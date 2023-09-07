#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>

#define BUFSIZE 30

void memprint(char *, char *, int);

void intro();
void part1();
void part2();
void part3();
void part4();
void part5(char *);
void part6();

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "usage: %s <filename>\n", argv[0]);
		exit(1);
	}
	intro();
	part1();
	part2();
	part3();
	part4();
	part5(argv[1]);
	part6();
}

void memprint(char *s, char *fmt, int len) {
	// iterate through each byte/character of s, and print each out
	int i;
	char fmt_with_space[8];

	sprintf(fmt_with_space, "%s ", fmt);
	for (i = 0; i < len; i++) {
		printf(fmt_with_space, s[i]);
	}
	printf("\n");
}

void intro() {
	printf("===== Intro =====\n");

	// Note: STDOUT_FILENO is defined in /usr/include/unistd.h:
	// #define	STDOUT_FILENO	1

	char s1[] = { 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x0a };
	write(STDOUT_FILENO, s1, 6);

	char s2[] = { 0xe5, 0x8f, 0xb0, 0xe7, 0x81, 0xa3, 0x0a };
	write(STDOUT_FILENO, s2, 7);

	char s3[] = { 0xf0, 0x9f, 0x98, 0x82, 0x0a };
	write(STDOUT_FILENO, s3, 5);
}

void part1() {

	printf("===== Question 1 =====\n");
	char s1[] = "hello";
	int s1_len;
	s1_len = sizeof(s1);
	printf("SIZE OF S1: %d\n", s1_len);
	// The number of bytes allocated for s1 is one larger than
	// the number of visible characters due to the null operator
	// that is added to the end.

	printf("===== Question 2 =====\n");

	memprint(s1, "0x%02x", s1_len);
	memprint(s1, "%d", s1_len);
	memprint(s1, "%c", s1_len);
	// Integer value of the extra byte is 0.

	printf("===== Question 3 (no code changes) =====\n");

	// #

	printf("===== Question 4 (no code changes) =====\n");

	// 7a

	printf("===== Question 5 =====\n");
	char s2[10];
	int s2_len;
	s2_len = sizeof(s2);

	printf("SIZE OF S2: %d\n", s2_len);

	// The number of bytes allocated is the same as the number of
	// bytes allocated for s2 because s2 is defined using a char array,
	// not a string.

	printf("===== Question 6 =====\n");
	char *s3 = s1;
	int s3_len;
	s3_len = sizeof(s3);
	printf("SIZE OF S3: %d\n", s3_len);

	// s3 is a variable that holds an address, not an array of bytes. Therefore, when we print
	// its size, we don't see how large the array of bytes is that it points to,
	// but the size (amount of bytes) of the value (in this case a 64 bit integer)
	// that it contains.

	printf("===== Question 7 =====\n");
	char *s4 = malloc(1024 * sizeof(char));
	int s4_len;

	s4_len = sizeof(s4);
	free(s4);

	printf("SIZE OF S4: %d\n", s4_len);

	// same as above

	printf("===== Question 8 (no code changes) =====\n");

	// 1,024 bytes allocated and not freed

	printf("===== Question 9 =====\n");

	// 0 in use at exit

}

