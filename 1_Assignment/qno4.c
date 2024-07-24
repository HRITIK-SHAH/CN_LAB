#include <stdio.h>

int check_endianness() {
    unsigned int x = 1;
    char *c = (char*)&x;
    return (int)*c;
}

void print_bytes(unsigned int num) {
    unsigned char *byte = (unsigned char*)&num;
    for (int i = 0; i < sizeof(num); i++) {
        printf("Byte %d: 0x%X\n", i, byte[i]);
    }
}

unsigned int convert_endianness(unsigned int num) {
    unsigned int byte0 = (num & 0x000000FF) << 24;
    unsigned int byte1 = (num & 0x0000FF00) << 8;
    unsigned int byte2 = (num & 0x00FF0000) >> 8;
    unsigned int byte3 = (num & 0xFF000000) >> 24;
    return (byte0 | byte1 | byte2 | byte3);
}

int main() {
    if (check_endianness()) {
        printf("The system is Little Endian\n");
    } else {
        printf("The system is Big Endian\n");
    }

    unsigned int number;
    printf("Enter a number: ");
    scanf("%u", &number);

    printf("Original number in memory:\n");
    print_bytes(number);

    unsigned int converted_number = convert_endianness(number);

    printf("Converted number in memory:\n");
    print_bytes(converted_number);

    return 0;
}

