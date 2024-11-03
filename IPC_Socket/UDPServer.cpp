#include<iostream>
#include<cstring>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

using namespace std;

int main(int argc, char **argv) {
    int server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_fd == -1) {
        cerr << "Create socket error" << endl;
        return -1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(6678);
    int ret = bind(server_fd, (struct sockaddr *)&serverAddr, (socklen_t)sizeof(serverAddr));
    if (ret == -1) {
        cerr << "Bind socket error" << endl;
        close(server_fd);
        return -1;
    }

    signal(SIGCHLD, SIG_IGN);
    char buff[256];
    memset(buff, 0, sizeof(buff));
    while (true) {
        struct sockaddr_in clientAddr;
        socklen_t clientAddrSz = sizeof(clientAddr);
        ssize_t readSz = recvfrom(server_fd, buff, sizeof(buff)-1, 0, (struct sockaddr *)&clientAddr, &clientAddrSz);
        if (readSz <= 0) {
            cerr << "Recvfrom socket error" << endl;
            continue;
        }

        switch (fork()) {
        case -1:
            cerr << "Fork thread error" << endl;
            continue;
        case 0:
            buff[readSz] = '\0';
            cout << "Recvfrom socket succ. readSz=" << readSz << " data=" << buff << endl;
            strcpy(buff, "I am server\0");
            sendto(server_fd, buff, strlen(buff), 0, (struct sockaddr *)&clientAddr, clientAddrSz);
            exit(0);
            break;
        default:
            break;
        }
    }

    close(server_fd);
    return 0;
}