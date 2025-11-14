#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

// =====================
// Base Class: Account
// =====================
class Account {
protected:
    string ownerName;
    double balance;

public:
    Account(string ismim, double pulim): ownerName(ismim), balance(pulim) {}

    double getBalance() const {return balance;}

    virtual void display() {cout << "Owner: " << ownerName << "\n" << "Balance: " << balance << "\n";}

    virtual ~Account() {cout << "Account closed for " << ownerName << "\n";}

    Account operator+(const Account& other) const {return Account(ownerName, balance + other.balance);}

    Account operator-(const Account& other) const {return Account(ownerName, balance - other.balance);}

    bool operator==(const Account& other) const {return balance == other.balance;}

    friend ostream& operator<<(ostream& os, const Account& acc) {os << "Owner: " << acc.ownerName << "\n" << "Balance: " << acc.balance << "\n";return os;}

    friend istream& operator>>(istream& is, Account& acc) {is >> acc.ownerName >> acc.balance;return is;}
};


class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string ismim, double pulim, double pulimkopayishi): Account(ismim, pulim), interestRate(pulimkopayishi) {}

    void display() {cout << "Owner: " << ownerName << "\n" << "Balance: " << balance << "\n" << "Interest Rate: " << interestRate << "%" << "\n";}

    ~SavingsAccount() {}
};

class CheckingAccount : public Account {
private:
    double transactionFee;
public:
    CheckingAccount(string ismim, double pulim, double pulimkamayishi): Account(ismim, pulim), transactionFee(pulimkamayishi) {}

    void display() {cout << "Owner: " << ownerName << "\n" << "Balance: " << balance << "\n" << "Transaction Fee: " << transactionFee << "\n";}

    ~CheckingAccount() {}
};

#endif
