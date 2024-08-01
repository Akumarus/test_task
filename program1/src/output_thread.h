#ifndef OUTPUT_THREAD_H
#define OUTPUT_THREAD_H

#include "buffer.h"
#include "socket.h"

class output_thread
{
private:
    buffer &buf;
    Socket &socket;
public:
    output_thread(buffer &buf, Socket &socket);
    void send_data();
};

#endif // OUTPUT_THREAD_H