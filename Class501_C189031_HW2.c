#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float binaryToFloat(const char* binary) {
    float number = 0.0f;
    int isMinus = 0;
    const char* ptr = binary;

    if (*ptr == '-') {
        isMinus = 1;
        ptr++;
    }

    while (*ptr && *ptr != '.') {
        number = number * 2 + (*ptr - '0');
        ptr++;
    }

    if (*ptr == '.') {
        ptr++;
        float small = 0.5f;
        while (*ptr) {
            if (*ptr == '1') {
                number += small;
            }
            small *= 0.5f;
            ptr++;
        }
    }

    if (isMinus) return -number;
    return number;
}

void showIEEE754(float num) {
    union {
        float f;
        unsigned int bits;
    } data;
    data.f = num;

    for (int i = 31; i >= 0; i--) {
        printf("%d", (data.bits >> i) & 1);
    }
    printf("\n");
}

void readSamples(float samples[], int count) {
    printf("Type the values of %d sampled points: ", count);
    for (int i = 0; i < count; i++) {
        scanf("%f", &samples[i]);
    }
}

void quantizeAndPrint(float samples[], int count, int level) {
    printf("The level of the input samples are ");
    for (int i = 0; i < count; i++) {
        int levelValue = 0;
        if (samples[i] >= -5 && samples[i] <= 5) {
            levelValue = (int)((samples[i] + 5) / 10 * level);
        }
        printf("%d ", levelValue);
    }

    printf("\nDigitized signal after quantization and coding is ");
    for (int i = 0; i < count; i++) {
        int levelValue = 0;
        if (samples[i] >= -5 && samples[i] <= 5) {
            levelValue = (int)((samples[i] + 5) / 10 * level);
        }

        for (int j = level / 2; j >= 1; j /= 2) {
            printf("%d", levelValue >= j ? 1 : 0);
            levelValue %= j;
        }
        printf(" ");
    }
    printf("\n");
}

int main() {
    int level = 0;
    float samples[5];

    printf("What is the level of Quantization? ");
    scanf("%d", &level);

    readSamples(samples, 5);
    quantizeAndPrint(samples, 5, level);

    char binaryInput[100];
    printf("Type a binary number for float point number: ");
    scanf("%s", binaryInput);

    float result = binaryToFloat(binaryInput);
    printf("The converted floating number is ");
    showIEEE754(result);

    return 0;
}
