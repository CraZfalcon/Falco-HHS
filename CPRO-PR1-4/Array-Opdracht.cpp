//5.7 Palindroom

#include <stdio.h>
#pragma warning(disable : 4996)

char input[6];

int is_palindroom(char[5]) {

	if (input[0] == input[4] && input[1] == input[3]) return 1;
	else return 0;
}

int main(void) {
	while (getchar() != '\n'); {
		printf("Geef een woord van 5 letters: ");
		scanf("%s", &input);
		if (is_palindroom(input) == 1) printf("Het woord is een palindroom");
		else printf("Het woord is geen palindroom");
	}
}

//5.10 Sinus tabel

//#include <stdio.h>
//#include <math.h>
//
//#define sinusWaarde 90
//
//float sinus[sinusWaarde+1];
//int input;
//
//int main(void) {
//
//	for (int i = 0; i <= sinusWaarde; i++) {
//		sinus[i] = sin(i * 2 * 3.14 / 360);
//		printf("sin(%2d) = %f\n", i, sinus[i]);
//	}
//
//	do {
//
//		printf("\n\n\n\n\n");
//		printf("Geef een sinus conversie getal: ");
//		scanf_s("%d", &input);
//		printf("%lf", sinus[input]);
//	} while (input != 0);
//}

//5.14 Doorsnede

//#include <stdio.h>
//#pragma warning(disable : 4996)
//
//int rij1[] = { 23, 3, 56, 6, 5 };
//int rij2[] = { 12, 6, 3, 18, 7, 10, 56, 11 };
//int aantal_doorsnede = doorsnede(rij1, sizeof rij1 / sizeof rij1[0], rij2,
//sizeof rij2 / sizeof rij2[0]);
//int i;
//for (int i = 0; i < aantal_doorsnede; i = i + 1) {
//	printf("%d ", rij1[i]);
//}