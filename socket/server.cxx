#include <netinet/in.h>     // Internet address structures and constants
#include <sys/socket.h>     // Core socket API
#include <unistd.h>         // POSIX System calls
#include <print>

int main(void) {
    // File descriptor
    //  - AF_INET = IPv4
    //  - SOCK_STREAM = Stream Sockets (TCP; Datagram Sockets UDP)
    //  - 0 = OS chooses protocol (TCP)
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Server address
    sockaddr_in server_address;                         // IPv4 Address
    server_address.sin_family = AF_INET;                // Match address family
    server_address.sin_port = htons(8080);              // Port number
    server_address.sin_addr.s_addr = INADDR_ANY;        // Bind to all NIs (0.0.0.0)

    // Bind socket to IP address and [port
    bind(server_socket, (struct sockaddr*)&server_address,
        sizeof(server_address));

    // Socket is ready to accept connections
    listen(server_socket, 5);

    // Blocks until a client connects
    //  - Creates a new socket for that client and keeps previous one open for
    //    future connections
    int client_socket = accept(server_socket, nullptr, nullptr);

    // Receive buffer; 0 initialized
    char buffer[1024] = {0};
    // Read bytes sent by client
    recv(client_socket, buffer, sizeof(buffer), 0);

    std::println("[LOG] Message from client: '{}'", buffer);

    // Closes the file descriptor and releases OS resources
    close(client_socket);
    close(server_socket);

    return 0;
}
