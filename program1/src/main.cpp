
#include "input_thread.h"
#include "output_thread.h"
#include "buffer.h"
#include "socket.h"
#include <thread>


#define PORT 1244
#define SERVER_IP "127.0.0.1"

int main() {

    buffer buf;
    Socket socket;
    
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr);
    
    socket.connect(serv_addr);

    input_thread input(buf);
    output_thread output(buf, socket);

    std::thread t1(&input_thread::read_data, &input);
    std::thread t2(&output_thread::send_data, &output);

    t1.join();
    t2.join();

    return 0;
}