#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

/*
 * simple program calling fork and wait
  The wait() function suspends execution of its calling process
   until stat_loc information is available for a terminated child process, or a signal is received. 

    On return from a
     successful wait() call, the stat_loc area contains termination information about the process that exited as defined below.
 */
int main(int argc, char **argv)
{
	pid_t child_id;
	pid_t my_id;
	int child_status;
	int i;

	child_id = fork();
	if(child_id != 0) {
		my_id = getpid();
		printf("pid: %d -- I just forked a child with id %d\n",
			(int)my_id,
			(int)child_id);
		printf("pid: %d -- I am waiting for process %d to finish\n",
			(int)my_id,
			(int)child_id);
		wait(&child_status);//chlid status is the output of wait
		printf("pid: %d -- my child has completed with status: %d\n",
			(int)my_id,
			child_status);
	} else {
		my_id = getpid();
		printf("pid: %d -- I am the child and I am going to count to 10\n",
			(int)my_id);
		for(i=0; i < 10; i++) {
			printf("pid: %d -- %d\n",my_id,i+1);
		}
	}

	printf("pid: %d -- I am exiting\n",my_id);
	exit(0);//this 0 will returned by wait

}


