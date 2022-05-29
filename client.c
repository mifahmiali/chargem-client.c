#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc, char *argv[]){

int sockClient ,port = 8000, status, countsend, countrecv;
struct sockaddr_in server;
char message[2000], receive[2000],temp;

sockClient = socket(AF_INET,SOCK_STREAM, 0);

 if(sockClient < 0){
  printf("ERROR !!! NO SOCKET RECEIVE\n");
}
else{
 printf("SOCKET CONNECTED SUCCESFULLY\n");
}
server.sin_family = AF_INET;
server.sin_addr.s_addr = inet_addr("192.16856.106");
server.sin_port=htons (port);

status = connect(sockClient, (struct sockaddr *)&server, sizeof(server));

 if(status == -1){
  printf("DOES NOT CONNECT!\n");
  perror("ERROR");
 }
 else{
  printf("CONNECTED SUCCESFULLY\n");
}

while(strncmp (receive, "STOP", 0) != 0){
 printf("From client:");
 scanf("%c",&temp);
 scanf("%[^\n]",message);
 
 countsend = send(sockClient, message, strlen(message), 0);
 
 memset(receive,0,1000);
 
 if(countsend < 0){
	printf("not enough!\n");
return 1;
}
	
countrecv = recv(sockClient, receive, 2000,0);

if(countrecv < 0){
printf("cannot receive \n");
}
printf("From Server: ");
puts(receive);
}
close(sockClient);
}
