#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include <unistd.h>
#include<stdlib.h>
#define PORT 3000

int main() 
{ 
    int sockfd=0, connfd, sent=0; 
    socklen_t len;
    struct sockaddr_in server_address, client; 
    char message[]="                                                                                                                                                                                                                                                                                                                                                                        dddddddd\nHHHHHHHHH     HHHHHHHHH                   lllllll lllllll                       WWWWWWWW                           WWWWWWWW                                 lllllll             d::::::d\nH:::::::H     H:::::::H                   l:::::l l:::::l                       W::::::W                           W::::::W                                 l:::::l             d::::::d\nH:::::::H     H:::::::H                   l:::::l l:::::l                       W::::::W                           W::::::W                                 l:::::l             d::::::d\nHH::::::H     H::::::HH                   l:::::l l:::::l                       W::::::W                           W::::::W                                 l:::::l             d:::::d \n  H:::::H     H:::::H      eeeeeeeeeeee    l::::l  l::::l    ooooooooooo         W:::::W           WWWWW           W:::::W ooooooooooo   rrrrr   rrrrrrrrr   l::::l     ddddddddd:::::d \n  H:::::H     H:::::H    ee::::::::::::ee  l::::l  l::::l  oo:::::::::::oo        W:::::W         W:::::W         W:::::Woo:::::::::::oo r::::rrr:::::::::r  l::::l   dd::::::::::::::d \n  H::::::HHHHH::::::H   e::::::eeeee:::::eel::::l  l::::l o:::::::::::::::o        W:::::W       W:::::::W       W:::::Wo:::::::::::::::or:::::::::::::::::r l::::l  d::::::::::::::::d \n  H:::::::::::::::::H  e::::::e     e:::::el::::l  l::::l o:::::ooooo:::::o         W:::::W     W:::::::::W     W:::::W o:::::ooooo:::::orr::::::rrrrr::::::rl::::l d:::::::ddddd:::::d \n  H:::::::::::::::::H  e:::::::eeeee::::::el::::l  l::::l o::::o     o::::o          W:::::W   W:::::W:::::W   W:::::W  o::::o     o::::o r:::::r     r:::::rl::::l d::::::d    d:::::d \n  H::::::HHHHH::::::H  e:::::::::::::::::e l::::l  l::::l o::::o     o::::o           W:::::W W:::::W W:::::W W:::::W   o::::o     o::::o r:::::r     rrrrrrrl::::l d:::::d     d:::::d \n  H:::::H     H:::::H  e::::::eeeeeeeeeee  l::::l  l::::l o::::o     o::::o            W:::::W:::::W   W:::::W:::::W    o::::o     o::::o r:::::r            l::::l d:::::d     d:::::d \n  H:::::H     H:::::H  e:::::::e           l::::l  l::::l o::::o     o::::o             W:::::::::W     W:::::::::W     o::::o     o::::o r:::::r            l::::l d:::::d     d:::::d \nHH::::::H     H::::::HHe::::::::e         l::::::ll::::::lo:::::ooooo:::::o              W:::::::W       W:::::::W      o:::::ooooo:::::o r:::::r           l::::::ld::::::ddddd::::::dd\nH:::::::H     H:::::::H e::::::::eeeeeeee l::::::ll::::::lo:::::::::::::::o               W:::::W         W:::::W       o:::::::::::::::o r:::::r           l::::::l d:::::::::::::::::d\nH:::::::H     H:::::::H  ee:::::::::::::e l::::::ll::::::l oo:::::::::::oo                 W:::W           W:::W         oo:::::::::::oo  r:::::r           l::::::l  d:::::::::ddd::::d\nHHHHHHHHH     HHHHHHHHH    eeeeeeeeeeeeee llllllllllllllll   ooooooooooo                    WWW             WWW            ooooooooooo    rrrrrrr           llllllll   ddddddddd   ddddd\n";
  
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&server_address, sizeof(server_address)); 
  
    // assign IP, PORT 
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(client); 
  
    // Accept the data packet from client and verification 
    while(1){
    connfd = accept(sockfd, (struct sockaddr *)&client, &len); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n"); 
  
    // Function for chatting between client and server 
   // func(connfd); 
  sent=send(connfd, message, strlen(message), 0);
  printf("Sent %d bytes to clinet: %s\n", sent, inet_ntoa(client.sin_addr));
    // After chatting close the socket 
   
    }
     close(sockfd); 
} 
