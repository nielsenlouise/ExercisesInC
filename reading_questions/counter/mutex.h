/* Example code for Think OS
Copyright 2015 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0
*/

#include <pthread.h>

// pthread_mutex_t behaves like a struct, so if you pass it as an argument,
// it makes a copy, which messes up the mutex.
// to avoid: pass pthread_mutex_t by address.
typedef struct {
  pthread_mutex_t mutex[1];
} Mutex;

Mutex *make_mutex ();
void mutex_lock(Mutex *mutex);
void mutex_unlock(Mutex *mutex);
