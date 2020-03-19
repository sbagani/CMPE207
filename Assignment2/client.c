#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<stdlib.h>
#define SIZE 20000
#define PORT 3000

int main(int argc, char const *argv[])
{
    int sockId=0;
    struct sockaddr_in server_address;
    struct hostent *server;
    char *reply = malloc(sizeof(char)*SIZE);

    sockId=socket(AF_INET, SOCK_STREAM, 0);
    if(sockId < 0)
    {
        printf("There was an error in socket creation");
        return -1;
    }
    bzero((char*) &server_address,sizeof(server_address));
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(PORT);
    server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(connect(sockId, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("There was a connection failure");
        return -1;
    }
     while(1)
    {
        bzero((char*)reply,SIZE);
        int result=recv(sockId,(void *)reply,SIZE,0);

    	if(result < 0)
    	{
        	puts("Receive failed");
            return -1;
    	}
        else if(result == 0)
        {
            puts("The source shutdown");
            return -1;
        }
        reply[result]='\0';
        fputs(reply, stdout);
        fflush(stdout);
    }
    return 0;
}