void part2() {
	char s1[] = "hello";
	char s2[1024];
	char *s3 = s1;

	// Copy sizeof(s1) bytes of s1 to s2.
	memcpy(s2, s1, sizeof(s1));

	printf("===== Question 10 =====\n");

	printf("ADDRESS OF S1: %lu\n", (long unsigned int)&s1);
	printf("ADRRESS OF S2: %lu\n", (long unsigned int)&s2);
	printf("ADRRESS OF S3: %lu\n", (long unsigned int)&s3);

	// None of them since they are each different variables

	printf("===== Question 11 =====\n");

	printf("VALUE IN S1: %lu\n", (long unsigned int)s1);
	printf("VALUE IN S2: %lu\n", (long unsigned int)s2);
	printf("VALUE IN S3: %lu\n", (long unsigned int)s3);

	printf("===== Question 12 (no code changes) =====\n");

	// For char[] the address of the variable is also the address referred to by the variable.
	// This means there is no changing the referred-to address of a variable declared char[]

	// variable s3 refers to the same content as s1. This is because s3 was declared a pointer that
	// holds the same address as the address stored in s1.

	printf("===== Question 13 =====\n");

	printf("CONTENT OF S1: %s\n", s1);
	printf("CONTENT OF S2: %s\n", s2);
	printf("CONTENT OF S3: %s\n", s3);

	// They each have the same content. s1 contains the address at which the string "hello" resides.
	// The contents of s1's pointer value are then copied to the address stored in s2. s1's pointer value is
	// then placed as s3's pointer value. Therefore they all contain the same contents.


	printf("===== Question 14 =====\n");

	printf("%s\n", &s1[0] == &s2[0] ? "S1 == S2" : "S1 != S2");
	printf("%s\n", &s1[0] == &s3[0] ? "S1 == S3" : "S1 != S3");
	printf("%s\n", &s2[0] == &s3[0] ? "S2 == S3" : "S2 != S3");

	// s1 and s3 reffer to the same memory locations since the value stored in s1 was 
	// later placed in s3.

	printf("===== Question 15 =====\n");

	printf("%s\n", strcmp(s1, s2) == 0 ? "S1 == S2" : "S1 != S2");
	printf("%s\n", strcmp(s1, s3) == 0 ? "S1 == S3" : "S1 != S3");
	printf("%s\n", strcmp(s2, s3) == 0 ? "S2 == S3" : "S2 != S3");

	// they all equal each other

	printf("===== Question 16 =====\n");
	s1[1] = 'u';

	printf("CONTENT OF S1: %s\n", s1);
	printf("CONTENT OF S2: %s\n", s2);
	printf("CONTENT OF S3: %s\n", s3);

	// Both s1 and s3 are different. This is because s1 and s3 contain the same pointer values
	// and can alter the same things in memory.

	printf("===== Question 17 =====\n");

	printf("%s\n", &s1[0] == &s2[0] ? "S1 == S2" : "S1 != S2");
	printf("%s\n", &s1[0] == &s3[0] ? "S1 == S3" : "S1 != S3");
	printf("%s\n", &s2[0] == &s3[0] ? "S2 == S3" : "S2 != S3");

	// No, none of the pointer values have changed since question 14 since none of the pointers have
	// changed the addresses they refer to.
	
	printf("===== Question 18 =====\n");

	printf("%s\n", strcmp(s1, s2) == 0 ? "S1 == S2" : "S1 != S2");
	printf("%s\n", strcmp(s1, s3) == 0 ? "S1 == S3" : "S1 != S3");
	printf("%s\n", strcmp(s2, s3) == 0 ? "S2 == S3" : "S2 != S3");


	// Yes, because now only s1 and s3 have the same values because when s1's array was altered, so 
	// was s3's since the reference the same address.
}

