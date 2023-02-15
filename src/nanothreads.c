/* Copyright 2022-Present Light Transport Entertainmemt Inc. MIT license */

#include <stdint.h>

#include "nanothreads.h"

#define THREAD_IMPLEMENTATION
#include "libs_thread.h"

/* C11 thread implementation */

int thrd_create(thrd_t *thr, thrd_start_t func, void *arg)
{
  // TODO: Set unique thread name.
  thread_ptr_t thread = thread_create( func, arg, "A thread", THREAD_STACK_SIZE_DEFAULT );

  if (thread == NULL) {
    return thrd_error;
  }

  (*thr) = thread;

  return thrd_success;
}
