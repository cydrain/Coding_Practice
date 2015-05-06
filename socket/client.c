#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, char* argv[]) {
    struct sockaddr_in servaddr;
    int connfd;
    char buf[MAXLINE];
    char *str;
    int i, n;

    if (argc != 2) {
        fputs("usage: ./client message\n", stderr);
        exit(1);
    }
    str = argv[1];

    if (-1 == (connfd = socket(AF_INET, SOCK_STREAM, 0))) {
        printf("create socket error: %s (%d)",
               strerror(errno), errno);
        exit(0);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    servaddr.sin_port = htons(SERV_PORT);

    if (-1 == connect(connfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) {
        printf("connect socket error: %s (%d)",
               strerror(errno), errno);
        exit(0);
    }

    printf("send msg '%s' to server\n", str);
    if (write(connfd, str, strlen(str)) < 0) {
        printf("write error: %s (%d)",
               strerror(errno), errno);
        exit(0);
    }

    if (-1 == (n = read(connfd, buf, MAXLINE))) {
        printf("accept socket error: %s (%d)",
               strerror(errno), errno);
        exit(0);
    }

    printf("Response from server: ");
    for (i = 0; i < n; i++) {
        printf("%c", buf[i]);
    }
    printf("\n");

    close(connfd);
    return 0;
}

