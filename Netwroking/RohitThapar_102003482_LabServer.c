#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; 

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

int main(){
    char str[100];
    char sendline[100];
    int listen_fd, comm_fd,i;
    struct sockaddr_in saddr;
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    bzero( &saddr, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(22000);
    i = bind(listen_fd, (struct sockaddr *) &saddr, sizeof(saddr));
    if(i==-1)
    printf("Bind Failed");
    else printf("Bind Successful \n");
    listen(listen_fd, 10);
    comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
    while(1)
    {
        bzero( str, 100);
        recv(comm_fd,str,100,0);
        if(strncmp(str,"exit",4)==0)
        break;
        if(strncmp(str,"1",1)==0) square[1] = 'X';
        if(strncmp(str,"2",1)==0) square[2] = 'X';
        if(strncmp(str,"3",1)==0) square[3] = 'X';
        if(strncmp(str,"4",1)==0) square[4] = 'X';
        if(strncmp(str,"5",1)==0) square[5] = 'X';
        if(strncmp(str,"6",1)==0) square[6] = 'X';
        if(strncmp(str,"7",1)==0) square[7] = 'X';
        if(strncmp(str,"8",1)==0) square[8] = 'X';
        if(strncmp(str,"9",1)==0) square[9] = 'X';

        int nm = checkwin(square);
        if(nm == 1) {
            printf("Client Win");
            break;
        }
        else if(nm == 0){
            printf("Client Lost");
            break;
            }
        board(square);
        bzero(sendline, 100);
        printf("Enter Server Move ");
        fgets(sendline,100,stdin);
        // send(comm_fd,sendline,strlen(sendline),0);
        if(strncmp(sendline,"exit",4)==0)
        break;
        board(square);

        if(strncmp(sendline,"1",1)==0) square[1] = 'O';
        if(strncmp(sendline,"2",1)==0) square[2] = 'O';
        if(strncmp(sendline,"3",1)==0) square[3] = 'O';
        if(strncmp(sendline,"4",1)==0) square[4] = 'O';
        if(strncmp(sendline,"5",1)==0) square[5] = 'O';
        if(strncmp(sendline,"6",1)==0) square[6] = 'O';
        if(strncmp(sendline,"7",1)==0) square[7] = 'O';
        if(strncmp(sendline,"8",1)==0) square[8] = 'O';
        if(strncmp(sendline,"9",1)==0) square[9] = 'O';
        if(checkwin(square) == 1) {
            printf("Server Win");
            break;
        }
        else if(checkwin(square) == 0) {
            printf("Server Lost");
            break;
            }
        send(comm_fd,square,strlen(square),0);
}
close(comm_fd);

}
