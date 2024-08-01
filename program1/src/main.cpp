
#include "input_thread.h"
#include "output_thread.h"
#include "buffer.h"
#include <thread>


#define PORT 1243
#define SERVER_IP "127.0.0.1"

int main() {

    /* 
        1. Input thread read data from console and send it to buufer;
        2. Output thread read data from buffer and send it with socket to program2;
    */

    Buffer buffer;
    Socket socket(PORT, SERVER_IP);

    Input_thread input_thread(buffer);
    Output_thread output_thread(buffer, socket);

    std::thread t1(&Input_thread::read_data, &input_thread);
    std::thread t2(&Output_thread::send_data, &output_thread);

    t1.join();
    t2.join();

    return 0;
}