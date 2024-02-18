#include <stdio.h>
#pragma warning(disable : 4996)

#define sleutel 0x0A

int main(void){
    
    FILE* normaalBestand;

    FILE* enryptedBestand;

    char normaal, encrypted; 

    normaalBestand = fopen("C:\\encrypted.txt", "r"); // input

    enryptedBestand = fopen("C:\\decrypted.txt", "w"); // output

    while(fscanf(normaalBestand, "%c", &normaal) == 1){
        // scanf( console      , "%d", &getal)

        encrypted = normaal ^ sleutel;

        fprintf(enryptedBestand, "%c", encrypted);
    }

    fclose(normaalBestand);
    fclose(enryptedBestand);

    return 0;

}

/*
    Neem het programma van listing 1 als basis en pas deze aan, zodat dit nieuwe programma het bestand
    encrypted.txt (input) inleest en weer zorgt dat het originele bestand weer ontstaat in een nieuw bestand
    met de naam decrypted.txt (output) in de directory C:\.
*/