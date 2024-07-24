#include <stdio.h>

int main() {
    unsigned int num = 0x12345678; // Example number (you can change this)
    char byte1, byte2, byte3, byte4;

    // Extracting bytes using bitwise operations
    byte1 = (num >> 24) & 0xFF;
    byte2 = (num >> 16) & 0xFF;
    byte3 = (num >> 8) & 0xFF;
    byte4 = num & 0xFF;

    printf("Byte 1: %d\n", byte1);
    printf("Byte 2: %d\n", byte2);
    printf("Byte 3: %d\n", byte3);
    printf("Byte 4: %d\n", byte4);

    return 0;
}

