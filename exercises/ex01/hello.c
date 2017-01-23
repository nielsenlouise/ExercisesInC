/* Example code for Think OS.
Copyright 2014 Allen Downey
License: GNU GPLv3
*/

#include <stdio.h>
int main()
{
    int x = 5;
    int y = x + 1;
    printf("%d", y);
    return 0;
}

/*
  Adding int x = 5 adds these lines to hello.s:
    subq	$16, %rsp
    movl	$5, -4(%rbp)
  Using optimization flag -02:
    The lines that deal with int x = 5 no longer exist because they're not used.
  printf printing x:
    The lines that deal with int x = 5 are present both with and without
    optimization.
  with int y = x+1:
    without optimization: you can see both x and y happening
    with optimization: it calculates y as 6 during compilation, so you can't see
    x at all.
*/
