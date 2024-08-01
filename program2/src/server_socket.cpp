
#include "server_socket.h"

Server_socket::Server_socket(int PORT) : sock(socket(AF_INET, SOCK_STREAM, 0))
{
    if(sock < 0) 
        throw std::runtime_error("Socket creation failed");
    
    int opt = 1;
    if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        throw std::runtime_error("setsockopt failed");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if(bind(sock, (struct sockaddr *)&serv_addr, addrlen) < 0)
        throw std::runtime_error("Bind failed");

    if(listen(sock, 3) < 0) 
        throw std::runtime_error("Listen failed");
}

Server_socket::~Server_socket()
{
    if(sock >= 0)
        close(sock);
}

int Server_socket::accept_connection()
{
    int new_socket;
    if ((new_socket = accept(sock, (struct sockaddr *)&serv_addr, (socklen_t*)&addrlen)) < 0)
        throw std::runtime_error("Accept failed");

    return new_socket;
}