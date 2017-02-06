# Reflection 1

## Sprint reflection

My personal goals were to learn C (over the course of the project) and to be able to reasonably contribute to the project. I haven't learned C in its entirety, but I am definitely more comfortable (and can more effectively understand the Google results). I also feel like I have not been contributing as much as I would like to the project, but for much of this sprint the project was in a place where it was often unclear how to contribute.

As a team, we tended to check in at the beginning and end of every meeting (both outside of and in class). We prepared for the sprint review by creating a project proposal and effectively having done all of our readings throughout the course of the sprint, although we did our sprint review with no code written. We realized during the sprint that we really needed to write some code and therefore to have more outside of class meetings, which is our kaizen to implement in sprint 2.

## Exercises and reading questions

#### HFC exercises

Completed exercises can be found here:

[ex01](../exercises/ex01)

[ex02](../exercises/ex02)

[ex02.5](../exercises/ex02.5)

#### Reading questions

Reading questions were completed inline on [this document](../reading_questions/thinkos.md).

## Exam question

Taken from reading ThinkOS 9. More relevant to the final exam than to the midterm for most of us.

Q: Describe synchronization errors in threading: why they happen, and how mutexes can help.

A: Synchronization errors occur because multiple threads will access the same variable at the same time. For example, if threads are iterating a variable, multiple threads will read the same value, iterate it, and write the same new value, thus creating unpredictable results. Mutexes prevent this: when a thread is iterating the variable, it uses a mutex function to lock the variable, reads the value, iterates the value, writes the new value, and unlocks the variable, now leaving it open for other threads to access. (This is applicable to purposes of threading other than iterating a single variable.)
