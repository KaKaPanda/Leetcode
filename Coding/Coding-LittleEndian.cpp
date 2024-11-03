// 指针强制转换
bool is_little_endian() {
    int x = 0x01;
    char* p = (char*)(&x);
    return (*p) == 1;
}


// union 联合体检测
bool is_little_endian() {
    union {
        unsigned int num;
        unsigned char byte; 
    } u;

    u.num = 0x01;
    return u.byte == 0x01;
}

// 网络序转换检测
#include <arpa/inet.h>
bool is_little_endian() {
    int x = 0x01;
    return htons(x) != 0x01;
}