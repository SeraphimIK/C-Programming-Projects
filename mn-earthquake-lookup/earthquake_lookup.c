#include <stdio.h>
#include <time.h>
#define SIZE 20
#define CITY_SIZE 50

int compare(char *s1, char *s2);

int main() {
    printf("Program developed by Seraphim Ikuomola \n");

    int seq[SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    char *city[SIZE] = {
        "Long Prairie", "New Prague", "St. Vincent", "New Ulm", "Red Lake",
        "Staples", "Bow String", "Detroit Lakes", "Alexandria", "Pipestone",
        "Morris", "Milaca", "Evergreen", "Rush City", "Nisswa", "Cottage Grove",
        "Walker", "Dumont", "Granite Falls", "Brandon"
    };

    char *date[SIZE] = {
        "1860-61", "12/16/1860", "12/28/1880", "2/5/1881", "2/6/17", "9/3/17",
        "12/23/28", "1/28/39", "2/15/50", "9/28/64", "7/9/75", "3/5/79",
        "4/16/79", "4/24/81", "9/27/82", "6/4/93", "2/9/94", "4/29/11",
        "9/10/15", "6/18/20"
    };

    char *intensity[SIZE] = {
        "VIII", "VII", "IV", "IV", "V", "VI", "V", "V", "IV", "IV",
        "VII", "I", "III", "I", "I", "IV", "II", "VI", "III", "III"
    };

    float mag[] = {5, 4.7, 3.6, 3.5, 3.8, 4.3, 3.8, 3.9, 3.6, 3.4, 4.7, 1, 3.1, 0.1, 1, 3.6, 2, 4.1, 3.1, 3.12};

    float damageCost[SIZE];
    for (int i = 0; i < SIZE; i++) {
        damageCost[i] = mag[i] * 5000000;
    }

    char key[CITY_SIZE];

    printf("#\tName\t\t\tDate\t\tIntensity\tMagnitude\tDamage Cost\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t%-20s%-15s%-10s%-12.2f$%.2f\n",
               seq[i], city[i], date[i], intensity[i], mag[i], damageCost[i]);
    }

    float sumMag = 0;
    for (int i = 0; i < SIZE; i++) {
        sumMag += mag[i];
    }
    float meanMag = sumMag / SIZE;
    float avgCost = meanMag * 5000000;

    printf("\nAverage Magnitude: %.2f\n", meanMag);
    printf("Average Damage Cost: $%.2f\n", avgCost);

    char cont = 'y';

    while (cont == 'y' || cont == 'Y') {
        time_t now = time(NULL);
        printf("\nSeraphim Ikuomola - %s", ctime(&now));

        printf("Enter city (or type 'quit' to exit): ");
        scanf("%49[^\n]%*c", key);

        if (compare(key, "quit") == 1) {
            break;
        }

        int found = 0;
        for (int i = 0; i < SIZE; i++) {
            found = compare(city[i], key);
            if (found == 1) {
                printf("\n%s is found at position %d. Date = %s, the earthquake magnitude = %.2f \n",
                       key, seq[i], date[i], mag[i]);
                break;
            }
        }

        if (found == 0) {
            printf("\n%s is not found in the array\n", key);
        }

        printf("\nSearch again? (y/n): ");
        scanf(" %c", &cont);
    }

    printf("\nProgram ended. Goodbye!\n");

    return 0;
}

int compare(char *s1, char *s2) {
    int i;
    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') {
            return 1;
        }
    }
    return 0;
}
