//Rohit Thapar
//102003482
//3CO19


#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <arpa/inet.h>
#define MAX 80
#define PORT 43454
#define SA struct sockaddr

int main()
{
int sockfd;
struct sockaddr_in servaddr;
sockfd=socket(AF_INET,SOCK_DGRAM,0);   // create socket
if(sockfd==-1)
{
printf("socket creation failed...\n");
exit(0);
}
else
printf("Socket successfully created..\n");
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("172.16.95.255");
servaddr.sin_port=htons(PORT);
int sockopt = setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &servaddr, sizeof(servaddr));

char buff[MAX];
int n,clen;
struct sockaddr_in cli;
clen=sizeof(cli);
// if(strncmp("exit",buff,4)==0)
// {
// printf("Server Exit...\n");
// break;
// }
// int len = 
bzero(buff,MAX);
n=0;
while((buff[n++]=getchar())!='\n');
sendto(sockfd,buff,sizeof(buff),0,(SA *)&servaddr,sizeof(servaddr));
// if(strncmp("exit",buff,4)==0)
// {
// printf("Server Exit...\n");
// break;
// }
close(sockfd);
}