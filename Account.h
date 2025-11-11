#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

// Base class: Account
class Account {
protected:
    string ownerName;
    double balance;

public:
    // Parameterized constructor
    Account(string name = "", double bal = 0.0) : ownerName(name), balance(bal) {}

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Virtual display function
    virtual void display() const {
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
    }

    // Virtual destructor
    virtual ~Account() {
        cout << "Account closed for " << ownerName << endl;
    }

    // Operator overloading

    // + operator → combines balances and returns new Account
    Account operator+(const Account& other) const {
        return Account(ownerName, balance + other.balance);
    }

    // - operator → returns difference between balances
    double operator-(const Account& other) const {
        return balance - other.balance;
    }

    // == operator → compares balances
    bool operator==(const Account& other) const {
        return balance == other.balance;
    }

    // << operator → output account info
    friend ostream& operator<<(ostream& os, const Account& acc) {
        os << "Owner: " << acc.ownerName << endl;
        os << "Balance: " << acc.balance << endl;
        return os;
    }

    // >> operator → input account info
    friend istream& operator>>(istream& is, Account& acc) {
        is >> acc.ownerName >> acc.balance;
        return is;
    }
};

// Derived class: SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    // Constructor
    SavingsAccount(string name = "", double bal = 0.0, double rate = 0.0)
        : Account(name, bal), interestRate(rate) {}

    // Override display
    void display() const override {
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }

    // Destructor
    ~SavingsAccount() override {
        cout << "Account closed for " << ownerName << endl;
    }
};

// Derived class: CheckingAccount
class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    // Constructor
    CheckingAccount(string name = "", double bal = 0.0, double fee = 0.0)
        : Account(name, bal), transactionFee(fee) {}

    // Override display
    void display() const override {
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Transaction Fee: " << transactionFee << endl;
    }

    // Destructor
    ~CheckingAccount() override {
        cout << "Account closed for " << ownerName << endl;
    }
};

#endif
