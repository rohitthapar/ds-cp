//Rohit Thapar
//102003482
//3CO19

#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#define MAX 80
#define PORT 43454
#define SA struct sockaddr
int main()
{
char buff[MAX];
int sockfd,len,n;
struct sockaddr_in servaddr;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd==-1)
{
printf("socket creation failed...\n");
exit(0);
}
else
printf("Socket successfully created..\n");

bzero(&servaddr,sizeof(len));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(PORT);
// int sockopt = setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &servaddr, sizeof(servaddr));
len=sizeof(servaddr);
if((bind(sockfd,(SA *)&servaddr,sizeof(servaddr)))!=0)
{
printf("socket bind failed...\n");
exit(0);
}
// printf("\nEnter : ");
// n=0;
// while((buff[n++]=getchar())!='\n');
// sendto(sockfd,buff,sizeof(buff),0,(SA *)&servaddr,len);
// if(strncmp("exit",buff,4)==0)
// {
// printf("Client Exit...\n");
// exit(0);
// break;
// }



bzero(buff,sizeof(buff));
recvfrom(sockfd,buff,100,0,(SA *)&servaddr,&len);
// printf("%d",x);
printf("From Server : %s\n",buff);

close(sockfd);
}