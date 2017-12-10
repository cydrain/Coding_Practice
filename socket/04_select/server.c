#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N 5
#define MAXLINE 80
#define SERV_PORT 8000

class server {
public:
    server(const short port);
    ~server();

    int initServer();
    void startListen();

private:
    struct sockaddr_in server_addr;
    int sock_serv;
};

server::server(const short port)
{
    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);
}

server::~server()
{
    close(sock_serv);
}

int server::initServer()
{
    int on;

    sock_serv = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_serv < 0) {
        printf("create socket error: %s(errno: %d)", strerror(errno), errno);
        return -1;
    }

    on = 1;
    // allow socket re-use a server address if it has been binded
    setsockopt(sock_serv, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    
    if ((bind(sock_serv, (struct sockaddr*)&server_addr, sizeof(server_addr))) == -1) {
        printf("bind socket error: %s(errno: %d)", strerror(errno), errno);
        close(sock_serv);
        return -1;
    }

    return 0;
}

void server::startListen()
{
    struct sockaddr_in cliaddr;
    socklen_t cliaddr_len;
    int sock_client;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i, n, flag;
    fd_set client_fdset;    // monitor file ID set
    int maxsock;
    struct timeval tv;      // timeout value
    int client_sockfd[N];
    int conn_amount = 0;

    if ((listen(sock_serv, N)) == -1) {
        printf("listen socket error: %s(errno: %d)", strerror(errno), errno);
        close(sock_serv);
        return;
    }

    maxsock = sock_serv;
    bzero((void*)client_sockfd, sizeof(client_sockfd));

    printf("Accepting connections ...\n");
    while (1) {
        FD_ZERO(&client_fdset);
        FD_SET(sock_serv, &client_fdset);

        tv.tv_sec = 30;
        tv.tv_usec = 0;

        for (i = 0; i < N; i++) {
            if (client_sockfd[i] != 0) {
                FD_SET(client_sockfd[i], &client_fdset);
                printf("add client_sockfd[%d] %d into fdset\n",
                       i, client_sockfd[i]);
            }
        }

        flag = select(maxsock+1, &client_fdset, NULL, NULL, &tv);
        if (flag < 0) {
            perror("select error!\n");
            break;
        } else if (flag == 0) {
            printf("select timeout!\n");
            continue;
        }

        for (i = 0; i < conn_amount; i++) {
            if (FD_ISSET(client_sockfd[i], &client_fdset)) {
                printf("start recv from client[%d]:\n", i);
                flag = recv(client_sockfd[i], buf, MAXLINE, 0);
                if (flag < 0) {
                    printf("client[%d] closed\n", i);
                    close(client_sockfd[i]);
                    FD_CLR(client_sockfd[i], &client_fdset);
                    client_sockfd[i] = 0;
                } else {
                    printf("recv from client[%d]: %s\n", i, buf);
                }
            }
        }

        if (FD_ISSET(sock_serv, &client_fdset)) {

            cliaddr_len = sizeof(cliaddr);
            if ((sock_client = accept(sock_serv, (struct sockaddr*)&cliaddr, &cliaddr_len)) == -1) {
                printf("accept socket error: %s(errno: %d)", strerror(errno), errno);
                continue;
            }

            if (conn_amount < N) {
                client_sockfd[conn_amount++] = sock_client;

                bzero(buf, sizeof(buf));
                strcpy(buf, "This is server! welcome!\n");
                send(sock_client, buf, MAXLINE, 0);

                printf("new connection client[%d] %s:%d\n", conn_amount-1,
                       inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

                bzero(buf, sizeof(buf));
                if ((n = recv(sock_client, buf, MAXLINE, 0)) == -1) {
                    printf("read error: %s(errno: %d)", strerror(errno), errno);
                    close(sock_serv);
                    return;
                }

                if (inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)) != NULL) {
                    printf("Received from %s at PORT %d: %s\n", str,
                           ntohs(cliaddr.sin_port), buf);
                }

                if (strcmp(buf, "quit") == 0) {
                    printf("quit!!!\n");
                    break;
                }

                if (sock_client > maxsock) {
                    maxsock = sock_client;
                }
            }
        }
    }

    for (i = 0; i < N; i++) {
        if (client_sockfd[i] != 0) {
            close(client_sockfd[i]);
        }
    }
}

int main(void) {
    server serv(SERV_PORT);
    serv.initServer();
    serv.startListen();
    return 0;
}

