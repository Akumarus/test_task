#ifndef INPUT_THREAD_H
#define INPUT_THREAD_H

#include "buffer.h"

class Input_thread
{
private:
    Buffer &buffer;
public:
    Input_thread(Buffer &buffer);
    void read_data();
};

#endif // INPUT_THREAD_H