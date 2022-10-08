#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include <arpa/inet.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
int main()
{
char str[100];
char sendline[100];
int listen_fd, comm_fd,i;
struct sockaddr_in servaddr;
listen_fd = socket(AF_INET, SOCK_STREAM, 0);
bzero( &servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(22000);
i = bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
if(i==-1)
printf("Bind Failed");
listen(listen_fd, 10);
comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
while(1)
{
bzero( str, 100);
recv(comm_fd,str,100,0);
if(strncmp(str,"e",1)==0)
break;
printf("Client: %s",str);
bzero(sendline, 100);
fgets(sendline,100,stdin);

// printf("Echoing back - %s",str);
send(comm_fd,sendline,strlen(sendline),0);

}
close(comm_fd);

}