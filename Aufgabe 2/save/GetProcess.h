#ifndef GETPROCESS_H
#define	GETPROCESS_H

#include <string>
using namespace std;

class GetProcess {
private:
    string action, cuturl;
    int accountnumber, amount;

public:
    GetProcess();
    GetProcess(const GetProcess& orig);
    virtual ~GetProcess();
    
    void setCutUrl (string);
    string getCutUrl();
    
    int getAccountnumber();
    string getAction();
    int getAmount();
};

#endif	/* GETPROCESS_H */

