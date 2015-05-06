#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, char *argv[]) {
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;
    char *str;

    if (argc != 2) {
        fputs("usage: ./client message\n", stderr);
        exit(1);
    }
    str = argv[1];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("create socket error: %s(errno: %d)",
               strerror(errno), errno);
        exit(0);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        printf("inet_pton error: %s(errno: %d)",
               strerror(errno), errno);
        exit(0);
    }
    servaddr.sin_port = htons(SERV_PORT);
    
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("connect error: %s(errno: %d)",
               strerror(errno), errno);
        exit(0);
    }

    printf("send msg '%s' to server\n", str);
    if (write(sockfd, str, strlen(str)) < 0) {
        printf("write error: %s(errno: %d)",
               strerror(errno), errno);
        exit(0);
    }

    if ((n = read(sockfd, buf, MAXLINE)) == -1) {
        printf("read error: %s(errno: %d)",
               strerror(errno), errno);
        exit(0);
    }

    printf("Response from server: %s\n", buf);

    close(sockfd);
    return 0;
}

