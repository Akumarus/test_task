#ifndef INPUT_THREAD_H
#define INPUT_THREAD_H

#include "buffer.h"

class input_thread
{
private:
    buffer &buf;
public:
    input_thread(buffer &buf);
    void read_data();
};

#endif // INPUT_THREAD_H