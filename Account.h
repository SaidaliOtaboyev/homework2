#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    string ownerName;
    double balance;

public:
    Account(const string& Saidali, double Hamkorbank)
        : ownerName(Saidali), balance(Hamkorbank) {}

    double getBalance() const {
        return balance;
    }

    virtual void display() const {
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {
        cout << "Account closed for " << ownerName << endl;
    }

    Account operator+(const Account& other) const {
        double newBalance = balance + other.balance;
        return Account(ownerName, newBalance);
    }

    Account operator-(const Account& other) const {
        double newBalance = balance - other.balance;
        return Account(ownerName, newBalance);
    }

    bool operator==(const Account& other) const {
        return balance == other.balance;
    }

    friend ostream& operator<<(ostream& os, const Account& acc) {
        os << "Owner: " << acc.ownerName << endl
           << "Balance: " << acc.balance << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Account& acc) {
        is >> acc.ownerName >> acc.balance;
        return is;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const string& Saidali, double Hamkorbank, double moneyboy)
        : Account(Saidali, Hamkorbank), interestRate(moneyboy) {}

    void display() const override {
        cout << "Owner: " << ownerName << endl
             << "Balance: " << balance << endl
             << "Interest Rate: " << interestRate << "%" << endl;
    }

    ~SavingsAccount() {}
};

class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(const string& Saidali, double Hamkorbank, double moneyboy)
        : Account(Saidali, Hamkorbank), transactionFee(moneyboy) {}

    void display() const override {
        cout << "Owner: " << ownerName << endl
             << "Balance: " << balance << endl
             << "Transaction Fee: " << transactionFee << endl;
    }

    ~CheckingAccount() {}
};

#endif
