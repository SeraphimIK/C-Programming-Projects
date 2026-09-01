#include <stdio.h>

int main(void) {

    int grade;
    int total = 0;
    int count = 0;
    double average;

    printf("Student: Seraphim Ikuomola\n");
    printf("Date: June 4, 2026\n\n");

    printf("Enter grade, -1 to end: ");
    scanf("%d", &grade);

    while (grade >= 0) {
        if (grade > 100) {
            printf("Invalid. Enter grade between 0 and 100: ");
        } else {
            total += grade;
            count++;
            printf("Enter grade, -1 to end: ");
        }
        scanf("%d", &grade);
    }

    if (count > 0) {
        average = (double) total / count;
        printf("\nClass average is: %.2f\n", average);
    } else {
        printf("No grades entered.\n");
    }

    return 0;
}
