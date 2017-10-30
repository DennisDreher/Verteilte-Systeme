#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <iostream>
#include <string>
#include <pthread.h>

#include "GetProcess.h"

using namespace std;

#define Port 12345  //Der Port, mit dem die Benutzer die Verbindung herstellen
#define PrintError(msg) cout << msg << endl
int main(void) {
    GetProcess gp;
    
    
    int sockfd, new_sockfd;  //Warten an sockfd, neue Verbindung an new_sockfd
    socklen_t sin_size;
    int recv_length=1, yes=1, i=0;
    char buffer[1024];
    
//PF_INET: Protokollfamilie
//SOCK_STREAM: Sequenced, reliable, connection-based byte streams
    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
        PrintError("socked failed");

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
        PrintError("setsockopt failed");

struct sockaddr_in host_addr, client_addr;
host_addr.sin_family = PF_INET;  //Host-Bytereihenfolge
host_addr.sin_port = htons(Port);  //Short, Netzwerk-Bytereihenfolge
host_addr.sin_addr.s_addr = 0; //Automatisch mit einer IP füllen
memset(&(host_addr.sin_zero), '\0', 8); //Rest der Struktur mit Nullen auffüllen

    if (bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr)) == -1)
        PrintError("bind failed");

    if (listen(sockfd, 5) == -1)
        PrintError("listen failed");

    sin_size = sizeof(struct sockaddr_in);
        
    while(1)
    {
	new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
	if(new_sockfd == -1)
            PrintError("accept failed");
                
        recv(new_sockfd, buffer, sizeof(buffer), 0);
        gp.setCutUrl(buffer);                           //url verarbeiten
        
        cout << "Kontonummer: " << gp.getAccountnumber() << endl;
        cout << "Aktion: " << gp.getAction() << endl;
        cout << "Menge: " << gp.getAmount() << endl;
    }
}