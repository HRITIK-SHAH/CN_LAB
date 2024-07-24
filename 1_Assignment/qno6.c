#include <stdio.h>

struct pkt {
    char ch[8];
    int num1;
    int num2;
};

struct pkt1 {
    char ch1;
    char ch2;
};

int main() {
    struct pkt packet;
    struct pkt1 extracted;
    
    for (int i = 0; i < 8; i++) {
        packet.ch[i] = 'A' + i;
    }
    packet.num1 = 0x12345678;
    packet.num2 = 0x9ABCDEF0;

    printf("Data in packet:\n");
    printf("ch: ");
    for (int i = 0; i < 8; i++) {
        printf("%c ", packet.ch[i]);
    }
    printf("\nnum1: 0x%X\n", packet.num1);
    printf("num2: 0x%X\n", packet.num2);

    printf("\nExtracted 2-byte data:\n");

    for (int i = 0; i < 16; i += 2) {
        if (i < 8) {
            extracted.ch1 = packet.ch[i];
            extracted.ch2 = packet.ch[i + 1];
        } else if (i < 12) {
            extracted.ch1 = (packet.num1 >> ((i - 8) * 8)) & 0xFF;
            extracted.ch2 = (packet.num1 >> ((i - 7) * 8)) & 0xFF;
        } else {
            extracted.ch1 = (packet.num2 >> ((i - 12) * 8)) & 0xFF;
            extracted.ch2 = (packet.num2 >> ((i - 11) * 8)) & 0xFF;
        }

        printf("ch1: 0x%X, ch2: 0x%X\n", (unsigned int)(unsigned char)extracted.ch1, (unsigned int)(unsigned char)extracted.ch2);
    }

    return 0;
}

