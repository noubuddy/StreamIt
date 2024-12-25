#include "StreamIt.h"

#include <ws2tcpip.h>
#include <ws2def.h>

// private members start

int get_addr_info(STRING serv_addr, STRING serv_port,  const ADDRINFOA* hints,  PADDRINFOA* result)
{
    return getaddrinfo(serv_addr, serv_port, hints, result);
}

SOCKET create_socket(int family, int socket_type, int protocol)
{
    return socket(family, socket_type, protocol);
}

int bind_socket(SOCKET socket, s_socket_address* socket_address, int length)
{
    // TODO: serialize socket_address
    return bind(socket, socket_address, length);
}

int listen_socket(unsigned long long socket, int backlog)
{
    return listen(socket, backlog);
}

SOCKET accept_socket(SOCKET socket, s_socket_address* socket_address, int* address_length)
{
    // TODO: serialize socket_address
    return accept(socket, socket_address, address_length);
}

int kill_socket(SOCKET socket, int signal)
{
    return shutdown(socket, signal);
}

int receive_socket(SOCKET socket, char* buffer, int length, int flags)
{
    return recv(socket, buffer, length, flags);
}

int send_socket(SOCKET socket, char* buffer, int length, int flags)
{
    return send(socket, buffer, length, flags);
}

void get_conn_props(struct addrinfo* addr_info, s_connection_props* conn_props)
{
    conn_props->flags = addr_info->ai_flags;
    conn_props->family = addr_info->ai_family;
    conn_props->socket_type = addr_info->ai_socktype;
    conn_props->protocol = addr_info->ai_protocol;
}

void get_socket_addr(struct sockaddr* in_socket_addr, s_socket_address* out_socket_addr)
{
    out_socket_addr->family = in_socket_addr->sa_family;
    *out_socket_addr->data = *in_socket_addr->sa_data;
}

// private members end

e_connection_status open_connection(STRING serv_addr, STRING serv_port, s_connection_props* conn_props)
{
    struct addrinfo* conn_result = NULL;
    struct addrinfo hints;
    
    const int result = get_addr_info(serv_addr, serv_port, &hints, &conn_result);
    if (result == 0)
    {
        return CONNECTION_FAILURE;
    }
    
    s_connection_props l_conn_props;
    get_conn_props(conn_result, &l_conn_props);
    
    
    return CONNECTION_SUCCESS;
}
