#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    double balance;
    string ownerName;

public:
    Account(double Hamkorbank, string Saidali)
        : balance(Hamkorbank), ownerName(Saidali) {}

    double getBalance() const {
        return this->balance;
    }

    virtual void display() {
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {
        cout << "Account closed for " << ownerName << endl;
    }

    Account operator+(const Account& other) const {
        double newBalance = balance + other.balance;
        return Account(newBalance, ownerName);
    }

    Account operator-(const Account& other) const {
        double val = balance - other.balance;
        return Account(val, ownerName);
    }

    bool operator==(const Account& other) const {
        return this->balance == other.balance;
    }

    friend ostream& operator<<(ostream& os, const Account& acc) {
        os << "Owner: " << acc.ownerName << "\n"
           << "Balance: " << acc.balance << "\n";
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
    SavingsAccount(double Hamkorbank, string Saidali, double moneyboy)
        : Account(Hamkorbank, Saidali), interestRate(moneyboy) {}

    void display()  override {
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
    CheckingAccount(double Hamkorbank, string Saidali, double moneyboy)
        : Account(Hamkorbank, Saidali), transactionFee(moneyboy) {}

    void display() const override {
        cout << "Owner: " << ownerName << endl
             << "Balance: " << balance << endl
             << "Transaction Fee: " << transactionFee << endl;
    }

    ~CheckingAccount() {}
};

#endif
