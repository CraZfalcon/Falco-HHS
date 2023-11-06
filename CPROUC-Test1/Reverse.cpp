#include <stdio.h>
#include <string.h>

char raw[] = "Hello World!";

int strlen(char* str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}


int main(void) {

	int index;
	for (index = 0; raw[index] != '\0'; index++);
	for (int i = 0; i < index - 1; i++) printf("%c", raw[index - i]);

	//for (int i = 0; i < strlen(raw); i++) printf("%c", raw[strlen(raw) - i - 1]);

	/*
	
		int len = strlen(raw);

		for (int i = 0; i < len; i++) {
			printf("%c", raw[len - i - 1]);
		}
	
	*/

}