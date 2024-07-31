#include "buffer.h"

void buffer::add_data(const std::string &data)
{
    std::unique_lock<std::mutex> lock(mtx);
    buf.push(data);
    data_ready = true;
    cv.notify_one();
}

std::string buffer::get_data()
{
    std::unique_lock<std::mutex>lock(mtx);
    cv.wait(lock, [this] {return data_ready; });

    std::string data = buf.front();
    buf.pop();
    data_ready = false;
    return data;
}