#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define SIZE 1024
#define BACKLOG 10 
int port = 45000; // default
char pathhtmlFile[2000]="index.html";
void report(struct sockaddr_in *serverAddress);
void setHttpHeader(char httpHeader[])
{
    FILE *htmlData = fopen(pathhtmlFile, "r");
    char line[100];
    char responseData[8000];
    while (fgets(line, 100, htmlData) != 0) {
        strcat(responseData, line);
    }
    strcat(httpHeader, responseData);
}

int main(void)
{

    char const* const fileName = "config.txt";

    FILE* file = fopen(fileName, "r"); 

    if(!file){
        printf("\n Unable to open : %s ", fileName);
    return -1;
    }

    char line[500];

    while (fgets(line, sizeof(line), file)) {
        if(line[0] == 'p' && line[1] == 'o')
        {
            char sub[2000];
            int c=0,position = 6;
            while (c < strlen(line)) {
                sub[c] = line[position+c-1];
                c++;
            }
            sub[c] = '\0';
            port = atoi(sub);
            printf("Port Number Updated to : %d\n",port);
        }
        else if(line[0] == 'p' && line[1] == 'a'){
            int c=0,position = 6;
            while (c < strlen(line)) {
                pathhtmlFile[c] = line[position+c-1];
                c++;
            }
            pathhtmlFile[c] = '\0';
            printf("Html file path Updated to : %s\n",pathhtmlFile);
        }
        
    }

    fclose(file);

    char httpHeader[8000] = "HTTP/1.1 200 OK\r\n\n";
    int serverSocket = socket(
        AF_INET,    
        SOCK_STREAM,  
        0            
    );

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    bind(
        serverSocket,                      
        (struct sockaddr *) &serverAddress, 
        sizeof(serverAddress)              
    );
    int listening = listen(serverSocket, BACKLOG);
    if (listening < 0) {
        printf("Error: The server is not listening.\n");
        return 1;
    }
    report(&serverAddress);   
    setHttpHeader(httpHeader); 
    int clientSocket;
    while(1) {
        clientSocket = accept(serverSocket, NULL, NULL);
        send(clientSocket, httpHeader, sizeof(httpHeader), 0);
        close(clientSocket);
    }
    return 0;
}

void report(struct sockaddr_in *serverAddress)
{
    char hostBuffer[INET6_ADDRSTRLEN];
    char serviceBuffer[NI_MAXSERV]; 
    socklen_t addr_len = sizeof(*serverAddress);
    int err = getnameinfo(
        (struct sockaddr *) serverAddress,
        addr_len,
        hostBuffer,
        sizeof(hostBuffer),
        serviceBuffer,
        sizeof(serviceBuffer),
        NI_NUMERICHOST
    );
    if (err != 0) {
        printf("It's not working!!\n");
    }
    printf("\n\n\tServer listening on http://%s:%s\n", hostBuffer, serviceBuffer);
}