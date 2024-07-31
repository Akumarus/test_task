#ifndef OUTPUT_THREAD_H
#define OUTPUT_THREAD_H

#include "buffer.h"

class output_thread
{
private:
    buffer buf;
public:
    output_thread(buffer &buf);
    void send_data();
};

#endif // OUTPUT_THREAD_H