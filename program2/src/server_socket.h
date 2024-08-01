#ifndef SOCKET_H
#define SOCKET_H

#include <iostream>
#include <string> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class Server_socket
{
private:
    int sock;
    struct sockaddr_in serv_addr;
    int addrlen = sizeof(serv_addr);
public:
    Server_socket(int PORT);
    ~Server_socket();

    int accept_connection();
};

#endif // SOCKET_H