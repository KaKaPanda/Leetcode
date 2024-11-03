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
    int client_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_fd == -1) {
        cerr << "Create socket error" << endl;
        return -1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(6678);

    char buff[256];
    memset(buff, 0, sizeof(buff));
    strcpy(buff, "I am client\0");
    ssize_t sendSz = sendto(client_fd, buff, strlen(buff), 0, (struct sockaddr *)&serverAddr, (socklen_t)sizeof(serverAddr));
    cout << "Sendto socket succ. sendSz=" << sendSz << endl;

    ssize_t readSz = recvfrom(client_fd, buff, sizeof(buff), 0, 0, 0);
    if (readSz <= 0) {
        cerr << "Recvfrom socket error" << endl;
        return -1;
    } else {
        buff[readSz] = '\0';
        cout << "Recvfrom socket succ. readSz=" << readSz << " data=" << buff << endl;
    }

    close(client_fd);
    return 0;
}