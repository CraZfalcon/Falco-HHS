#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#pragma warning(disable : 4244)

struct substitutieStruct {
    double x;
    double y;
};

struct abcFormuleStruct {
    double x;
    double y;
    double d;
};

int plus(int doorWerkGetal) {
    int operant = 0;
    printf("Voer de operant in\n");
    scanf_s("%d", &operant);
    return doorWerkGetal + operant;
}

int min(int doorWerkGetal) {
    int operant = 0;
    printf("Voer de operant in\n");
    scanf_s("%d", &operant);
    return doorWerkGetal - operant;
}

int keer(int doorWerkGetal) {
    int operant = 0;
    printf("Voer de operant in\n");
    scanf_s("%d", &operant);
    return doorWerkGetal * operant;
}

int delen(int doorWerkGetal) {
    int operant = 0;
    printf("Voer de operant in\n");
    scanf_s("%d", &operant);
    return doorWerkGetal / operant;
}

int macht(int doorWerkGetal) {
    int operant = 0;
    printf("Voer de operant in\n");
    scanf_s("%d", &operant);
    return pow(doorWerkGetal, operant);
}

int wortel(int doorWerkGetal) {
    int operant = 0;
    printf("Voer de operant in\n");
    scanf_s("%d", &operant);
    return pow(doorWerkGetal, 1.0 / operant);
}

int omdraaien(int doorWerkGetal) {
    printf("\n%d is omgekeerd ", doorWerkGetal);
    int uitkomst = 0;
    do {
        uitkomst *= 10;
        uitkomst += doorWerkGetal % 10;
        doorWerkGetal /= 10;
    } while (doorWerkGetal > 0);
    return uitkomst;
}

int faculteit(int doorWerkGetal) {
    int uitkomst = doorWerkGetal;
    for (int i = doorWerkGetal - 1; i >= 2; i--) {
        uitkomst *= i;
    }
    return uitkomst;
}

int tijdInSeconden(int doorWerkGetal) {
    struct UrenMinutenSeconden {
        int uren = 0;
        int minuten = 0;
        int seconden = 0;
    } tijd;
    printf("Geef het aantal uren, minuten en seconden\n");
    scanf_s("%d\n %d\n %d", &tijd.uren, &tijd.minuten, &tijd.seconden);

    int uitkomst = tijd.uren * 3600 + tijd.minuten * 60 + tijd.seconden;
    return uitkomst;
}

int weerstandenParralel(int doorWerkGetal) {
    int aantalWeerstanden;
    printf("Geef het aantal weerstanden\n");
    scanf_s("%d", &aantalWeerstanden);

    double totWeerstand = 0;
    for (int i = 0; i < aantalWeerstanden; i++) {
        double weerstand;
        printf("geef de waarde van weerstand %d\n", i);
        scanf_s("%lf", &weerstand);
        totWeerstand += 1.0 / weerstand;
    }
    totWeerstand = 1.0 / totWeerstand;
    return totWeerstand;
}

int rente(int doorWerkGetal) {
    double operant = 0;
    double rentepos = 0;
    double renteneg = 0;
    while (1) {
        printf("Geef een geheel aantal jaar waarvoor u de rente wil berekenen\n");
        scanf_s("%d", &doorWerkGetal);

        if (doorWerkGetal >= 0 || doorWerkGetal < 100) {
            printf("Geef de beginwaarde\n");
            scanf_s("%lf", &operant);
            printf("Geef de rente voor als de beginwaarde positief is in procenten onder de 100\n");
            scanf_s("%lf", &rentepos);
            printf("Geef de rente voor als de beginwaarde negatief is in porcenten onder de 100\n");
            scanf_s("%lf", &renteneg);
            break;
        }
        printf("Ongeldig antwoord, probeer het opnieuw\n");
    }
    printf("\n ---------------------------------------- \n jaar   rente        nieuw \n ---------------------------------------- \n");
    double eindwaarde = operant;
    for (int i = 0; i < doorWerkGetal; i++) {
        eindwaarde = (eindwaarde / 100) * (100 + (eindwaarde > 0 ? rentepos : renteneg));
        double tussenwaarde = (eindwaarde - operant);
        printf(" %d      %lf   %lf\n", i, tussenwaarde, eindwaarde);
    }
    printf("\n ---------------------------------------- \n\n");
    return eindwaarde;
}

