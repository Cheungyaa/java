#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void xor_division(char* dividend, const char* divisor, int data_len, int gen_len, char* crc_result) {
    char temp[30] = { 0 };
    strncpy(temp, dividend, data_len + gen_len - 1);

    for (int i = 0; i < data_len; i++) {
        if (temp[i] == '1') {
            for (int j = 0; j < gen_len; j++) {
                temp[i + j] = (temp[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }

    strncpy(crc_result, temp + data_len, gen_len - 1);
    crc_result[gen_len - 1] = '\0';
}

int main() {
    char gen[5] = { 0 };
    char data[20] = { 0 };
    char augmented_data[30] = { 0 };
    char crc[5] = { 0 };
    FILE* input = NULL;
    FILE* output = NULL;

    printf("Please, type 4-bit generation code: ");
    scanf("%4s", gen);

    input = fopen("data.txt", "r");
    if (input == NULL) {
        return 1;
    }
    fscanf(input, "%10s", data);
    fclose(input);

    int data_len = strlen(data);
    int gen_len = strlen(gen);

    strcpy(augmented_data, data);
    for (int i = 0; i < gen_len - 1; i++) {
        augmented_data[data_len + i] = '0';
    }
    augmented_data[data_len + gen_len - 1] = '\0';

    xor_division(augmented_data, gen, data_len, gen_len, crc);

    output = fopen("output.txt", "w");
    if (output == NULL) {
        return 1;
    }
    fprintf(output, "The data with CRC is %s%s\n", data, crc);
    fclose(output);

    printf("The data with CRC: %s%s\n", data, crc);

    return 0;
}
