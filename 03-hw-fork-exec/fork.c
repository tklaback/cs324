#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
// #include <sys/wait.h>

int main(int argc, char *argv[]) {
	int pid;

	printf("Starting program; process has pid %d\n", getpid());

	FILE *f = fopen("fork-output.txt", "w");

	fprintf(f, "BEFORE FORK (%d)\n", fileno(f));
	fflush(f);

	int pipefd[2];

	if (pipe(pipefd) == -1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	if ((pid = fork()) < 0) {
		fprintf(stderr, "Could not fork()");
		exit(1);
	}

	/* BEGIN SECTION A */

	printf("Section A;  pid %d\n", getpid());
	sleep(5);

	/* END SECTION A */
	if (pid == 0) {
		/* BEGIN SECTION B */

		char *newenviron[] = { NULL };

		printf("Program \"%s\" has pid %d. Sleeping.\n", argv[0], getpid());

		if (argc <= 1) {
			printf("No program to exec.  Exiting...\n");
			exit(0);
		}

		printf("Running exec of \"%s\"\n", argv[1]);
		execve(argv[1], &argv[1], newenviron);
		printf("End of program \"%s\".\n", argv[0]);
		exit(0);

		/* END SECTION B */
	} else {
		/* BEGIN SECTION C */
		sleep(5);
		exit(0);

		/* END SECTION C */
	}
	/* BEGIN SECTION D */

	printf("Section D\n");
	sleep(30);

	/* END SECTION D */
}

