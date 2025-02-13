#include <stdio.h>

// print Fahrenheit-Celsius table
int main() {
    int fahr;

    for (fahr = 300.0; fahr >= 0.0; fahr = fahr - 20.0) {
        printf("%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}