int transformer(int doorWerkGetal) {
    int Up, Us, Np, Ns;
    int uitkomst;
    doorWerkGetal = 0;

    do {
        printf("Geef 1 voor de spanning aan de primaire zijde\n2 voor de spanning aan de secundaire zijde\n3 voor het aantal wikkelingen aan de primaire zijde\n4 voor het aantal wikkelingen aan de secundaire zijde\n");
        scanf_s("%d", &doorWerkGetal);
    } while (doorWerkGetal <= 0 || doorWerkGetal >= 5);

    if (doorWerkGetal != 1) {
        printf("Geef de spanning aan de primaire zijde");
        scanf_s("%d", &Up);
    }
    else if (doorWerkGetal != 2) {
        printf("Geef de spanning aan de secundaire zijde");
        scanf_s("%d", &Us);
    }
    else if (doorWerkGetal != 3) {
        printf("Geef het aantal wikkelingen aan de primaire zijde");
        scanf_s("%d", &Np);
    }
    else if (doorWerkGetal != 4) {
        printf("Geef het aantal wikkelingen aan de secundaire zijde");
        scanf_s("%d", &Ns);
    }

    if (doorWerkGetal == 1) {
        uitkomst = Us * Np / Ns;
    }
    else if (doorWerkGetal == 2) {
        uitkomst = Up * Ns / Np;
    }
    else if (doorWerkGetal == 3) {
        uitkomst = Up * Ns / Us;
    }
    else {
        uitkomst = Us * Np / Up;
    }
    return uitkomst;
}

int grootsteEnKleinste(int doorWerkGetal, int operatie) {
    int uitkomst = 0;
    int counter = 0;
    int getallen[100]{};

    while (1) {
        printf("Geef een geheel positief getal om aan te geven hoeveel getallen u wil inlezen\n");
        scanf_s("%d", &doorWerkGetal);
        if (doorWerkGetal > 0) {
            break;
        }
        printf("Ongeldig antwoord, probeer het opnieuw\n");
    }

    do {
        printf("geef gettal nummer %d:   ", counter);
        scanf_s("%d", &getallen[counter]);
        counter++;
    } while (counter < doorWerkGetal);

    counter = 1;
    uitkomst = 0;

    if (operatie == 13) {
        do {
            if (getallen[counter] > uitkomst) {
                uitkomst = getallen[counter];
            }
            counter++;
        } while (counter > doorWerkGetal);
        counter = 1;
    }
    else if (operatie == 14) {
        do {
            if (getallen[counter] < uitkomst) {
                uitkomst = getallen[counter];
            }
            counter++;
        } while (counter > doorWerkGetal);
        counter = 1;
    }
    return uitkomst;
}

int overwerk(int doorWerkGetal) {
    int uitkomst = 0;
    int uren = 0;
    int salaris = 0;

    while (1) {
        printf("Geef het aantal uren dat u heeft gewerkt:\n");
        scanf_s("%d", &uren);
        if (uren >= 0) { break; }
    }
    printf("Geef uw uur loon:\n");
    scanf_s("%d", &salaris);

    if (uren <= 40) {
        uitkomst = uren * salaris;
    }
    else if (uren > 40 && uren <= 50) {
        uitkomst = (40 * salaris) + ((uren - 40) * salaris * 1, 5);
    }
    else {
        uitkomst = (50 * salaris) + ((uren - 40) * salaris * 2);
    }
    return uitkomst;
}

struct abcFormuleStruct abcFormuleFunctie() {
    struct abcFormuleStruct uitkomsten;
    double a = 0;
    double b = 0;
    double c = 0;
    double d = 0;
    double x = 0;
    double y = 0;

    printf("Geef a:\n");
    scanf_s("%lf", &a);
    printf("Geef b:\n");
    scanf_s("%lf", &b);
    printf("Geef :\n");
    scanf_s("%lf", &c);

    d = b * b - 4 * a * c;
    uitkomsten.x = (-1 * b + sqrt(d)) / (2 * a);
    uitkomsten.y = (-1 * b - sqrt(d)) / (2 * a);

