#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <arpa/inet.h>
using namespace std;

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    char *str;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("create socket error: %s(errno: %d)",
               strerror(errno), errno);
        return -1;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("connect error: %s(errno: %d)", strerror(errno), errno);
        close(sockfd);
        return -1;
    }

    printf("connect to server: OK! \n");

    bzero(buf, sizeof(buf));
    recv(sockfd, buf, MAXLINE, 0);
    printf("recv: %s\n", buf);

    bzero(buf, sizeof(buf));
    strcpy(buf, "This is client!\n");
    send(sockfd, buf, MAXLINE, 0);

    while (1) {
        bzero(buf, sizeof(buf));
        cin >> buf;
        send(sockfd, buf, MAXLINE, 0);
        printf("Send to server: %s\n", buf);

        if (strcmp(buf, "quit") == 0) {
            printf("quit!!!\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}

