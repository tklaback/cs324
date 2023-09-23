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

		printf("Section B\n");
		close(pipefd[0]);
		char write_string[] = "hello from Section B\n";
		sleep(10);
		write(pipefd[1], write_string, sizeof(write_string));
		sleep(10);
		close(pipefd[1]);

		printf("Section B finished\n");

		exit(0);

		/* END SECTION B */
	} else {
		/* BEGIN SECTION C */

		printf("Section C\n");
		int BUF_SIZE = 1024;
		close(pipefd[1]);
		char buf[BUF_SIZE];
		int bytes_read = 0;
		int total = 0;
		while ((bytes_read = read(pipefd[0], buf, BUF_SIZE)) > 0){
			total += bytes_read;
		}
		printf("NUMBER OF BYTES READ FROM READ: %d\n", total);
		printf("RETURNED STRING: %s", buf);

		bytes_read = 0;
		total = 0;
		while ((bytes_read = read(pipefd[0], buf, BUF_SIZE)) > 0){
			total += bytes_read;
		}
		printf("NUMBER OF BYTES READ FROM READ: %d\n", total);
		printf("RETURNED STRING: %s", buf);

		printf("Section C finished\n");
		close(pipefd[0]);

		exit(0);

		/* END SECTION C */
	}
	/* BEGIN SECTION D */

	printf("Section D\n");
	sleep(30);

	/* END SECTION D */
}

