#include "output_thread.h"
#include "data_process.h"
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>

//output_thread::output_thread(buffer &buf) : buf(buf) {}

void output_thread::send_data()
{
    while(true)
    {
        std::string data = buf.get_data();
        std::cout << "Converted data: " << data << std::endl;

        int sum = data_process::calculate_sum(data);
        std::cout << "Sum of numeric data: " << sum << std::endl;
    }

}