    return (uitkomsten);
}

int gemiddelde(int doorWerkGetal) {
    int hoeveelheid = 0;
    int uitkomst = 0;
    int ary[100]{ NULL };

    while (1) {
        printf("Geef aan hoeveel getallen u wilt invoeren:\n");
        scanf_s("%d", &hoeveelheid);
        if (hoeveelheid > 0) { break; }
    }
    printf("\n\nGeef de getallen die u in wilt voeren:\n");
    for (int counter = 1; counter <= hoeveelheid; counter++) {
        scanf_s("%d", &ary[counter]);
    }
    for (int counter = 1; counter <= hoeveelheid; counter++) {
        uitkomst = uitkomst + ary[counter];
    }
    return (uitkomst / hoeveelheid);
}

struct substitutieStruct substitutieFunctie() {
    struct substitutieStruct uitkomsten;

    double a1 = 0;
    double b1 = 0;
    double c1 = 0;
    double a2 = 0;
    double b2 = 0;
    double c2 = 0;
    double d = 0;

    printf("Geef a1:\n");
    scanf_s("%lf", &a1);
    printf("Geef b1:\n");
    scanf_s("%lf", &b1);
    printf("Geef c1:\n");
    scanf_s("%lf", &c1);
    printf("Geef a2:\n");
    scanf_s("%lf", &a2);
    printf("Geef b2:\n");
    scanf_s("%lf", &b2);
    printf("Geef c2:\n");
    scanf_s("%lf", &c2);

    d = a1 * b2 - a2 * b1;
    if (d == 0) {
        printf("\nEr is geen uitkomst mogelijk\n\n");
        exit(1);
    }
    else {
        uitkomsten.x = (b2 * c1 - b1 * c2) / d;
        uitkomsten.y = (a1 * c2 - a2 * c1) / d;
    }

    return (uitkomsten);
}



int tafel(int doorWerkGetal) {
    double operant = 0;
    int fouten = 0;
    while (1) {
        printf("Voer een geheel en positief getal in om aan tegeven hoe lang u de tavel van %d wil\n", doorWerkGetal);
        scanf_s("%lf", &operant);
        if (operant < 0) {
            printf("getal is niet positief");
            break;
            fouten++;
        }
    }

    printf("Uitkomst is:\n");
    for (int tafel_getal = 1; tafel_getal <= operant; tafel_getal = tafel_getal + 1) {
        printf("%d x %d = %d\n", tafel_getal, doorWerkGetal, doorWerkGetal * tafel_getal);
    }
    return 1;
}

int maand(int doorWerkGetal) {
    int fouten = 0;
    if (doorWerkGetal <= 0 || doorWerkGetal >= 13) {
        while (1) {
            printf("Geef een vervangend getal van 1 tot 12 waarvan u de maand wil weten\n");
            scanf_s("%d", &doorWerkGetal);
            if (doorWerkGetal <= 0 || doorWerkGetal >= 13) {
                printf("Getal is niet tussen 1 en 12");
                break;
                fouten++;
            }
        }
    }

    switch (doorWerkGetal) {
    case 1: printf("\nDe maand is Januari\n\n"); break;
    case 2: printf("\nDe maand is Februari\n\n"); break;
    case 3: printf("\nDe maand is Maart\n\n"); break;
    case 4: printf("\nDe maand is April\n\n"); break;
    case 5: printf("\nDe maand is Mei\n\n"); break;
    case 6: printf("\nDe maand is Juni\n\n"); break;
    case 7: printf("\nDe maand is Juli\n\n"); break;
    case 8: printf("\nDe maand is Augustus\n\n"); break;
    case 9: printf("\nDe maand is Septemper\n\n"); break;
    case 10: printf("\nDe maand is Oktober\n\n"); break;
    case 11: printf("\nDe maand is November\n\n"); break;
    case 12: printf("\nDe maand De maand is December\n\n"); break;
    default: printf("\nEr ging iets fout\n\n"); break;
    }
    return 1;
}

