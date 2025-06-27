#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

#include "types.h"

typedef enum e_log_verbosity {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_FATAL
} e_log_verbosity;

void print_log(STRING t_message, e_log_verbosity t_verbosity);

#define LOG_DEBUG(message) print_log(message, LOG_DEBUG);
#define LOG_INFO(message) print_log(message, LOG_INFO);
#define LOG_WARNING(message) print_log(message, LOG_WARNING);
#define LOG_ERROR(message) print_log(message, LOG_ERROR);
#define LOG_FATAL(message) print_log(message, LOG_FATAL);

#endif // LOGGER_H
