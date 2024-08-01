#ifndef OUTPUT_THREAD_H
#define OUTPUT_THREAD_H

#include "buffer.h"
#include "socket.h"

class Output_thread
{
private:
    Buffer &buffer;
    Socket &socket;
public:
    Output_thread(Buffer &buffer, Socket &socket);
    void send_data();
};

#endif // OUTPUT_THREAD_H