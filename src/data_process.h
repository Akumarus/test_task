#ifndef DATA_PROCESS_H
#define DATA_PROCESS_H

#include <string>

class data_process
{
private:
    /* data */
public:
    static bool is_valid_input(const std::string &input);
    static std::string process_input(const std::string &input);
    static int calculate_sum(const std::string &data);
};

#endif // DATA_PROCESS_H