int deelbaarDoor(int doorWerkGetal) {
    int uitkomst = 0;
    int fouten = 0;
    double operant;
    printf("Voer een getal in om aan te geven binnen welk getal u de deelbaare getalen met %d wil\n", doorWerkGetal);
    scanf_s("%lf", &operant);
    printf("de getallen die je met %d heel kan delen binnen het getal %lf zijn\n", doorWerkGetal, operant);
    int opslag = 1;
    while (uitkomst < operant - doorWerkGetal) {
        uitkomst = doorWerkGetal * opslag;
        printf("%d\n", uitkomst);
        opslag = opslag + 1;
    }
    printf("\n");
    return 1;
}

int evenOfOneven(int doorWerkGetal) {
    int fouten = 0;
    if (doorWerkGetal % 2 == 0) {
        printf("%d is een even getal\n\n", doorWerkGetal);
    }
    else {
        printf("%d is een oneven getal\n\n", doorWerkGetal);
    }
    return 1;
}

int sorteren(int doorWerkGetal, int operatie) {
    int HOEVEELHEID = 0;
    int fouten = 0;
    while (1) {
        printf("Voer een geheel, positief getal onder de honderd in om aan te geven hoeveel getalen u wil soorteren\n");
        scanf_s("%d", &HOEVEELHEID);
        if (HOEVEELHEID < 0 || HOEVEELHEID > 100) {
            printf("getal is niet positief en onder de honderd");
            break;
            fouten++;
        }
    }
    double ary[100]{};
    double k;
    int herhalen = 0;
    int inlezen = 0;
    int i;
    int j;

    for (inlezen = 0; inlezen < HOEVEELHEID; inlezen = inlezen + 1) {
        do {
            printf("Geef getal %d op: ", inlezen + 1);

        } while (scanf_s("%lf", &ary[inlezen]) != 1);
    }

    for (herhalen = 0; herhalen < 9; herhalen++) {
        i = 0;
        j = 0;
        k = 0;
        for (i = 0; i < HOEVEELHEID - 1; i++) {
            j = i + 1;
            if (ary[i] > ary[j]) {
                k = ary[j];
                ary[j] = ary[i];
                ary[i] = k;
            }
        }
    }

    if (operatie == 20) {
        for (i = 0; i <= HOEVEELHEID - 1; i++) {
            printf("%d    %lf\n", i, ary[i]);
        }
    }
    else if (operatie == 21) {
        for (i = 0; i <= HOEVEELHEID - 1; i++) {
            j = HOEVEELHEID - i - 1;
            printf("%d    %lf\n", i, ary[j]);
        }
    }
    return 1;
}

int decimaalNaarBinair(int doorWerkGetal) {
    int fouten = 0;
    int ary[100]{ NULL };
    int counter = 1;
    printf("\n");
    do {
        ary[counter] = doorWerkGetal % 2;
        doorWerkGetal = doorWerkGetal / 2;
        counter++;
    } while (doorWerkGetal != 0);

    do {
        counter--;
        printf("%d", ary[counter]);
    } while (counter >= 2);

    printf("\n\n");
    return 1;
}

int decimaalNaarHexaDecimaal(int doorWerkGetal) {
    int fouten = 0;
    int ary[100]{ NULL };
    int counter = 1;
    printf("\n");
    do {
        ary[counter] = doorWerkGetal % 16;
        doorWerkGetal = doorWerkGetal / 16;
        counter++;
    } while (doorWerkGetal != 0);

    do {
        counter--;
        if (ary[counter] >= 10) {
            switch (ary[counter]) {
            case 10: printf("A"); break;
            case 11: printf("B"); break;
            case 12: printf("C"); break;
            case 13: printf("D"); break;
            case 14: printf("E"); break;
            case 15: printf("F"); break;
            default: fouten++; printf("\n\nEr ging iets fout\n\n"); break;
            }
        }
        else {
            printf("%d", ary[counter]);
        }
    } while (counter >= 2);

    printf("\n\n");
    return 1;
}

