#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int compare(char Data[], char Code[], int len) {
    for (int i = 0; i < len; i++) {
        if (Data[i] > Code[i]) return -1;
        if (Data[i] < Code[i]) return 1;
    }
    return 0;
}

int main() {
    char data[30];
    char crc_code[5];
    char result[30]{};

    printf("Please, type 4-bit generation code: ");
    scanf("%s", crc_code);
    printf("Please, type 10-bit Data: ");
    scanf("%s", data);

    int data_length = strlen(data);
    int code_length = strlen(crc_code);

    for (int i = 0; i < data_length; i++) {
        result[i] = data[i];
    }

    for (int i = 0; i < code_length; i++) {
        result[data_length + i] = '0';
    }

    char* crc = result + data_length + code_length;
    for (int i = 0; i < code_length; i++) {
        crc[i] = '0';
    }
    crc[code_length] = 0;

    for (int i = 0; i <= data_length; i++) {
        if (compare(crc_code, crc, code_length) >= 0) {
            for (int j = 0; j < code_length; j++) {
                crc[j] = (crc[j] == crc_code[j]) ? '0' : '1';
            }
        }

        for (int j = 0; j < code_length - 1; j++) {
            crc[j] = crc[j + 1];
        }
        crc[code_length - 1] = result[i];
    }

    strcpy(result + data_length, crc);
    printf("The data with CRC: %s\n", result);
    return 0;
}
2