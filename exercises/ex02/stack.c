/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    // in local scope, instantiate the counter and the array length 5
    int i;
    int array[SIZE];

    // print the location of the array
    printf("%p\n", array);

    // write 42 as every entry in the array
    for (i=0; i<SIZE; i++) {
  array[i] = 42;
    }
    // return the location of the array
    return array;
}

void bar() {
    // in local scope, instantiate the counter and the array length 5
    int i;
    int array[SIZE];

    // print the location of the array
    printf("%p\n", array);

    // write 0, 1, 2, 3, 4 as entries in the array
    for (i=0; i<SIZE; i++) {
  array[i] = i;
    }
    // return nothing
}

int main()
{
    // instantiate a counter
    int i;
    // set a pointer to the location of the array returned by foo()
    // this doesn't work because the array is stack allocated
    int *array = foo();
    // run bar()
    bar();

    // print the array
    // this doesn't work because you can't access the array
    for (i=0; i<SIZE; i++) {
  printf("%d\n", array[i]);
    }

    return 0;
}
