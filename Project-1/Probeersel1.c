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
/*#include <stdio.h>
#include <math.h>

float a;
int i, b;

int main(void) {

	while (1 == 1)
	{
		printf("Geef een getal: ");
		scanf_s("%f", &a);
		printf("Hoe vaak?: ");
		scanf_s("%d", &b);
		printf("\n");
		if(a * b < 10000){
			for (i = 1; i <= b; i++) {
				printf("%4f x %4f = %4f\n", a, i, a * i);

			}
		}
		else {
			printf("Te groot getal");
			printf("\n");
		}
		printf("\n");
	}
}*/

/*#include <stdio.h>

int a;


int main(void) {

	while(1 == 1){
		printf("enter number: ");
		scanf("%d", &a);

		switch (a)
		{
		case 1:
			printf("urmom \n");
			break;
		case 2:
			printf("urdad \n");
			break;
		case 3:
			printf("uruncle \n");
			break;
		case 4:
			printf("uraunt \n");
			break;
		case 5:
			printf("urgrandma \n");
			break;
		case 6:
			printf("urgrandpa \n");
			break;
		case 7:
			printf("urcousin \n");
			break;
		case 8:
			printf("ursister \n");
			break;
		case 9:
			printf("urbrother \n");
			break;
		case 10:
			printf("urwife \n");
			break;
		case 11:
			printf("urhusband \n");
			break;
		case 12:
			printf("urson \n");
			break;
		case 13:
			printf("urdaughter \n");
			break;
		case 14:
			printf("ursoninlaw \n");
			break;
		case 15:
			printf("urdaughterinlaw \n");
			break;
		case 16:
			printf("urgrandson \n");
			break;
		case 17:
			printf("urgranddaughter \n");
			break;
		case 18:
			printf("urgrandsoninlaw \n");
			break;
		case 19:
			printf("urgranddaughterinlaw \n");
			break;
		default:
			printf("nobody in your family");
			break;
		}
	printf("\n");
	}
}*/

#import <stdio.h>

/*
int seconds = (totalSeconds % 60);
int minutes = (totalSeconds % 3600) / 60;
int hours = (totalSeconds % 86400) / 3600;
int days = (totalSeconds % (86400 * 30)) / 86400;
*/


int main(void) {

	int totalSeconds = 0;
	int seconds = 0;
	int minutes = 0;
	int hours = 0;
	int days = 0;
	int weeks = 0;

	printf("Enter the number of seconds: ");
	scanf("%d", &totalSeconds);

	seconds = (totalSeconds % 60);
	minutes = (totalSeconds % 3600) / 60;
	hours = (totalSeconds % 86400) / 3600;
	days = (totalSeconds % (86400 * 30)) / 86400;

	printf("%d days, %d hours, %d minutes, %d seconds\n", days, hours, minutes, seconds);
}