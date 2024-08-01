#include "data_process.h"
#include <algorithm>

bool Data_process::is_valid_input(const std::string &input)
{
    if(input.length() > 64) return false;
    
    return std::all_of(input.begin(), input.end(), ::isdigit);
}

std::string Data_process::process_input(const std::string &input)
{
    std::string sorted_input = input;
    sort(sorted_input.begin(), sorted_input.end(), std::greater<char>());

    for(size_t i = 0; i < sorted_input.size(); i++)
    {
        if((sorted_input[i] - '0') % 2 == 0)
        {
            sorted_input[i] = 'K';
            sorted_input.insert(i + 1, 1, 'B');
            i++;
        }
    }

    return sorted_input;
}

int Data_process::calculate_sum(const std::string &data)
{
    int sum = 0;
    for(char c : data)
    {
        if(isdigit(c))
        {
            sum += c - '0';
        }
    }
    
    return sum;
}
