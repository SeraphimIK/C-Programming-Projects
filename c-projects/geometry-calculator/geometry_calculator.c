#include <stdio.h>
#include <math.h>

// Function prototypes
int input();
void output(float);
float areaOfCircle(int radius);
float perimeterOfKite(float diagonal1, float diagonal2);

int main()
{
    float result;
    int choice, num;

    printf("Project developed by Seraphim Ikuomola. Date: 06/25/2026\n\n");

    do {
        // Menu
        printf("1. Calculate area of circle\n");
        printf("2. Calculate area of square\n");
        printf("3. Calculate perimeter of kite\n");
        printf("0. Quit\n");
        printf("Enter your choice:\t");

        choice = input();

        switch (choice) {
        case 0: { break; }
        case 1: {
            printf("Enter radius:\n");
            num = input();
            result = areaOfCircle(num);
            printf("Area of circle=");
            output(result);
            break;
        }
        case 2: {
            printf("Enter side of square:\n");
            num = input();
            result = num * num;
            printf("Area of square=");
            output(result);
            break;
        }
        case 3: {
            // Hardcoded per assignment: diagonal1=12, diagonal2=15
            result = perimeterOfKite(12, 15);
            printf("Perimeter of kite=");
            output(result);
            printf("\n");
            break;
        }
        default:
            printf("wrong Input\n");
        }

    } while (choice != 0);

    return 0;
}

// function to take input
int input()
{
    int number;
    scanf("%d", &number);
    return (number);
}

// function to print output
void output(float number) { printf("%f", number); }

// Area of a circle
float areaOfCircle(int radius)
{
    return radius * radius * 3.14;
}

// Perimeter of a kite
float perimeterOfKite(float diagonal1, float diagonal2)
{
    float half_d1 = diagonal1 / 2;
    float half_d2 = diagonal2 / 2;
    float side = sqrt((half_d1 * half_d1) + (half_d2 * half_d2));
    return 4 * side;
}