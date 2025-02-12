#ifndef SOCKET_H
#define SOCKET_H

#include <iostream>
#include <string> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class Socket
{
private:
    int sock;
    
public:
    struct sockaddr_in serv_addr;

    Socket(int PORT, const char* SERVER_IP);
    ~Socket();

    bool connect(struct sockaddr_in &addr);
    bool send(std::string &data);
};

#endif // SOCKET_H