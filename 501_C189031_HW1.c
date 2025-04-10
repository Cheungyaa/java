#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    float string[5];
    printf("Type the values of 5 sampled points: ");
    scanf_s("%f %f %f %f %f", &string[0], &string[1], &string[2], &string[3], &string[4]);

    printf("Digitized signal after quantization and coding is: ");

    for (int i = 0; i < 5; i++) {
        if (string[i] >= -5 && string[i] < -3.75) { printf("000 "); }
        else if (string[i] >= -3.75 && string[i] < -2.5) { printf("001 "); }
        else if (string[i] >= -2.5 && string[i] < -1.25) { printf("010 "); }
        else if (string[i] >= -1.25 && string[i] < 0) { printf("011 "); }
        else if (string[i] >= 0 && string[i] < 1.25) { printf("100 "); }
        else if (string[i] >= 1.25 && string[i] < 2.5) { printf("101 "); }
        else if (string[i] >= 2.5 && string[i] < 3.75) { printf("110 "); }
        else if (string[i] >= 3.75 && string[i] <= 5) { printf("111 "); }
    }

    printf("\n");
    scanf_s("");
    return 0;
}
