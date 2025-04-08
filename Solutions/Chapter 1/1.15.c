#include <stdio.h>

#define MAX_COUNT 300

float fahrToCel(float fahr);

int main() {
    float fahr;
    float cel;

    printf("Fahrenheit To Celsius table\n\n");
    for (fahr = 0; fahr <= MAX_COUNT; fahr += 20) {
        cel = fahrToCel(fahr);
        printf("%3.0f\t%6.1f\n", fahr, cel);
    }
}

float fahrToCel(float fahr) { return (5.0 / 9.0) * (fahr - 32.0); }
