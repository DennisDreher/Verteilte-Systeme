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
#include <unistd.h>

#include "GetProcess.h"
#include "Functions.h"

using namespace std;

#define Port 12345  //Der Port, mit dem die Benutzer die Verbindung herstellen
#define PrintError(msg) cout << msg << endl

int sockfd, new_sockfd;  //Warten an sockfd, neue Verbindung an new_sockfd
socklen_t sin_size;
int recv_length, yes=1, i=0;
char buffer[1024];

GetProcess gp;
Functions Fnct;
int wichthread = 1;

void* threads (void* arg)
{
    cout << "Thread: " << wichthread << endl;
    wichthread ++;
    char* pBuffer = (char*)arg;
    string url = pBuffer;
    gp.setCutUrl(url);
    
    if(gp.getAction() == "deposit")
    {
        Fnct.Deposit(gp.getAccountnumber(), gp.getAmount());
        close(new_sockfd);
        pthread_exit(0);
    }
    
    if(gp.getAction() == "statement")
    {
        Fnct.Statement(gp.getAccountnumber(), new_sockfd);
        close(new_sockfd);
        pthread_exit(0);
    }
    
    if(gp.getAction() == "withdraw")
    {
        Fnct.Withdraw(gp.getAccountnumber(), gp.getAmount());
        close(new_sockfd);
        pthread_exit(0);
    }
    
    if(gp.getAction() == "accountstatus")
    {
        Fnct.AccountStatus(gp.getAccountnumber(), new_sockfd);
        close(new_sockfd);
        pthread_exit(0);
    }
}

int main(void)
{
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
        
        //Variablen für prüfen auf leerzeile
        int find;
        string s1;
        do{
            recv(new_sockfd, buffer, 1, 0);
            
            //Auf leerzeile prüfen
            s1 = s1 + buffer[0];
            find = s1.find("\r\n\r\n");            
            if(find != -1)
                cout << s1 << endl;
            
        } while(find == -1);
        
        strcpy(buffer, s1.c_str()); 
        
        //Thread
        pthread_t tid;
        pthread_attr_t attr;
        pthread_attr_init(&attr);        
        pthread_create(&tid, &attr, threads, buffer);
        //close(new_sockfd);
    }
    return 0;
}