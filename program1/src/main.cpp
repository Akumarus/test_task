#include "input_thread.h"
#include "output_thread.h"
#include "buffer.h"
#include <thread>


int main()
{
    buffer buf;
    input_thread input(buf);

    std::thread t1(&input_thread::read_data, &input);

    t1.join();

    return 0;
}