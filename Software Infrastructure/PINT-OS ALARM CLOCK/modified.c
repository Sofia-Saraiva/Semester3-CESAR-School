// THREAD.H
struct thread
  {
    /* Owned by thread.c. */
    tid_t tid;                          /* Thread identifier. */
    enum thread_status status;          /* Thread state. */
    char name[16];                      /* Name (for debugging purposes). */
    uint8_t *stack;                     /* Saved stack pointer. */
    int priority;                       /* Priority. */
    struct list_elem allelem;           /* List element for all threads list. */
    int64_t tick_wakeup; // sofia

    /* Shared between thread.c and synch.c. */
    struct list_elem elem;              /* List element. */

#ifdef USERPROG
    /* Owned by userprog/process.c. */
    uint32_t *pagedir;                  /* Page directory. */
#endif

    /* Owned by thread.c. */
    unsigned magic;                     /* Detects stack overflow. */
  };


// THREAD.C 
extern struct list sleep_list; // declare sleep list

void
thread_init (void) 
{
  ASSERT (intr_get_level () == INTR_OFF);

  lock_init (&tid_lock);
  list_init (&ready_list);
  list_init (&all_list);
  list_init(&sleep_list); // initialize sleep list

  /* Set up a thread structure for the running thread. */
  initial_thread = running_thread ();
  init_thread (initial_thread, "main", PRI_DEFAULT);
  initial_thread->status = THREAD_RUNNING;
  initial_thread->tid = allocate_tid ();
}


void thread_sleep(int64_t ticks) {
  struct thread *cur = thread_current ();
  enum intr_level old_level;

  if (cur != idle_thread) {
      old_level = intr_disable (); // disable interrupt
      list_push_back(&sleep_list, &cur->elem); // add thread to sleep list
      cur->tick_wakeup = ticks; // tick_wakeup == start + ticks
      cur->status = THREAD_BLOCKED; // blocks thread
      schedule(); // context switch
      intr_set_level (old_level); // enable interrupt
  }
  
}


// TIMER.C
struct list sleep_list;

void
timer_sleep (int64_t ticks) 
{
  int64_t start = timer_ticks ();

  ASSERT (intr_get_level () == INTR_ON);
  //while (timer_elapsed (start) < ticks) 
    //thread_yield ();

  if (timer_elapsed (start) < ticks)  { // sofia
    thread_sleep(start + ticks);
  }
}


static void
timer_interrupt (struct intr_frame *args UNUSED)
{
  ticks++;
  thread_tick ();

  struct list_elem *aux = list_begin(&sleep_list); // sofia
  while (aux != list_end(&sleep_list)) {
    struct thread *t = list_entry(aux, struct thread, elem);

    if (t->tick_wakeup <= ticks) {
      aux = list_remove(aux);
      thread_unblock(t);
    }
    else {
      aux = list_next(aux);
    }
  }
}
