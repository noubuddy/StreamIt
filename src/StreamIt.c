#include "StreamIt.h"

#include <ws2tcpip.h>
#include <ws2def.h>

// private members start

// int get_addr_info(STRING serv_addr, STRING serv_port,  const ADDRINFOA* hints,  PADDRINFOA* ppResult)
// {
//     return getaddrinfo(serv_addr, serv_port, hints, ppResult);
// }
//
// void get_conn_props(struct addrinfo* addr_info, s_connection_props& conn_props)
// {
//     conn_props.flags = addr_info->ai_flags;
//     conn_props.family = addr_info->ai_family;
//     conn_props.socket_type = addr_info->ai_socktype;
//     conn_props.protocol = addr_info->ai_protocol;
// }

// private members end

// e_connection_status open_connection(STRING serv_addr, STRING serv_port, s_connection_props& conn_props)
// {
//     struct addrinfo* conn_result = NULL;
//     struct addrinfo hints;
//     
//     const int result = get_addr_info(serv_addr, serv_port, &hints, &conn_result);
//     if (result == 0)
//     {
//         return CONNECTION_FAILURE;
//     }
//     
//     s_connection_props l_conn_props;
//     get_conn_props(conn_result, l_conn_props);
//     
//     
//     return CONNECTION_SUCCESS;
// }
