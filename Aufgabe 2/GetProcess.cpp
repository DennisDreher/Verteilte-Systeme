#include "GetProcess.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

GetProcess::GetProcess() {
}
GetProcess::GetProcess(const GetProcess& orig) {
}
GetProcess::~GetProcess() {
}

//das "HTTP GET" bearbeiten und die nötigen daten auslesen
//Beispiel URL: http://<hostname>/account?no=<ktonummer>&withdraw=5
void GetProcess::setCutUrl (string url){
    
    //URL auslesen
    url.erase(0, 5);                            //"GET /" am anfang der url loeschen
    url.erase(url.find(" ", 0));                //ende der url finden und alles nachkommende loeschen
    
    //Kontonummer auslesen
    url.erase(0, url.find("=", 0)+1);           //bis zum beginn der kontonummer alles loeschen
    cuturl = url.substr(0, url.find("&"));      //kontonummer zwischenspeicher
    accountnumber = atoi(cuturl.c_str());       //kontonummer in int umwandenl und speichern
    
    //Aktion auslesen
    url.erase(0, url.find("&", 0)+1);           //bis zum beginn der aktion alles loeschen
    action = url.substr(0, url.find("=", 0));   //aktion speichern
    
    //Geldbetrag auslesen
    url.erase(0, url.find("=", 0)+1);           //bis zum beginn des betrags alles loeschen
    amount = atoi(url.c_str());                 //betrag speichern
}

string GetProcess::getCutUrl (){
    return(cuturl);
}

int GetProcess::getAccountnumber(){
    return(accountnumber);
}

string GetProcess::getAction(){
    return(action);
}

int GetProcess::getAmount(){
    return(amount);
}