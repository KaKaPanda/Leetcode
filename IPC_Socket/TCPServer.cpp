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
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        cerr << "Create socket error" << endl;
        return -1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(6677);
    int ret = bind(server_fd, (struct sockaddr *)&serverAddr, (socklen_t)sizeof(serverAddr));
    if (ret == -1) {
        cerr << "Bind socket error" << endl;
        close(server_fd);
        return -1;
    }

    ret = listen(server_fd, 5);
    if (ret == -1) {
        cerr << "Listen socket error" << endl;
        close(server_fd);
        return -1;
    }

    signal(SIGCHLD, SIG_IGN);
    char buff[256];
    memset(buff, 0, sizeof(buff));
    ssize_t readSz = 0;
    while (true) {
        struct sockaddr_in clientAddr;
        socklen_t clientAddrSz = sizeof(clientAddr);
        int client_fd = accept(server_fd, (struct sockaddr *)&clientAddr, &clientAddrSz);
        if (client_fd == -1) {
            cerr << "Accept socket error" << endl;
            continue;
        }

        switch (fork()) {
        case -1:
            cerr << "Fork thread error" << endl;
            close(client_fd);
            continue;
        case 0:
            readSz = read(client_fd, buff, sizeof(buff)-1);
            if (readSz <= 0) {
                cerr << "Read socket error" << endl;
            } else {
                buff[readSz] = '\0';
                cout << "Read socket succ. readSz=" << readSz << " data=" << buff << endl;
                strcpy(buff, "I am server\0");
                write(client_fd, buff, strlen(buff));
                close(client_fd);
                exit(0);
            }
            break;
        default:
            close(client_fd);
            break;
        }
    }

    close(server_fd);
    return 0;
}