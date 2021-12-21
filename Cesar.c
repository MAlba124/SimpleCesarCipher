#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int encrypt(const char *str) {
	
	char cipher[4056];
	int asciiCode;
	if(strlen(str) > 0) {
		for(int i = 0; i <= strlen(str); i++) {
			asciiCode = str[i] + 4;
			cipher[i] = (char) asciiCode;
		}
		cipher[strlen(cipher)+1] += '\0';
		printf("%s\n", cipher);
		return 0;
	} else {
		printf("Failed to encrypt or string is empty\n");
		return -1;
	}
}

int decrypt(const char *cipher) {
	
	char str[4056];
	int asciiCode;
	if(strlen(cipher) > 0) {
		for(int i = 0; i <= strlen(cipher); i++) {
			asciiCode = cipher[i] - 4;
			str[i] = (char) asciiCode;
		}
		str[strlen(str)+1] += '\0';
		printf("%s\n", str);
		return 0;
	} else {
		printf("Failed to decrypt or string is empty\n");
		return -1;
	}	
}

int main(int argc, char const *argv[]) {

	if(argc > 2) {
		if(strcmp(argv[1], "-e") == 0 || strcmp(argv[1], "-encrypt") == 0) {
			printf("Encrypted string: ");
			encrypt(argv[2]);
		} else if(strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "-decrypt") == 0) {
			printf("Decrypted string: ");
			decrypt(argv[2]);
		} else {
			printf("No argument named: %s\n", argv[2]);
		}
	} else {
		printf("String argument is null\n");
	}
	return 0;
}
