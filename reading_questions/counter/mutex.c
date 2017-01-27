/* Example code for Software Systems at Olin College.
Copyright 2012 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0
*/

#include <stdlib.h>
#include <pthread.h>
#include "mutex.h"

// wrapper for pthread_mutex_t, defined in Pthread API
Mutex *make_mutex()
{
  // allocate space for a pthread_mutex_t type
  Mutex *mutex = (Mutex *) malloc(sizeof(Mutex));
  pthread_mutex_init(mutex->mutex, NULL);
  // return a pointer
  return mutex;
}

// locking and unlocking: simple wrappers for pthreads functions.
void mutex_lock(Mutex *mutex)
{
  pthread_mutex_lock(mutex->mutex);
}

void mutex_unlock(Mutex *mutex)
{
  pthread_mutex_unlock(mutex->mutex);
}
