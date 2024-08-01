#include "input_thread.h"
#include "data_process.h"
#include <iostream>
#include <thread>

Input_thread::Input_thread(Buffer &buffer) : buffer(buffer) {}

void Input_thread::read_data()
{
    while(true)
    {
        std::string input;
        std::cout << "Enter string (number only, less then 64 characters)\t: ";
        std::cin >> input;

        if(Data_process::is_valid_input(input))
        {
            std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
            std::string processed = Data_process::process_input(input);
            std::cout << "Data sent to buffer: " << std::endl;
            buffer.add_data(processed);
        }
        else
        {
            std::cout << "Incorrect input (Use number, maximum input no more than 64 characters)" << std::endl;
        }
    }
}