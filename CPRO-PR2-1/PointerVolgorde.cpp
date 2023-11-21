#include <stdio.h>
#pragma warning(disable:4996)




void opvolgorde(int* a, int* b, int* c) {
	int temp;
	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
	if (*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}
	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

int main() {
	int i, j, k;

	scanf("%d\n%d\n%d", &i, &j, &k);
	opvolgorde(&i, &j, &k);
	printf("de juiste volgorde is: %d %d %d", i, j, k);


}