#include "Functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
using namespace std;
fstream f;

struct tm *newtime;
time_t currenttime;

Functions::Functions() {
}

Functions::Functions(const Functions& orig) {
}

Functions::~Functions() {
}

void Functions::Deposit(int numb, int diff)
{
    accountnumber = numb;
    difference = diff;
    
    time(&currenttime);
    newtime = localtime(&currenttime);
    
    int day = newtime->tm_mday;
    int month = newtime->tm_mon + 1;
    int year = newtime->tm_year + 1900;
    int hour = newtime->tm_hour;
    int min = newtime->tm_min;
    int sec = newtime->tm_sec;
    
    //Datei mit entsprechender Accountnummer öffnen
    stringstream strs;
    strs << accountnumber;
    string temp_str = strs.str();
    char* data = (char*) temp_str.c_str();
    
    ifstream FileTest(data);
    if(!FileTest)
    {
        std::cout << "File not found." << std::endl;        
    }
    
    else
    {
        //Aktuellen Kontostand einlesen
        string s;
        f.open(data, ios::in);
        while(!f.eof())
        {
            getline(f, s);
        }
        s.erase(0, s.find("=", 0)+1);
        amount = atoi(s.c_str());
        f.close();
        
        amount = amount + diff;
        
        f.open(data, ios::out|ios::app);
        //Datum und Uhrzeit protokollieren
        f << endl << endl << day << "." << month << "." << year << " - " << hour << ":" <<  min << ":" << sec;
        //Aktion und aktuellen Kontostand protokollieren
        f << endl << "Einzahlung=" << difference << endl << "Kontostand=" << amount;
        f.close();
    }
}

void Functions::Statement(int acc, int sock)
{
    accountnumber = acc;
    int socked = sock;
    
    stringstream strs;
    strs << accountnumber;
    string temp_str = strs.str();
    char* data = (char*) temp_str.c_str();    
    f.open(data, ios::in);    
    while(!f.eof())
    {
        string s = " ";
        getline(f, s);
        s = s.substr(0, s.find("\n"));
        int laenge = s.size() +1;
        char test[laenge];
        strcpy(test, s.c_str());
        test[laenge-1] = '\n';
        test[laenge] = '\0';
        send(socked, test, sizeof(test), 0);
    }
    f.close();
    
    f.open(data, ios::trunc|ios::out);
    f << " ";
    f.close();
}

void Functions::Withdraw(int numb, int diff)
{
    accountnumber = numb;
    difference = diff;
    
    time(&currenttime);
    newtime = localtime(&currenttime);
    
    int day = newtime->tm_mday;
    int month = newtime->tm_mon + 1;
    int year = newtime->tm_year + 1900;
    int hour = newtime->tm_hour;
    int min = newtime->tm_min;
    int sec = newtime->tm_sec;
    
    //Datei mit entsprechender Accountnummer öffnen
    stringstream strs;
    strs << accountnumber;
    string temp_str = strs.str();
    char* data = (char*) temp_str.c_str();
    
    ifstream FileTest(data);
    if(!FileTest)
    {
        std::cout << "File not found." << std::endl;        
    }
    
    else
    {
        //Aktuellen Kontostand einlesen
        string s;
        f.open(data, ios::in);
        while(!f.eof())
        {
            getline(f, s);
        }
        s.erase(0, s.find("=", 0)+1);
        amount = atoi(s.c_str());
        f.close();
        
        amount = amount - diff;
        
        f.open(data, ios::out|ios::app);
        //Datum und Uhrzeit protokollieren
        f << endl << endl << day << "." << month << "." << year << " - " << hour << ":" <<  min << ":" << sec;
        //Aktion und aktuellen Kontostand protokollieren
        f << endl << "Auszahlung=" << difference << endl << "Kontostand=" << amount;
        f.close();
    }
}

void Functions::AccountStatus(int numb, int sock)
{
    int socked = sock;
    
    //Datei mit entsprechender Accountnummer öffnen
    stringstream strs;
    strs << accountnumber;
    string temp_str = strs.str();
    char* data = (char*) temp_str.c_str();
    
    ifstream FileTest(data);
    if(!FileTest)
    {
        std::cout << "File not found." << std::endl;        
    }    
    
    //Aktuellen Kontostand einlesen
    string s;
    f.open(data, ios::in);
    while(!f.eof())
    {
        getline(f, s);
    }
    f.close();
    s = s.substr(0, s.find("\n"));
    int laenge = s.size() +1;
    char test[laenge];
    strcpy(test, s.c_str());
    test[laenge-1] = '\n';
    test[laenge] = '\0';
    send(socked, test, sizeof(test), 0);
    
    cout << "Aktueller Kontostand: " << amount << "€" << endl;
}