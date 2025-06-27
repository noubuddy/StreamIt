#include "logger.h"

#include <stdio.h>

STRING verbosity_to_string(e_log_verbosity t_verbosity) {
    switch (t_verbosity) {
        case LOG_DEBUG:
            return "DEBUG";
        case LOG_INFO:
            return "INFO";
        case LOG_WARNING:
            return "WARNING";
        case LOG_ERROR:
            return "ERROR";
        case LOG_FATAL:
            return "FATAL";
        default:
            return "UNKNOWN";
    }
}

void print_log(STRING t_message, e_log_verbosity t_verbosity) {
    printf("[%s] %s\n", verbosity_to_string(t_verbosity), t_message);
}
