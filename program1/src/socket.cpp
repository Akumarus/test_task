
#include "socket.h"

Socket::Socket() : sock(socket(AF_INET, SOCK_STREAM, 0))
{
    if(sock < 0)
    {
        throw std::runtime_error("Socket creation failed");
    }
}

Socket::~Socket()
{
    if(sock >= 0)
    {
        close(sock);
    }
}

void Socket::connect(struct sockaddr_in &addr)
{
    if(::connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        throw std::runtime_error("Connection failed");
    }
}

void Socket::send(std::string &data)
{
    if(::send(sock, data.c_str(), data.length(), 0) < 0)
    {
        throw std::runtime_error("Send failed");
    }
}