void part3() {
	char s1[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	char s2[] = { 97, 98, 99, 100, 101, 102 };
	char s3[] = { 0x61, 0x62, 0x63, 0x64, 0x65, 0x66 };

	size_t s1_size = sizeof(s1);

	printf("%s\n", memcmp(s1, s2, s1_size) == 0 ? "s1 == s2" : "s1 != s2");
	printf("%s\n", memcmp(s2, s3, s1_size) == 0 ? "s2 == s3" : "s2 != s3");
	printf("%s\n", memcmp(s1, s3, s1_size) == 0 ? "s1 == s3" : "s1 != s3");

	printf("===== Question 19 =====\n");

	// They are all the same. Each char array contains values that can be represented as characters.
	// when we print each char array as a string, we get the same result since each char array is the
	// same, just represented by different characters.
}

void part4() {
	char s1[] = { 'a', 'b', 'c', '\0', 'd', 'e', 'f', '\0' };
	char s2[] = { 'a', 'b', 'c', '\0', 'x', 'y', 'z', '\0' };

	printf("===== Question 20 =====\n");
	size_t s1_size = sizeof(s1);
	printf("%s\n", memcmp(s1, s2, s1_size) == 0 ? "s1 == s2" : "s1 != s2");

	// They are not equal since they have some different values.

	printf("===== Question 21 =====\n");
	printf("%s\n", strcmp(s1, s2) == 0 ? "s1 == s2" : "s1 != s2");

	// They are evaluated using strcmp as thesame since by definition a string is a null-terminated
	// char array. This means that the strings will only be compared to the first null character.
	// In this case, they are both the same up to the first null character.

	printf("===== Question 22 =====\n");
	char s3[16];
	char s4[16];

	memset(s3, 'z', sizeof(s3));
	memprint(s3, "%02x", sizeof(s3));

	memset(s4, 'z', sizeof(s4));
	memprint(s4, "%02x", sizeof(s4));

	// no

	printf("===== Question 23 =====\n");

	strcpy(s3, s1);
	memprint(s3, "%02x", sizeof(s3));

	// Only the first 4 bytes (which includes the null character) since strcpy only recognizes the values
	// in s1 up to and including the first null character.

	printf("===== Question 24 =====\n");
	int myval = 42;

	sprintf(s4, "%s %d\n", s1, myval);
	memprint(s4, "%02x", sizeof(s4));

	// the null value was placed at the very end of the formated string after it was processed.

	printf("===== Question 25 =====\n");
	char *s5;
	char *s6 = NULL;
	char *s7 = s4;

	memprint(s5, "%02x", 8);
	// memprint(s6, "%02x", 8);
	memprint(s7, "%02x", 8);
	
	// They can all be printed except for s6

}

void part5(char *filename) {
	printf("===== Question 26 =====\n");

	printf("stdin: %d\n", fileno(stdin));
	printf("stdout: %d\n", fileno(stdout));
	printf("stderr: %d\n", fileno(stderr));

	// stdin = 0 stdout = 1 stderr = 2

	printf("===== Question 27 =====\n");

	char buf[BUFSIZE];

	memset(buf, 'z', BUFSIZE);
	memset(buf + 24, 0, 1);
	memprint(buf, "%02x", BUFSIZE);

	// No

	printf("===== Question 28 =====\n");

	printf("%s\n", buf);
	write(fileno(stdout), buf, BUFSIZE);
	printf("\n");

	// printtf prints up to but nott including the null byte. write prints all values except for null value.

	fprintf(stderr, "===== Question 29 =====\n");

	fprintf(stderr, "%s\n", buf);
	write(fileno(stderr), buf, BUFSIZE);
	fprintf(stderr, "\n");

	// You only see what is printed to stderr, not what is printed to stdout.

	printf("===== Question 30 (no code changes) =====\n");

	// 2> prints everything but the stderr

	printf("===== Question 31 =====\n");
	int fd1, fd2;
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	char path[strlen(cwd) + sizeof(filename) + 1];

	sprintf(path, "%s/%s", getenv("PWD"), filename);

	fd1 = open(path, O_RDONLY);

	fd2 = fd1;	

	printf("fd1: %d\n", fd1);
	
	// fd1 is the next number after stdin, stdout and stderr file descriptors

	printf("===== Question 32 =====\n");
	size_t nread = 0;
	size_t totread = 0;
	nread = read(fd1, buf, 4);
	totread += nread;
	printf("nread: %lu\n", nread);
	printf("totread: %lu\n", totread);

	memprint(buf, "%02x", BUFSIZE);

	// Yes, they matched because read() returns the number of bytes read and I 
	// passed in 4 as the amount of bytes that I wanted to be read.
	
	printf("===== Question 33 (no code changes) =====\n");

	// No, no null characher was inluded because there is no null terminating character
	// in the file according to hexdump

	printf("===== Question 34 (no code changes) =====\n");

	nread = read(fd2, &buf[totread], 4);
	totread += nread;

	printf("nread: %lu\n", nread);
	printf("totread: %lu\n", totread);

	memprint(buf, "%02x", BUFSIZE);

	// No, the file was read from where it left off after the first call. This is because
	// the file position is advanced by the number of bytes that are read from the file each time.

	printf("===== Question 35 =====\n");

	// Only the value of the file descriptor matters since it is the value that represents the 
	// open file.

	printf("===== Question 36 (no code changes) =====\n");

	// 8

	printf("===== Question 37 (no code changes) =====\n");

	nread = read(fd1, &buf[totread], BUFSIZE - totread);
	totread += nread;

	printf("nread: %lu\n", nread);
	printf("totread: %lu\n", totread);

	memprint(buf, "%02x", BUFSIZE);

	// The return value from read does not match the count value passed in because
	// there were fewer bytes in the file than the number passed in.

	printf("===== Question 38 =====\n");

	// 22

	printf("===== Question 39 (no code changes) =====\n");

	// 22

	printf("===== Question 40 (no code changes) =====\n");

	// The number of bytes read would have been the same as BUFSIZE

	printf("===== Question 41 (no code changes) =====\n");

	nread = read(fd1, &buf[totread], BUFSIZE - totread);
	totread += nread;

	printf("nread: %lu\n", nread);
	printf("totread: %lu\n", totread);

	memprint(buf, "%02x", BUFSIZE);

	// nread is 0 because read returns 0 when it is at end of file

	printf("===== Question 42 =====\n");

	printf("%s\n", buf);

	// There are to z's at the end because %s only terminates after it
	// sees a null value and the null valule came after after the two 
	// z's in buf.

	printf("===== Question 43 =====\n");

	memset(&buf[totread], 0, 1);

	printf("%s\n", buf);

	// The output now looks the exact same as the file because
	// by adding the null at the end of the file contents, we have
	// told the machine to stop reading beyond the null value. 

	printf("===== Question 44 =====\n");
	int ret = 0;

	ret = close(fd1);

	printf("%d\n", ret);

	// close returned 0 meaning successfully closed file.

	printf("===== Question 45 =====\n");

	ret = close(fd2);

	printf("%d\n", ret);
	
	// close returned -1 meaning unsuccessfully closed file. This happened
	// because the file is already closed and can't be closed again.

	printf("===== Question 46 =====\n");

	fprintf(stdout, "abc");
	fprintf(stderr, "def");
	fprintf(stdout, "ghi\n");

	write(fileno(stdout), "abc", 3);
	write(fileno(stderr), "def", 3);
	write(fileno(stdout), "ghi\n", 4);

	// Because stderr is unbuffered it is written first before abc. However,
	// the write function does not buffer and therefore sends everything
	// in the order displayed in the program.

	printf("===== Question 47 =====\n");

	fprintf(stdout, "abc");
	fflush(stdout);
	fprintf(stderr, "def");
	fprintf(stdout, "ghi\n");

	write(fileno(stdout), "abc", 3);
	write(fileno(stderr), "def", 3);
	write(fileno(stdout), "ghi\n", 4);

	// the output is now the exact same because we flushed stdout's buffer
	// before our print to stderr.


}

void part6() {
	printf("===== Question 49 =====\n");
	char *s1;

	s1 = getenv("CS324_VAR");

	if (s1 == NULL) {
		printf("CS323_VAR not found\n");
	} else {
		printf("CS324_VAR is %s\n", s1);
	}

	// in the first command we don't have an environment variable set, but
	// we do in the second line.

	printf("===== Question 50 (no code changes) =====\n");

	// the environment variable persists and doesn't have to be on the same
	// line as when you run the executable.
}
