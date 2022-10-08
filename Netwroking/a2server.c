#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h> //used for tcp ip functions
#include <stdio.h>
#include<string.h>
int main()
{
char str[100];
int listen_fd, comm_fd;
struct sockaddr_in servaddr;
listen_fd = socket(AF_INET, SOCK_STREAM, 0);
bzero( &servaddr, sizeof(servaddr)); // erases the data in the n bytes of memory
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(22000);
bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
listen(listen_fd, 10);

while(1)
{
comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
bzero( str, 100);
recv(comm_fd,str,100,0);
printf("Echoing back - %s",str);
send(comm_fd,str,strlen(str),0);
close(comm_fd);

}
}

// #include <netinet/in.h>

// struct sockaddr_in {
//     short            sin_family;   // e.g. AF_INET
//     unsigned short   sin_port;     // e.g. htons(3490)
//     struct in_addr   sin_addr;     // see struct in_addr, below
//     char             sin_zero[8];  // zero this if you want to
// };

// struct in_addr {
//     unsigned long s_addr;  // load with inet_aton()
// };