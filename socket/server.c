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

int main(void) {
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    char buf[MAXLINE];
    char addr[INET_ADDRSTRLEN];
    int i, n;

    if (-1 == (listenfd = socket(AF_INET, SOCK_STREAM, 0))) {
        printf("create socket error: %s (%d)",
               strerror(errno), errno);
        exit(0);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    if (-1 == bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) {
        printf("bind socket error: %s (%d)",
               strerror(errno), errno);
        exit(0);
    }

    if (-1 == listen(listenfd, 20)) {
        printf("listen socket error: %s (%d)",
               strerror(errno), errno);
        exit(0);
    }

    printf("Accepting connctions ...\n");
    while (1) {
        cliaddr_len = sizeof(cliaddr);
        if (-1 == (connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &cliaddr_len))) {
            printf("accept socket error: %s (%d)",
                   strerror(errno), errno);
            exit(0);
        }

        if (-1 == (n = read(connfd, buf, MAXLINE))) {
            printf("accept socket error: %s (%d)",
                   strerror(errno), errno);
            exit(0);
        }

        if (-1 == inet_ntop(AF_INET, &cliaddr.sin_addr, addr, sizeof(addr))) {
            printf("inet_ntop() error: %s (%d)",
                   strerror(errno), errno);
            exit(0);
        }

        printf("Recv msg from CLIENT %s PORT %d\n",
               addr, ntohs(cliaddr.sin_port));

        for (i = 0; i < n; i++) {
            buf[i] = toupper(buf[i]);
        }

        if (write(connfd, buf, n) < 0) {
            printf("write error: %s (%d)",
                   strerror(errno), errno);
            exit(0);
        }

        close(connfd);
    }
}

