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

int main(void) {
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i, n;
    const char *p;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("create socket error: %s(errno: %d)", strerror(errno), errno);
        exit(0);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    
    if ((bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) == -1) {
        printf("bind socket error: %s(errno: %d)", strerror(errno), errno);
        exit(0);
    }

    if ((listen(listenfd, 20)) == -1) {
        printf("listen socket error: %s(errno: %d)", strerror(errno), errno);
        exit(0);
    }

    printf("Accepting connections ...\n");
    while (1) {
        cliaddr_len = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &cliaddr_len)) == -1) {
            printf("accept socket error: %s(errno: %d)", strerror(errno), errno);
            exit(0);
        }
        if ((n = read(connfd, buf, MAXLINE)) == -1) {
            printf("read error: %s(errno: %d)", strerror(errno), errno);
            exit(0);
        }

        if (inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)) != -1) {
            printf("Received from %s at PORT %d: %s\n", str,
                   ntohs(cliaddr.sin_port), buf);
        }

        for (i = 0; i < n; i++) {
            buf[i] = toupper(buf[i]);
        }

        if (write(connfd, buf, n) < 0) {
            printf("write error: %s(errno: %d)", strerror(errno), errno);
            exit(0);
        }
        close(connfd);
    }
}

