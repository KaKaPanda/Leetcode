#include<iostream>
#include<cstring>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

using namespace std;

int main(int argc, char **argv) {
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1) {
        cerr << "Create socket error" << endl;
        return -1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(6677);
    int ret = connect(client_fd, (struct sockaddr *)&serverAddr, (socklen_t)sizeof(serverAddr));
    if (ret == -1) {
        cerr << "Connect socket error" << endl;
        close(client_fd);
        return -1;
    }

    char buff[256];
    memset(buff, 0, sizeof(buff));
    strcpy(buff, "I am client\0");
    ret = write(client_fd, buff, strlen(buff));
    if (ret == -1) {
        cerr << "Write socket error" << endl;
        close(client_fd);
        return -1;
    }

    ssize_t readSz = read(client_fd, buff, sizeof(buff)-1);
    if (readSz <= 0) {
        cerr << "Read socket error" << endl;
        close(client_fd);
        return -1;
    } else {
        buff[readSz] = '\0';
        cout << "Read socket succ. readSz=" << readSz << " data=" << buff << endl;
    }

    close(client_fd);
    return 0;
}