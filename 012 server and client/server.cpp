#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {

    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;

    char sendBuff[1025];
    time_t ticks;

    // create socket descriptor
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff));

    serv_addr.sin_family = AF_INET; // family/domain
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // the interface to listen on
    serv_addr.sin_port = htons(5000); // the port on which the server will wait for the client requests to come

    // assign serv_addr to the listenfd
    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(listenfd, 10);

    while (1)
    {
        // waiting for an incoming client request then returns the socket descriptor representing the client socket
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

        ticks = time(NULL);
        snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));
        write(connfd, sendBuff, strlen(sendBuff)); 

        close(connfd);
        sleep(1);
    }
}

