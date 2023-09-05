/*#include <stdio.h>

 int main(void) {
	int a, b;
	printf("Geef het eerste getal: ");
	scanf("%d", &a);
	printf("Geef een tweede getal: ");
	scanf("%d", &b);
	

	printf("Het product van %d en %d is: %d\n", a, b, a * b);
	printf("\nSluit dit venster door op enter te drukken");
	getchar();
	return 0;
}*/
 /*int main(void) {
	 double x, y, wortel, macht;
	 int i;
	 printf("Voer een positief getal x in: ");
	 scanf("%lf", &x);
	 printf("Voer een getal y in: ");
	 scanf("%lf", &y);
	 for (i = 0; i < 5; i++){
		 wortel = sqrt(x);
		 macht = pow(x, y);
		 printf("De vierkantswortel uit %f is: %f\n", x, wortel);
		 printf("%f tot de macht %f is: %f\n", x, y, macht);
		 x++;
	 }
	 getchar();
	 return 0;
 }*/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>

int a, i, b;
int main(void) {

	while (1 == 1)
	{
		printf("Geef een getal: ");
		scanf_s("%d", &a);
		printf("Hoe vaak?: ");
		scanf_s("%d", &b);
		printf("\n");
		if(a * b < 10000){
			for (i = 1; i <= b; i++) {
				printf("%5d x %5d = %5d\n", a, i, a * i);

			}
		}
		else {
			printf("Te groot getal");
			printf("\n");
		}
		printf("\n");
	}
}