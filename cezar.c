#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define defaultKey 3
#define unknownChar '_'

bool isLowercase(char x);
bool isUppercase(char x);
char En(char x);
char Dn(char x);

int main (int argc, char *argv[]) {

	switch (argc) {
		case 1:
			return 1;
		case 2:
			return 2;
	}

	int len = strlen(argv[2]);
	switch (argv[1][0]) {
		case 'e':
			for (int i = 0; i < len; i++) {
				printf("%c", En(argv[2][i]));
			}
			break;
		case 'd':
			for (int i = 0; i < len; i++) {
				printf("%c", Dn(argv[2][i]));
			}
			break;
		default:
			printf("Invalid option\n");
	}

	return 0;
}


bool isLowercase(char x) {
	return (x >= 'a' && x <= 'z')?true:false;
}

bool isUppercase(char x) {
	return (x >= 'A' && x <= 'Z')?true:false;
}

char En(char x) {
	char r = x + 3;

	if (isLowercase(x)) {
		if (r > 'z')
			r = r - 26;
	} else if (isUppercase(x)) {
		if (r > 'Z')
			r = r - 26;
	} else {
		r = unknownChar;
	}

	return r;
}

char Dn(char x) {
	char r =  x - 3;

	if (isLowercase(x)) {
		if (r < 'a')
			r = r + 26;
	} else if (isUppercase(x)) {
		if (r < 'A')
			r = r + 26; 
	} else {
		r = unknownChar;
	}

	return r;
}