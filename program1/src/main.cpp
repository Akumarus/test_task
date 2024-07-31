#include <iostream>
#include <memory>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdexcept>
#include <signal.h>
#include <string>

#define PORT 1244
#define SERVER_IP "127.0.0.1"

// Класс для управления сокетом
class Socket {
public:
    Socket() : sock(socket(AF_INET, SOCK_STREAM, 0)) {
        if (sock < 0) {
            throw std::runtime_error("Socket creation failed");
        }
    }

    ~Socket() {
        if (sock >= 0) {
            close(sock);
        }
    }

    void connect(const struct sockaddr_in &addr) {
        if (::connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            throw std::runtime_error("Connection failed");
        }
    }

    void send(const std::string &data) {
        if (::send(sock, data.c_str(), data.length(), 0) < 0) {
            throw std::runtime_error("Send failed");
        }
    }

private:
    int sock;
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
        Socket socket;
        struct sockaddr_in serv_addr;

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);

        if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
            throw std::runtime_error("Invalid address");
        }

        socket.connect(serv_addr);

        std::string message = "55";
        while (true) {
            socket.send(message);
            std::cout << "Sent data: " << message << std::endl;
            sleep(1); // Задержка в 1 секунду
        }

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}