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
#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>

 int main(void) {
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
 }