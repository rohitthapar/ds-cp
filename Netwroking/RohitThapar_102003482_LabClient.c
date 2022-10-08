#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include <arpa/inet.h>
#include <fcntl.h> 
#include <unistd.h> 

void board(char square[])
{
    // system("cls");
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);
    printf("     |     |     \n\n");
}
int checkwin(char square[])
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return  - 1;
}
int main(int argc,char **argv)
{
    int sockfd,n;
    char sendline[100];
    char recvline[100];
    struct sockaddr_in saddr;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    bzero(&saddr,sizeof saddr);
    saddr.sin_family=AF_INET;
    saddr.sin_port=htons(22000);
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//inet_pton(AF_INET,"127.0.0.1",&(servaddr.sin_addr));
    connect(sockfd,(struct sockaddr *)&saddr,sizeof(saddr));
    while(1)
    {
        bzero( sendline, 100);
        bzero( recvline, 100);
        printf("Enter Client Move: ");
        fgets(sendline,100,stdin); /*stdin = 0 , for standard input */
        send(sockfd,sendline,strlen(sendline),0);
        recv(sockfd,recvline,100,0);
        board(recvline);
        // int nm = checkwin(recvline);
        // if(nm == 1) {
        //     printf("Client Win");
        //     break;
        // }
        if(strncmp(sendline,"exit",4)==0)
        break;
        // for(int i=0;i<strlen(recvline);i++){
        //     printf("%c ",recvline[i]);
        // }

        // printf("Server Move: %s",recvline);
        if(checkwin(recvline) == 1) {
            printf("Server Win");
            break;
        }
        else if(checkwin(recvline) == 0) {
            printf("Server Lost");
            break;
            }

}
}

