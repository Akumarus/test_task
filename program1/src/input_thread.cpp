#include "input_thread.h"
#include "data_process.h"
#include <iostream>
#include <thread>

input_thread::input_thread(buffer &buf) : buf(buf) {}

void input_thread::read_data()
{
    while(true)
    {
        std::string input;
        std::cout << "Enter string (number only, less then 64 characters)\t: ";
        std::cin >> input;

        if(data_process::is_valid_input(input))
        {
            std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
            std::string processed = data_process::process_input(input);
            std::cout << "Data sent to buffer: " << std::endl;
            buf.add_data(processed);
        }
        else
        {
            std::cout << "Incorrect input (Use number, maximum input no more than 64 characters)" << std::endl;
        }
    }
}