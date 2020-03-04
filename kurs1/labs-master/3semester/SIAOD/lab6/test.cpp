#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

int main()
{
    int sock, listener;
    struct sockaddr_in addr;
    char buf[1024];
    int bytes_read;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0) {
        std::cout << "error listen!";
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(7001);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        std::cout << "error bind";
    }

    listen(listener, 1);
    
    while(1) {
        sock = accept(listener, NULL, NULL);
        if(sock < 0) {
            std::cout << "error accept";
        }

        while(1) {
            bytes_read = recv(sock, buf, 1024, 0);
            if(bytes_read <= 0) break; 
            std::cout << "buf = " << buf;
            send(sock, buf, bytes_read, 0);
        }
    }
    
    return 0;
}