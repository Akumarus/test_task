#ifndef BUFFER_H
#define BUFFER_H

#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>

class Buffer
{
private:
    std::queue<std::string> buffer;
    std::mutex mtx;
    std::condition_variable cv;
    bool data_ready = false;
public:
    void add_data(const std::string &data);
    std::string get_data();
};

#endif // BUFFER_H