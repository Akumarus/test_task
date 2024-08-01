#include "output_thread.h"
#include "data_process.h"
#include <iostream>


Output_thread::Output_thread(Buffer &buffer, Socket &socket) : buffer(buffer), socket(socket) {}

void Output_thread::send_data()
{
    while(true)
    {
        if(!socket.connect(socket.serv_addr))
            std::cout << "Connection failed" << std::endl;

    while(true)
    {
        std::string data = buffer.get_data();

        if(data.empty()) break;
        
        int sum = Data_process::calculate_sum(data);
        std::cout << "Converted data: " << data << std::endl;
        std::cout << "Sum of numeric data: " << sum << std::endl;

        std::string send_data = std::to_string(sum);
        if(!socket.send(send_data))
            std::cout << "Send failed, attempting to reconnect... " << sum << std::endl;
        else
            std::cout << "Sent data: " << sum << std::endl;
    }
    }
}

