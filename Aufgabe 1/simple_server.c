#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define Port 12345  //Der Port, mit dem die Benutzer die Verbindung herstellen
int main(void) {
	int sockfd, new_sockfd;  //Warten an sockfd, neue Verbindung an new_sockfd
	socklen_t sin_size;
	int recv_length=1, yes=1, i=0;
	char buffer[1024];

	struct tm *newtime;
	time_t currenttime;




//PF_INET: Protokollfamilie
//SOCK_STREAM: Sequenced, reliable, connection-based byte streams
	if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
		printf("socket failed\n");

	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
		printf("setsockopt failde\n");

struct sockaddr_in host_addr, client_addr;
host_addr.sin_family = PF_INET;  //Host-Bytereihenfolge
host_addr.sin_port = htons(Port);  //Short, Netzwerk-Bytereihenfolge
host_addr.sin_addr.s_addr = 0; //Automatisch mit einer IP füllen
memset(&(host_addr.sin_zero), '\0', 8); //Rest der Struktur mit Nullen auffüllen

	if (bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr)) == -1)
		printf("bind failed\n");

	if (listen(sockfd, 5) == -1)
		printf("listen failed\n");

	sin_size = sizeof(struct sockaddr_in);
	
	int zaehler = 0;
	while(zaehler < 5)
	{	
		//printf("Auf accept warten\n");
		new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
		//if(new_sockfd = (accept(sockfd, (struct sockaddr *)&client_addr, &sin_size)) == -1)
		if(new_sockfd == -1)
			printf("accept failed\n");
		/*else
		{
			printf("accept successful\n");
			printf("new_sockfd nach accept: %i\n", new_sockfd);
		}*/
		//printf("weiterhin warten\n");
		time(&currenttime);
		newtime = localtime(&currenttime);
	
		printf("[%d:%d:%d] Anfrage von %s, Port %d\n", newtime->tm_hour, newtime->tm_min, newtime->tm_sec, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

	//int zaehler = 0;
	//while (zaehler<5)
	//{
		char sec = (char)newtime->tm_sec;
		if((send(new_sockfd, &sec, sizeof(sec), 0)) == -1)
			printf("failde to send seconds\n");
		char min = (char)newtime->tm_min;
		if((send(new_sockfd, &min, sizeof(min), 0)) == -1)
			printf("failde to send minutes\n");
		char hour = (char)newtime->tm_hour;
		if((send(new_sockfd, &hour, sizeof(hour), 0)) == -1)
			printf("failde to send hours\n");
		zaehler = zaehler + 1;
	}
}
