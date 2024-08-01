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
    Socket();
    ~Socket();

    void connect(struct sockaddr_in &addr);
    void send(std::string &data);
};

#endif // SOCKET_H