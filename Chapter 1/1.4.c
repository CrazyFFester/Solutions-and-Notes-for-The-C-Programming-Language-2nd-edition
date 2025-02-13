#include <stdio.h>

int main() {
    float fahr;
    float celcius;
    int lower;
    int upper;
    int step;

    lower = 0;
    upper = 300;
    step = 20;

    celcius = lower;

    printf("Celcuis-Fahrenheir table\n\n");

    while (celcius <= upper) {
        fahr = (9.0 * celcius / 5.0) + 32.0;
        printf("%3.0f\t%6.1f\n", celcius, fahr);
        celcius = celcius + step;
    }
}
