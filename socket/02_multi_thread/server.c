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
#include <pthread.h>

#define MAXLINE 80
#define SERV_PORT 8000

typedef void* (*func)(void*);

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

struct sockfd {
    int sock_server;
    int sock_client;
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

void pthread_work(void *p)
{
    struct sockfd *argv = (struct sockfd *)p;
    int sock_server = argv->sock_server;
    int sock_client = argv->sock_client;
    char buf[MAXLINE];
    int n;

    printf("sock_server %d, sock_client %d\n", sock_server, sock_client);

    strcpy(buf, "This is server! welcome!\n");
    send(sock_client, buf, MAXLINE, 0);

    while (1) {
        bzero(buf, sizeof(buf));
        if ((n = recv(sock_client, buf, MAXLINE, 0)) == -1) {
            printf("read error: %s(errno: %d)", strerror(errno), errno);
            close(sock_server);
            return;
        }

        printf("Recv: %s\n", buf);

        if (strcmp(buf, "quit") == 0) {
            printf("quit!!!\n");
            break;
        }
    }
    close(sock_client);
    pthread_exit(0);
}

void server::startListen()
{
    struct sockaddr_in cliaddr;
    socklen_t cliaddr_len;
    int sock_client;

    if ((listen(sock_serv, 5)) == -1) {
        printf("listen socket error: %s(errno: %d)", strerror(errno), errno);
        close(sock_serv);
        return;
    }

    printf("Accepting connections ...\n");
    while (1) {
        cliaddr_len = sizeof(cliaddr);
        if ((sock_client = accept(sock_serv, (struct sockaddr*)&cliaddr, &cliaddr_len)) == -1) {
            printf("accept socket error: %s(errno: %d)", strerror(errno), errno);
            continue;
        }

        struct sockfd argv;
        argv.sock_server = sock_serv;
        argv.sock_client = sock_client;

        pthread_t tid;
        if (0 != pthread_create(&tid, NULL, (func)pthread_work, (void*)&argv)) {
            perror("thread create error!\n");
        } else {
            printf("create thread %d successfully!\n", tid);
        }
    }
}

int main(void) {
    server serv(SERV_PORT);
    serv.initServer();
    serv.startListen();
    return 0;
}

