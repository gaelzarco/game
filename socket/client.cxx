#include <netinet/in.h>     // Internet address structures and constants
#include <sys/socket.h>     // Core socket API
#include <unistd.h>         // POSIX system calls
#include <cstring>

int main(void) {
    // File descriptor
    //  - AF_INET = IPv4
    //  - SOCK_STREAM = Stream Sockets (TCP)
    //  - 0 = OS chooses protocol (TCP)
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Server address
    sockaddr_in server_address;                         // IPv4 Address
    server_address.sin_family = AF_INET;                // Match address family
    server_address.sin_port = htons(8080);              // Port number
    server_address.sin_addr.s_addr = INADDR_ANY;        // Bind to all NIs (0.0.0.0)

    // Send connection request
    connect(client_socket, (struct sockaddr*)&server_address,
        sizeof(server_address)
    );
    
    const char* msg = "Hello, server!";
    // Send message to server
    send(client_socket, msg, strlen(msg), 0);

    // Close file descriptor and release OS resources
    close(client_socket);

    return 0;
}
