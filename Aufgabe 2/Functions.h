#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#include <string>
using namespace std;

class Functions {
private:
    int accountnumber, amount, difference;
    string sAction;
    
public:
    Functions();
    Functions(const Functions& orig);
    virtual ~Functions();
    
    void Deposit(int, int);
    void Statement(int, int);
    void Withdraw(int, int);
    void AccountStatus(int, int);
};

#endif	/* FUNCTIONS_H */