int binairNaarDecimaal(int doorWerkGetal) {
    int fouten = 0;
    int ary[100]{ NULL };
    int hoeveelheid = 0;
    int uitkomst = 0;

    while (1) {
        printf("\ngeef aan hoelang uw binaire getal is:\n");
        scanf_s("%d", &hoeveelheid);
        if (hoeveelheid >= 1) { break; }
        printf("\nOngeldig antwoord, probeer het opnieuw.\n\n");
        fouten++;
    }

    printf("\nVul het binaire getal, getal voor getal in:\n");

    for (int counter = 1; counter <= hoeveelheid; counter++) {
        while (1) {
            scanf_s("%d", &ary[counter]);
            if (ary[counter] == 1 || ary[counter] == 0) { break; }
            printf("\nOngeldig antwoord, probeer het opnieuw.\n\n");
            fouten++;
        }
    }

    for (int counter = 1; counter <= hoeveelheid; counter++) {
        uitkomst = uitkomst + (ary[counter] * (pow(2, (hoeveelheid - counter))));
    }

    printf("\n\nhet decimale getal is %d\n\n\n", uitkomst);

    return 1;
}

int hexaDecimaalNaarDecimaal(int doorWerkGetal) {
    int fouten = 0;
    char ary[100]{ NULL };
    int hoeveelheid = (sizeof ary / sizeof ary[0]);
    int uitkomst = 0;

    while (1) {
        printf("\nVul het hexadecimale getal, teken voor teken in:\n");
        scanf_s("%[^\n]%c", &ary);

        for (int counter = 0; counter <= hoeveelheid; counter++) {
            switch (ary[counter]) {
            case '0': ary[counter] = 0; break;
            case '1': ary[counter] = 1; break;
            case '2': ary[counter] = 2; break;
            case '3': ary[counter] = 3; break;
            case '4': ary[counter] = 4; break;
            case '5': ary[counter] = 5; break;
            case '6': ary[counter] = 6; break;
            case '7': ary[counter] = 7; break;
            case '8': ary[counter] = 8; break;
            case '9': ary[counter] = 9; break;
            case 'a':
            case 'A': ary[counter] = 10; break;
            case 'b':
            case 'B': ary[counter] = 11; break;
            case 'c':
            case 'C': ary[counter] = 12; break;
            case 'd':
            case 'D': ary[counter] = 13; break;
            case 'e':
            case 'E': ary[counter] = 14; break;
            case 'f':
            case 'F': ary[counter] = 15; break;
            default: printf("\n\nEr ging iets fout\n\n"); fouten++; break;
            }
        }
    }

    for (int counter = 0; counter <= hoeveelheid; counter++) {
        uitkomst = uitkomst + (ary[counter] * (pow(16, (hoeveelheid - counter))));
    }

    printf("\n\nhet decimale getal is %d\n\n\n", uitkomst);

    return uitkomst;
}



