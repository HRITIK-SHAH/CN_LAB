#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// socket_domain_protocol
int main() {
    int ret = socket(AF_INET, SOCK_DGRAM, 0);
    if (ret == -1) {
        printf("Socket creation failed\n");
        exit(1);
    } else {
        printf("Socket created successfully\n");
    }

    struct sockaddr_in sent;
    memset(&sent, 0, sizeof(sent)); // Zero out the structure
    sent.sin_family = AF_INET;
    sent.sin_port = htons(5000); // Convert to network byte order
    sent.sin_addr.s_addr = INADDR_ANY;

    ret = bind(ret, (struct sockaddr *)&sent, sizeof(sent));
    if (ret == -1) {
        printf("Bind failed\n");
        exit(1);
    } else {
        printf("Bind successful\n");
    }

    return 0;
}

