#pragma once
#ifndef CORE_WIN64_H
#define CORE_WIN64_H

#include "types.h"

typedef enum e_connection_status
{
    CONNECTION_SUCCESS = 0,
    CONNECTION_FAILURE
} e_connection_status;

typedef struct s_connection_props
{
    i32 family;
    i32 socket_type;
    i32 protocol;
    i32 flags;
} s_connection_props;

typedef struct s_socket_address
{
    u16 family;
    byte data[14];
} s_socket_address;

typedef struct s_winsock_version {byte major, minor;} s_winsock_version;

i32 init_winsock(s_winsock_version t_version);

e_connection_status open_connection(STRING serv_addr, STRING serv_port, s_connection_props* conn_props);

#endif //CORE_WIN64_H