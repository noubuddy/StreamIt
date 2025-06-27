#include "memory.h"

#include <string.h>

void wipemem(void* t_dst, sz t_size) {
    memset(t_dst, 0, t_size);
}