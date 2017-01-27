/* Example code for Think OS.
Copyright 2014 Allen Downey
License: GNU GPLv3
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_CHILDREN 5

void perror_exit(char *s)
{
  perror(s);
  exit(-1);
}

void *check_malloc(int size)
{
  void *p = malloc(size);
  if (p == NULL) {
      perror_exit("malloc failed");
  }
  return p;
}

// structure to contain values shared between threads
typedef struct {
  int counter;
} Shared;

// allocates space for a Shared structure
// initializes the contents
Shared *make_shared(int end)
{
  Shared *shared = check_malloc(sizeof(Shared));
  shared->counter = 0;
  return shared;
}

// wrapper for pthread_create
// this makes pthread_create easier to use
// also provides error checking
pthread_t make_thread(void *(*entry)(void *), Shared *shared)
{
  int ret;
  pthread_t thread;

  ret = pthread_create(&thread, NULL, entry, (void *) shared);
  // pthread_create returns 0 if successful
  // if not, here's an error message
  if (ret != 0) {
      perror_exit("pthread_create failed");
  }
  // returns the handle of a new thread
  return thread;
}

// wrapper for join_thread
// param = handle of thread you want to wait for
void join_thread(pthread_t thread)
{
  // call pthread_join
  int ret = pthread_join(thread, NULL);
  // check the result
  if (ret == -1) {
      perror_exit("pthread_join failed");
  }
}

void child_code(Shared *shared)
{
  // this prints the value of the counter and increments it.
  printf("counter = %d\n", shared->counter);
  shared->counter++;
}

// function where the execution of a new thread will begin
void *entry(void *arg)
{
  // param has to be a void pointer, but we know it's a pointer to
  // a Shared struct (in this code) so we can typecast it like so.
  Shared *shared = (Shared *) arg;
  // this does the real work.
  child_code(shared);
  // this can pass a value to the thread that joins with this thread.
  // child_code doesn't have anything to say, so we'll pass NULL.
  pthread_exit(NULL);
}

int main()
{
  int i;
  // NUM_CHILDREN is a compile-time constant that determines the
  // number of child threads.
  // child is an array of thread handles.
  pthread_t child[NUM_CHILDREN];

  Shared *shared = make_shared(1000000);

  for (i=0; i<NUM_CHILDREN; i++) {
    child[i] = make_thread(entry, shared);
  }

  // waits for the children one at a time in order of creation
  // the loop still works if they don't finish in order
  for (i=0; i<NUM_CHILDREN; i++) {
    join_thread(child[i]);
  }

  return 0;
}
