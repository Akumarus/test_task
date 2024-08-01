#include "buffer.h"

void Buffer::add_data(const std::string &data)
{
    std::unique_lock<std::mutex> lock(mtx);
    buffer.push(data);
    data_ready = true;
    cv.notify_one();
}

std::string Buffer::get_data()
{
    std::unique_lock<std::mutex>lock(mtx);
    cv.wait(lock, [this] {return data_ready; });

    std::string data = buffer.front();
    buffer.pop();
    data_ready = false;
    return data;
}