int main(void) {
    int uitkomst = 0;

    printf("Welkom bij de rekenmachine\n");
    while (1) {
        int doorRekenGetal = 0;
        printf("Voer een geheel getal in\n");
        scanf_s("%d", &doorRekenGetal);

        while (1) {
            int operatie;
            while (1) {
                printf("Voer in een: \n1 voor plus, 2 voor min, 3 voor keer, 4 voor delen, 5 voor kwadrateren,");
                printf("\n6 voor wortel, 7 voor omdraaien, 8 voor faculteit, 9 voor tijd in seconden, 10 voor parralelweerstand,");
                printf("\n11 voor rente, 12 voor transformer waarde, 13 voor het grootste getal, 14 voor het laagste getal,");
                printf("\n15 voor overwerk, 16 voor de ABCformule");
                printf("\n16 voor de tafel, 17 voor de maand, 18 voor deelbaardoor, 19 voor even of oneven, ");
                printf("\n20 voor hoog laag sorteren, 21 voor laag hoog sorteren, 22 voor binair, 23 voor hexadecimaal of");
                printf("\n24 voor binair naar decimaal\n\n");
                scanf_s("%d", &operatie);

                if (operatie >= 1 && operatie <= 28) {
                    break;
                }

                printf("Ongeldig antwoord, probeer het opnieuw.\n");
            }

            if (operatie >= 1 && operatie <= 28) {

                switch (operatie) {
                case 1: printf("De uitkomst is %d\n\n", plus(doorRekenGetal)); break;
                case 2: printf("De uitkomst is %d\n\n", min(doorRekenGetal)); break;
                case 3: printf("De uitkomst is %d\n\n", keer(doorRekenGetal)); break;
                case 4: printf("De uitkomst is %d\n\n", delen(doorRekenGetal)); break;
                case 5: printf("De uitkomst is %d\n\n", macht(doorRekenGetal)); break;
                case 6: printf("De uitkomst is %d\n\n", wortel(doorRekenGetal)); break;
                case 7: printf("De uitkomst is %d\n\n", omdraaien(doorRekenGetal)); break;
                case 8: printf("De uitkomst is %d\n\n", faculteit(doorRekenGetal)); break;
                case 9: printf("De gegeven tijd bestaat uit %d seconden\n\n", tijdInSeconden(doorRekenGetal)); break;
                case 10: printf("De totaalweerstand is %d Ohm\n\n", weerstandenParralel(doorRekenGetal)); break;
                case 11: printf("De eindwaarde is %d\n\n", rente(doorRekenGetal)); break;
                case 12: printf("De gewenste waarde is %d\n\n", transformer(doorRekenGetal)); break;
                case 13: printf("Het grootste getal is %d\n\n", grootsteEnKleinste(doorRekenGetal, operatie)); break;
                case 14: printf("Het kleinste getal is is %d\n\n", grootsteEnKleinste(doorRekenGetal, operatie)); break;
                case 15: printf("Het eind bedrag is %d\n\n", overwerk(doorRekenGetal)); break;
                case 16: struct abcFormuleStruct s16; s16 = abcFormuleFunctie(); printf("X = %lf \nY = %lf\n Determinant = %lf\n\n", s16.x, s16.y, s16.d); break;
                case 17: printf("het gemiddelde is %d", gemiddelde(doorRekenGetal)); break;
                case 18: struct substitutieStruct s18; s18 = substitutieFunctie(); printf("X = %lf \nY = %lf\n\n", s18.x, s18.y); break;
                case 19: tafel(doorRekenGetal); printf("Het programma is afgelopen\n\n"); break;
                case 20: maand(doorRekenGetal); printf("Het programma is afgelopen\n\n"); break;
                case 21: deelbaarDoor(doorRekenGetal); printf("Het programma is afgelopen\n\n"); break;
                case 22: evenOfOneven(doorRekenGetal); printf("Het programma is afgelopen\n\n"); break;
                case 23: sorteren(doorRekenGetal, operatie); printf("Het programma is afgelopen\n\n"); break;
                case 24: sorteren(doorRekenGetal, operatie); printf("Het programma is afgelopen\n\n"); break;
                case 25: decimaalNaarBinair(doorRekenGetal); printf("Het programma is afgelopen\n\n"); break;
                case 26: decimaalNaarHexaDecimaal(doorRekenGetal); printf("Het programma is afgelopen\n\n"); break;
                case 27: binairNaarDecimaal(doorRekenGetal); printf("Het programma is afgelopen\n\n"); break;
                case 28: hexaDecimaalNaarDecimaal(doorRekenGetal); printf("Het programma is afgelopen\n\n"); break;
                default: printf("Er ging iets fout\n\n"); break;
                }
            }

            int teruggaanNaar = 0;
            while (operatie <= 28) {
                printf("Voer in: 1 om opnieuw te rekenen, 2 om door te rekenen met dit getal of op 3 om af te sluiten\n");
                scanf_s("%d", &teruggaanNaar);

                if (teruggaanNaar >= 1 && teruggaanNaar <= 3) {
                    break;
                }
                printf("Ongeldig antwoord, probeer het opnieuw\n");
            }

            while (operatie >= 18 && operatie <= 28) {
                printf("Voer in: 1 om opnieuw te rekenen of 2 om af te sluiten\n");
                scanf_s("%d", &teruggaanNaar);

                if (teruggaanNaar >= 1 && teruggaanNaar <= 2) {
                    break;
                }
                printf("Ongeldig antwoord, probeer het opnieuw.\n");
            }

            if (teruggaanNaar == 1 && operatie <= 28) {
                break;
            }
            else if (teruggaanNaar == 2 && operatie <= 18) {
                doorRekenGetal = uitkomst;
                uitkomst = 0;
                continue;
            }
            else {
                printf("Bedankt voor het gebruiken van deze rekenmachine\n\n\n");
                return 0;
            }
        }
    }
}