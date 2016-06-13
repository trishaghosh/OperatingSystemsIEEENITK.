// The Scheduling Algorithm used in the Xv6 Operatiing System is Round Robin Technique.

//It is a Preemptive Scheduling Algorithm.

/*This scheduling algo is implemented using Context Switch. The Xv6 Scheduler performs the Context Switch in two teps. The current processes Kernel Threads to the CPUs Scheduler thread. This scheduler thread selects the next process to be executed from the ready queue and switches the the selected process.

The CPUs Scheduler Thread is a Kernel Thread

Context switches in Xv6 are performed in two steps
*current process →scheduler (in sched function)
*scheduler →the next process (in schduler function)

Scheduler loops through the ptable to select the next process
** a round-robin scheduling algorithm
It calls swtch (Context Switch is implemented in swtch.s) to switch to the kernel thread of the next process
** kernel stack and the registers are saved and restored (swtch function does this)
** swtch returns when the running process calls sched to switch to
the scheduler
A process can call yield to voluntarily give up CPU
** a running process yields to other processes in the timer interrupt
handler for preemptive scheduling (trap.c)

Synchronisation is implemented using Locks 

The Scheduling Algorithm in functions sched and scheduler are written in the file PROC.H

*/

//Scheduler Algorithm 
void
scheduler(void)
{
  struct proc *p;

  for(;;){
    // Enable interrupts on this processor.
    sti();

    // Loop over process table looking for process to run.
    acquire(&ptable.lock);
    for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
      if(p->state != RUNNABLE)
        continue;

      // Switch to chosen process.  It is the process's job
      // to release ptable.lock and then reacquire it
      // before jumping back to us.
      proc = p;
      switchuvm(p);
      p->state = RUNNING;
      swtch(&cpu->scheduler, proc->context);
      switchkvm();

      // Process is done running for now.
      // It should have changed its p->state before coming back.
      proc = 0;
    }
    release(&ptable.lock);

  }
}

// Enter scheduler.  Must hold only ptable.lock
// and have changed proc->state.
void
sched(void)
{
  int intena;

  if(!holding(&ptable.lock))
    panic("sched ptable.lock");
  if(cpu->ncli != 1)
    panic("sched locks");
  if(proc->state == RUNNING)
    panic("sched running");
  if(readeflags()&FL_IF)
    panic("sched interruptible");
  intena = cpu->intena;
  swtch(&proc->context, cpu->scheduler);
  cpu->intena = intena;
}

// Give up the CPU for one scheduling round.
void
yield(void)
{
  acquire(&ptable.lock);  //DOC: yieldlock
  proc->state = RUNNABLE;
  sched();
  release(&ptable.lock);
}



