#include <stdio.h>

int i, aantalWeerstanden, weerstandWaarde;
float vervangingsWeerstand;

int main(void) {
	while (1 == 1) {
		vervangingsWeerstand = 0;
		printf_s("Geef aantal weerstanden op: ");
		scanf_s("%d", &aantalWeerstanden);

		if (aantalWeerstanden >= 2) {

			for (i = 1; i <= aantalWeerstanden; i++) {

				printf("Geef de waarde van weerstand %d aan: ", i);
				scanf_s("%d", &weerstandWaarde);
				vervangingsWeerstand = vervangingsWeerstand + (1 / (float)weerstandWaarde);

			}

			printf("Vervangingsweerstand = %f\n\n\n", (1 / vervangingsWeerstand));
		}

		else {
			printf_s("\nIncorrecte invoer. Minimaal 2 weerstanden nodig\n\n");
		}
	}
}