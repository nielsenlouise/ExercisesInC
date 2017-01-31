## Chapter 1


### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Dynamic types are pretty common in interpreted languages.

2) Name two advantages of static typing over dynamic typing.

You know exactly what type the variable you declare is and it saves space to do so at compile time.

3) Give an example of a static semantic error.

Declaring `int x = "hello"` would probably make a static semantic error.

4) What are two reasons you might want to turn off code optimization?

Optimization might make some bugs you didn't see otherwise appear and using optimization increases compile time.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

The `-S` flag generates assembly code that is typically configured for the machine you're running on.

6) If you spell a variable name wrong, or if you spell a function name wrong,
the error messages you get might look very different.  Why?

One is a syntax error and one is trying to use functions that don't exist.

7) What is a segmentation fault?

The result of trying to write or read from incorrect locations in memory during runtime.


## Chapter 2


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

[]

2) What is the difference between a program and a process?

A process represents a running program. It's a data structure to keep track of the program.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?

It creates the illusion that every process is running continuously on its own space on the hard drive. This doesn't happen and process abstraction makes sure that all the processes don't mess each other up.

4) What is the kernel?

The kernel is makes core capabilities of the operating system like making threads.

5) What is a daemon?

Daemons are helpful, friendly processes that run in the background and help the operating system services.


## Chapter 3


### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

6 bits (up to 64 values, but 5 bits is only 32, which is too few).

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

2^32 (4294967296) characters.

3) What is the difference between "memory" and "storage" as defined in Think OS?

Memory is main memory, usually some kind of RAM, and holds data while a process is running. This is usually volatile and is lost when the computer shuts down. Memory is measured in binary units of bytes.

Storage is usually stored on a HDD or a SSD. These are non-volatile, so it is long-term storage. Storage is measured in decimal units of bytes.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

A gibibyte (GiB) is 2^30 bytes. A gigabyte (GB) is 10^9 bytes. Difference between the decimal and binary equivalent value is 6.87%.

5) How does the virtual memory system help isolate processes from each other?

A process cannot access data from another process because the per-process thing that assigns physical addresses will never assign a virtual address that maps to memory allocated to a different process.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

Things are allocated to both the stack and the heap during runtime, so it allows them to grow toward each other and use the amount of space they each need while also still probably keeping the addresses for things in the stack and the heap far away from each other. Maybe, I'm really not sure.

7) What Python data structure would you use to represent a sparse array?

Probably a dictionary, but I'm not totally sure what a sparse array is.

8) What is a context switch?

Context switch is when the operating system interrupts a running process, saves its state, and runs another process.

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.

 | Allen's Computer | My Computer
--- | --- | ---
Address of main is | 0x40057c | 0x4005d6
Address of global is | 0x60104c | 0x60104c
Address of local is | 0x7fffd26139c4 | 0x7fff0700aa1c
Address of p is | 0x1c3b010 | 0x1d5b010

1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).  

When I instantiate another variable with `malloc`, it's address is 0x1fb30a0, which is higher than what it was before.

2) Add a function that prints the address of a local variable, and check whether the stack grows down.  

Yup

3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.


## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically true about files systems but not true of their implementations.

It maps from file names to streams of bytes but is built on top of storage devices that are actually organized in blocks.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

The file position, whether the file is reading or writing, and the address/name/whatever pointer(s) to the file. Probably. I don't actually know.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Block transfers (ask about this), prefetching (begin loading blocks before they are requested), buffering (only writing to disk once if block is modified several times in memory), and caching (keeping a copy in memory).

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the file you wrote is not there.  What happened?

The file was probably in a cache and not saved to disk yet and so was lost when the computer shut down.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

FATs do not require you to know the file size at the beginning and creates more space as you need it, but it is slow because you need to iterate through each one, like in a linked list.

6) What is overhead?  What is fragmentation?

Overhead is the amount of space used by a data structure in order to store data. Fragmentation is the unused space in blocks (either full or partially unused blocks).

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

A lot of things use the file abstraction (the stream of bytes abstraction), like the UNIX pipe and network communication, so it's easier to understand for programmers and makes programs capable of working with data coming from other places. Not totally sure why it's a bad idea, but maybe something along the lines of why dynamic typing can be bad: it won't error at you when you're doing something horribly wrong/with something you really shouldn't be touching like that.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert
it to a 16-bit number and accidentally apply sign extension?

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator.
Try it out and confirm that the result is interpreted as -12.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.



## Chapter 6


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

b) Writing to unallocated memory.

c) Reading from a freed chunk.

d) Writing to a freed chunk.

e) Failing to free a chunk that is no longer needed.


3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical
memory a process has.  Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

If you want to know more about how malloc works, read
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

2) What is the fundamental problem caches are meant to solve?

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

4) The book gives several examples of programming language features, like loops, that tend
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with
different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?


## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

3) What is the difference between an interrupt and a context switch?

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

5) Why might a scheduler want to give higher priority to an I/O bound process?

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)



## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

So threads can call functions without interfering with each other.

2) What does the `gcc flag -lpthread` do?

Compiles with the Pthread library in gcc.

3) What does the argument of `pthread_exit` do?

It can be used to pass a value to the thread that joins with another thread.

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

I don't know what happens in general, but in this code, the thread just has to wait until it's its turn.

5) What goes wrong if several threads try to increment a shared integer at the same time?

Several threads can read the same value before any of them increment it, so it doesn't really increment correctly (synchronization error).

6) What does it mean to "lock a mutex"?

You lock something while one thread is looking at it and then, once that thread is done, unlock it so the next thread can access it. Locking/unlocking/mutexes prevent synchronization errors.



## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

6) What happens if you signal a condition variable when there are no waiting threads?

7) Do you have to lock the mutex to signal a condition variable?

8) Does the condition have to be true when you signal a condition variable?



## Chapter 11


### Semaphores in C
