

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// libray for socket programming functions
#include <arpa/inet.h>

int main()
{
    // defining ip and port no
    char *ip = "127.0.0.1";
    int port = 5566;

    int server_sock, client_sock;
    // Induld fucntions to access
    struct sockaddr_in server_addr, client_addr;
    // socket lenght function
    socklen_t addr_size;
    char buffer[1024];
    int n;
    // declaring socket
    // returns the file descriptor or return -1 if the error has occured
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0)
    {
        perror("[-]Socket error");
        exit(1);
    }
    printf("[+]TCP server socket created.\n");
    // set all the elements of the server_adder array to
    memset(&server_addr, '\0', sizeof(server_addr));
    // assigning server a port and ip adreesss
    // logical sdress declare kiye
    server_addr.sin_family = AF_INET; // ipv4
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    // bind code
    // logical adress me assign karra
    n = bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (n < 0)
    {
        perror("[-]Bind error");
        exit(1);
    }
    printf("[+]Bind to the port number: %d\n", port);
    // 5 is a limit of request in queue
    listen(server_sock, 5);
    printf("Listening...\n");
    // inifitintly wait
    while (1)
    {
        addr_size = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size);
        printf("[+]Client connected.\n");

        bzero(buffer, 1024);
        recv(client_sock, buffer, sizeof(buffer), 0);
        printf("Client: %s\n", buffer);

        bzero(buffer, 1024);
        strcpy(buffer, "HI, THIS IS SERVER. HAVE A NICE DAY!!!");
        printf("Server: %s\n", buffer);
        send(client_sock, buffer, strlen(buffer), 0);

        close(client_sock);
        printf("[+]Client disconnected.\n\n");
    }

    return 0;
}

/**
mitesh@LAPTOP-E7OVG5CT:~/cncode$ gcc Server.c
mitesh@LAPTOP-E7OVG5CT:~/cncode$ gcc Server.c -o Server
mitesh@LAPTOP-E7OVG5CT:~/cncode$ ./Server
[+]TCP server socket created.
[+]Bind to the port number: 5566
Listening...
[+]Client connected.
Client: HELLO, THIS IS CLIENT.
Server: HI, THIS IS SERVER. HAVE A NICE DAY!!!
[+]Client disconnected.
*/
