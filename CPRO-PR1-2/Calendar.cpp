#include <stdio.h>


//int main(void) {
//
//	int getal = 0;
//	int temp = 0;
//
//	char woord;
//
//	/*do {
//		printf("geef een getal: ");
//		scanf_s("%d", &getal);
//
//		if (temp > 0 && getal != temp && getal !=0) {
//			printf("\nde getallen zijn NIET hetzelfde\n\n");
//		}
//	
//		temp = getal;
//
//	} while (getal != 0);*/
// 
//
//
//
//
//
//
//
//
//
//
//
//	do {
//		printf("geef een getal: ");
//		scanf_s("%d", &i);
//		printf("\ngeef een ander getal: ");
//		scanf_s("%d", &j);
//
//		if (i != j) {
//			printf("\nde getallen zijn NIET hetzelfde\n\n");
//		}
//		else if (i == j) {
//			printf("de getallen zijn WEL hetzelfde");
//		}
//	} while (getal != 0);
//}


int main(void) {

	int pincode = 1234;
	int pogingen = 3;
	int invoer;

	for (int i = 1; i <= pogingen; i++) {
		printf("voer code in: ");
		scanf_s("%d", &invoer);
		if (invoer == pincode) {
			printf("\n\n\npincode correct!\n\n\n");
			return 1;
		}
		else {
			printf("code fout. probeer het opnieuw\n\n");
		}
	}
	printf("\n\n\nVERGRENDELD!!!!\n\n\n");
}