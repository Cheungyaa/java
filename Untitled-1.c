#include <stdio.h>

int quantize(float value) {
    // -5V ~ 5V 범위를 8개의 양자화 레벨로 나눔
    int level = (int)((value + 5) / 10 * 7 + 0.5);
    return level;
}

int main() {
    float sampled_points[5];
    int quantized_values[5];

    printf("Type the values of 5 sampled points: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &sampled_points[i]);
    }

    for (int i = 0; i < 5; i++) {
        quantized_values[i] = quantize(sampled_points[i]);
    }

    printf("Digitized signal after quantization and coding is ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", quantized_values[i]);
    }
    printf("\n");

    return 0;
}
