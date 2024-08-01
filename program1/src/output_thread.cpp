#include "output_thread.h"
#include "data_process.h"
#include <iostream>


output_thread::output_thread(buffer &buf, Socket &socket) : buf(buf), socket(socket) {}

void output_thread::send_data()
{
    while(true)
    {
        std::string data = buf.get_data();

        if(data.empty()) break;
        
        int sum = data_process::calculate_sum(data);
        std::cout << "Converted data: " << data << std::endl;
        std::cout << "Sum of numeric data: " << sum << std::endl;

        std::string send_data = std::to_string(sum);
        socket.send(send_data);
        std::cout << "Sent data: " << sum << std::endl;
    }

}

