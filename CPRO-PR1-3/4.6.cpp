//#include <stdio.h>
//
//
//int num;
//
//
//int collatzSteps(int n) {
//	int i;
//
//	for (i = 0; n > 1; i++) {
//
//		if (n % 2 == 0) n = n / 2;
//
//		else if (n % 2 != 0) n = 3 * n + 1;
//
//		printf("stap %d: n = %d\n", i + 1, n);
//
//	}
//
//	return i;
//
//}
//
//
//
//int main(void) {
//	int input;
//
//	do {
//		printf("Voer een geheel getal in groter dan 1: ");
//		scanf_s("%d", &input);
//		printf("\n");
//	} while (input < 2);
//
//	printf("\nAantal stappen voor %d is %d\n\n", input, collatzSteps(input));
//
//}

#include <stdio.h>
int a, b, c, d, e, num;

int max2(int a, int b) {
	if (a < b) {
		return b;
	}
	else if (a > b) {
		return a;
	}
}

int max5(int a, int b, int c, int d, int e) {
	max2(max2(max2(max2(a, b), c), d), e);
}

int leesGetal() {
	printf("geef een geheel getal op: ");
	return scanf_s("%d");
}


int main(void) {
	int var1 = leesGetal();



}