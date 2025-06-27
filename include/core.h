#pragma once
#ifndef CORE_H
#define CORE_H

typedef enum e_result {
    RESULT_SUCCESS,
    RESULT_FAILURE,
} e_result;

e_result init_sockets();

#endif //CORE_H
