#include <iostream>
#include "server_socket.h"

#define PORT 1243

int main() {

    Server_socket server(PORT);
    char buffer[1024] = {0};

    while (true) {

        std::cout << "Waiting for a new connection..." << std::endl;
        int socket = server.accept_connection();
        std::cout << "Connection accepted!" << std::endl;

        while (true) {
           int bytes_received = read(socket,buffer, sizeof(buffer) - 1);
           if (bytes_received <= 0) {
               std::cerr << "Connection closed or error occurred." << std::endl;
               close(socket);
               break;
           }

            buffer[bytes_received] = '\0';
            
            std::string data(buffer);
            int length = data.length();

            if(length > 2 && length % 32 == 0)
            {
                std::cout << "DATA OK" << "Received data: " << buffer << std::endl;

            }
            else
            {
                std::cout << "DATA ERROR " << "Received: " << buffer << std::endl;
                std::cerr << "Data is either less than 2 characters or not a multiple of 32." << std::endl;
            }
        }
    }

    return 0;
}