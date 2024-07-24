#include <stdio.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    struct pkt packet;
    unsigned int number;
    
    printf("Enter a number (0 to 16777215): ");
    scanf("%u", &number);
    
    packet.ch1 = (number >> 16) & 0xFF;
    packet.ch2[0] = (number >> 8) & 0xFF;
    packet.ch2[1] = number & 0xFF;
    packet.ch3 = 0;

    printf("ch1: 0x%X\n", (unsigned int)(unsigned char)packet.ch1);
    printf("ch2[0]: 0x%X\n", (unsigned int)(unsigned char)packet.ch2[0]);
    printf("ch2[1]: 0x%X\n", (unsigned int)(unsigned char)packet.ch2[1]);
    printf("ch3: 0x%X\n", (unsigned int)(unsigned char)packet.ch3);

    unsigned int aggregated_number = ((unsigned int)packet.ch1 << 16) |
                                     ((unsigned int)packet.ch2[0] << 8) |
                                     (unsigned int)packet.ch2[1];
    
    printf("Aggregated number: 0x%X\n", aggregated_number);

    return 0;
}

