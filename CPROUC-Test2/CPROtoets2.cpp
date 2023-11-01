#include <stdio.h>
#pragma warning(disable : 4996)

int rij[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int main(void) {
	for (int i = 0; i < (sizeof(rij) / sizeof(rij[0])); i++)
	{
		if (i % 2 == 1)
			printf("%d\n", rij[i]);
	}
}