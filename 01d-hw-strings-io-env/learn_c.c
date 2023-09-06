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
	// part1();
	part2();
	// part3();
	// part4();
	// part5(argv[1]);
	// part6();
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

	printf("===== Question 19 =====\n");
}

void part4() {
	char s1[] = { 'a', 'b', 'c', '\0', 'd', 'e', 'f', '\0' };
	char s2[] = { 'a', 'b', 'c', '\0', 'x', 'y', 'z', '\0' };

	printf("===== Question 20 =====\n");

	printf("===== Question 21 =====\n");

	printf("===== Question 22 =====\n");
	char s3[16];
	char s4[16];

	printf("===== Question 23 =====\n");

	printf("===== Question 24 =====\n");
	int myval = 42;

	printf("===== Question 25 =====\n");
	char *s5;
	char *s6 = NULL;
	char *s7 = s4;

}

void part5(char *filename) {
	printf("===== Question 26 =====\n");

	printf("===== Question 27 =====\n");

	char buf[BUFSIZE];

	printf("===== Question 28 =====\n");

	fprintf(stderr, "===== Question 29 =====\n");

	printf("===== Question 30 (no code changes) =====\n");

	printf("===== Question 31 =====\n");
	int fd1, fd2;

	printf("===== Question 32 =====\n");
	size_t nread = 0;
	size_t totread = 0;

	printf("===== Question 33 (no code changes) =====\n");

	printf("===== Question 34 (no code changes) =====\n");

	printf("===== Question 35 =====\n");

	printf("===== Question 36 (no code changes) =====\n");

	printf("===== Question 37 (no code changes) =====\n");

	printf("===== Question 38 =====\n");

	printf("===== Question 39 (no code changes) =====\n");

	printf("===== Question 40 (no code changes) =====\n");

	printf("===== Question 41 (no code changes) =====\n");

	printf("===== Question 42 =====\n");

	printf("===== Question 43 =====\n");

	printf("===== Question 44 =====\n");

	printf("===== Question 45 =====\n");
	int ret = 0;

	printf("===== Question 46 =====\n");

	printf("===== Question 47 =====\n");

	printf("===== Question 48 =====\n");

}

void part6() {
	printf("===== Question 49 =====\n");
	char *s1;

	printf("===== Question 50 (no code changes) =====\n");
}
