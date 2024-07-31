#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <stdexcept>
#include <signal.h>

#define PORT 1244

// Класс для управления серверным сокетом
class ServerSocket {
public:
    ServerSocket() : server_fd(socket(AF_INET, SOCK_STREAM, 0)) {
        if (server_fd == 0) {
            throw std::runtime_error("Socket creation failed");
        }

        int opt = 1;
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
            throw std::runtime_error("setsockopt failed");
        }

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(PORT);

        if (bind(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            throw std::runtime_error("Bind failed");
        }

        if (listen(server_fd, 3) < 0) {
            throw std::runtime_error("Listen failed");
        }
    }

    ~ServerSocket() {
        if (server_fd >= 0) {
            close(server_fd);
        }
    }

    int acceptConnection() {
        int new_socket;
        if ((new_socket = accept(server_fd, (struct sockaddr *)&serv_addr, (socklen_t*)&addrlen)) < 0) {
            throw std::runtime_error("Accept failed");
        }
        return new_socket;
    }

private:
    int server_fd;
    struct sockaddr_in serv_addr;
    int addrlen = sizeof(serv_addr);
};

// Обработка сигналов для корректного завершения программы
void handle_signal(int signal) {
    std::cerr << "Signal " << signal << " received, exiting..." << std::endl;
    exit(1);
}

int main() {
    // Устанавливаем обработчики сигналов
    signal(SIGINT, handle_signal);  // Обработка Ctrl+C (SIGINT)
    signal(SIGTERM, handle_signal); // Обработка сигнала завершения (SIGTERM)

    try {
        ServerSocket server;
        char buffer[1024] = {0};

        while (true) {
            std::cout << "Waiting for a new connection..." << std::endl;
            int new_socket = server.acceptConnection();
            std::cout << "Connection accepted!" << std::endl;

            while (true) {
                int valread = read(new_socket, buffer, sizeof(buffer) - 1);
                if (valread <= 0) {
                    std::cerr << "Connection closed or error occurred." << std::endl;
                    close(new_socket);
                    break;
                }

                buffer[valread] = '\0'; // Null-terminate the received data
                std::cout << "Received: " << buffer << std::endl;
            }
        }

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}