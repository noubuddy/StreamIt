#include "core.h"
#include "logger.h"

#ifdef WIN32
#include "platform/win64/sockets.h"
#endif

e_result init_sockets() {

#ifdef WIN32
    s_winsock_version version = {2, 2};
    i32 result = init_winsock(version);
    if (result != 0) {
        LOG_FATAL("Failed to initialize WinSock");
        return RESULT_FAILURE;
    }
#endif

    return RESULT_SUCCESS;
}
