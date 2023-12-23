#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main(void) {

<<<<<<< Updated upstream
		/*/FILE* filePointer;
=======
		FILE* filePointer;
>>>>>>> Stashed changes

		char buffer[100] = "";
		const char adress1 [] = "C:\\Users\\falco\\OneDrive\\AB - 01 - PCB & Code\\Github\\Falco-HHS\\CPRO-PR1-2\\Tekst1.txt";
		const char adress2 [] = "C:\\Users\\falco\\OneDrive\\AB - 01 - PCB & Code\\Github\\Falco-HHS\\CPRO-PR1-2\\Tekst2.txt";

		filePointer = fopen(adress1, "r");
		if (filePointer == NULL) { printf("File not found\n\n"); }
		else fscanf(filePointer, "%s", buffer);
		printf("\n\n%s\n\n", buffer);
		filePointer = fopen(adress2, "r");
		if (filePointer == NULL) { printf("File not found\n\n"); }
		else fscanf(filePointer, "%s", buffer);

<<<<<<< Updated upstream
		printf("\n\n%s\n\n", buffer);*/


	FILE* filePointer;
	char buffer[100] = "";
	filePointer = fopen("C:\\Users\\falco\\Desktop\\test.txt", "r");
	for (int i = 0; i < 120; i++) {
		//fprintf(filePointer, "regel nummer %d\n", i);
		fscanf(filePointer, "%s", buffer);
		printf("%s\n", buffer);
	}
	return 0;

}



=======
		printf("\n\n%s\n\n", buffer);


}


>>>>>>> Stashed changes
/*void old() {
	printf("Enter the document name: ");
	scanf("%s", &docName);

	char fileAdress[];
	fileAdress = strcat(defaultAdress, docName);

	filePointer = fscanf(adress, "r");
	if (filePointer == NULL) { printf("File not found"); exit(-1); }
	if (docName == "-h") { printf("helpdesk"); exit(-1); }

	if (docName != "-h") {

		fscanf(filePointer, "%s", buffer);
		printf("%s\n\n", buffer);











		return 0;
	}
}*/