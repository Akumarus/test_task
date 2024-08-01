
#include "socket.h"

Socket::Socket(int PORT, const char* SERVER_IP) : sock(socket(AF_INET, SOCK_STREAM, 0))
{   
    if(sock < 0)
        throw std::runtime_error("Socket creation failed");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr);

}

Socket::~Socket()
{
    if(sock >= 0)
        close(sock);
}

bool Socket::connect(struct sockaddr_in &addr)
{
    if(::connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        return 0;

    return 1;
}

bool Socket::send(std::string &data)
{   
    if (sock < 0)
        return false;

    if(::send(sock, data.c_str(), data.length(), 0) < 0)
    {
        close(sock);
        sock = - 1;
        return false;
    }
    
    return true;
}

