# Pipex

> This project aims to deepen your understanding of the two concepts that you already know: Redirections and Pipes. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus.
> 

<aside>
💡 Before starting, feel free to check some of these sources as they helped me a lot get familiar with the theory and practice behind this project:

</aside>

[https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY](https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)

Also, check out this blog with a lot of great posts.

[Home - codequoi](https://www.codequoi.com/en/home-english/)

As always, when in doubt just check the manual - it’s a pain in the ass to read but it has a lot of useful information: `man`

<aside>
💡 Enjoy the project, and as always ************************************be as thorough as possible************************************ - don’t leave stones unturned!

</aside>

[Theory](Pipex%20cb2f8fa8623f43d6b24b445a156c76a9/Theory%205bcbc028009a4b6f8017f888c4aa0efc.md)

[Coding](Pipex%20cb2f8fa8623f43d6b24b445a156c76a9/Coding%20d37091112d3046819240906479e22081.md)

# Theory

[Functions](Theory%205bcbc028009a4b6f8017f888c4aa0efc/Functions%202d81552c7500443188b942e8ba4f5306.md)

[UNIX Processes](Theory%205bcbc028009a4b6f8017f888c4aa0efc/UNIX%20Processes%20362981cef0c04ac2b4a1b684efb291b5.md)

[Inter-Process Communication](Theory%205bcbc028009a4b6f8017f888c4aa0efc/Inter-Process%20Communication%2041b01c40a4164f278503cd5dbb97d34f.md)

# Functions

## perror

perror is a C library function `void perror(const char *str)` that takes a string as an argument and displays it followed by a colon and space, and then the descriptive error message to the stderror. 

## strerror

strerror is a C library function `char *strerror(int errnum)` searches and internal array for the error code **errnum** and returns a pointer to the string with the corresponding error message. The usual number used as errnum is *errno*.

## access

access, prototyped `int access(const char *pathname, int mode)` is a function that checks if the calling process can access the file passed in the *******pathnme******* for the accessibility checks specified by the ****mode****. The check is done using the calling process’s real UID and GID rather than the effective IDs as is done when attempting an operation on the file.

## dup

The dup system call creates a copy of the file descriptor passed as input using the lowest numbered available file descriptor as the new descriptor. `int dup(int oldfd)` generates a new file descriptor, but it can be used interchangeably with the old one, as they will refer to the same open file, and therefore share the file offset and file status flag. In practice this means that if we were using get next line on one of them, the offset  of the other file descriptor would also change.

## dup2

The dup2 system call functions similarly to dup, except the caller has the option to specify the new file descriptor. `int dup2(int oldf, int newfd)` automatically and silently closes the existing *****newfd***** if it’s in use, and reassigns it to the duplicated file descriptor.

## execve

execve is one of the functions belonging to the exec family. `int execve(char *pathname, char *const argv[], char *cont envp[])` executes the program referred to by ********pathname********. As a consequence, the program that is currently being run by the process is replaced by the new program passed as an argument with newly initialized stack and heap. The ****argv**** parameter is an array of argument strings passed to the new program, the first of which (argv[0]) is by convention the filename associated with the file being executed. ****envp**** is an array of strings which are passed as environment to the new program.

