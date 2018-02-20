#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

/*
 * simple program calling fork
 fork() causes creation of a new process.  The new process (child process) is an exact copy of the calling process (parent process) except for the following:

  o   The child process has a unique process ID.

  o   The child process has a different parent process ID (i.e., the process ID of the parent process).

  o   The child process has its own copy of the parent's descriptors.  These descriptors reference the same underlying objects, so that, for instance, file pointers in file
               objects are shared between the child and the parent, so that an lseek(2) on a descriptor in the child process can affect a subsequent read or write by the parent.  This
               descriptor copying is also used by the shell to establish standard input and output for newly created processes as well as to set up pipes.

  o   The child processes resource utilizations are set to 0; see setrlimit(2).
 */


/*
Return values: Upon successful completion, fork() returns a value of 0 to the child process and returns the process ID of the child process to the parent process.  Otherwise, a value of -1 is
     returned to the parent process, no child process is created, and the global variable errno is set to indicate the error.
*/
int main(int argc, char **argv)
{
	pid_t child_id;
	pid_t my_id;

	my_id = getpid();
	printf("pid: %d -- I am the parent about to call fork\n",
			(int)my_id);

	child_id = fork();
	if(child_id != 0) {
		my_id = getpid();
		printf("pid: %d -- I just forked a child with id %d\n",
			(int)my_id,
			(int)child_id);
	} else {
		my_id = getpid();
		printf("pid: %d -- I am the child\n",my_id);
	}

	printf("pid: %d -- I am exiting\n",my_id);
	exit(0);

}


