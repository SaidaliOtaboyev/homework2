#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <limits>
#include <cmath>

class Account {
protected:
    std::string ownerName;
    double balance;

public:
    Account(std::string name = "", double bal = 0.0)
        : ownerName(std::move(name)), balance(bal) {}

    double getBalance() const {
        return balance;
    }

    virtual void display() const {
        std::cout << "Owner: " << ownerName << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }

    virtual ~Account() {
        std::cout << "Account closed for " << ownerName << std::endl;
    }

    // Operator overloadlar
    Account operator+(const Account& other) const {
        return Account(ownerName, balance + other.balance);
    }

    double operator-(const Account& other) const {
        return balance - other.balance;
    }

    bool operator==(const Account& other) const {
        // floating point comparison with small epsilon
        return std::fabs(balance - other.balance) <= 1e-9;
    }

    friend std::ostream& operator<<(std::ostream& out, const Account& acc) {
        out << "Owner: " << acc.ownerName << std::endl;
        out << "Balance: " << acc.balance << std::endl;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Account& acc) {
        // consume leading whitespace/newline, then read full line for name
        std::getline(in >> std::ws, acc.ownerName);
        in >> acc.balance;
        // discard rest of the line so next reads start clean
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return in;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(std::string name = "", double bal = 0.0, double rate = 0.0)
        : Account(std::move(name), bal), interestRate(rate) {}

    void display() const override {
        std::cout << "Owner: " << ownerName << std::endl;
        std::cout << "Balance: " << balance << std::endl;
        std::cout << "Interest Rate: " << interestRate << "%" << std::endl;
    }
};

class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(std::string name = "", double bal = 0.0, double fee = 0.0)
        : Account(std::move(name), bal), transactionFee(fee) {}

    void display() const override {
        std::cout << "Owner: " << ownerName << std::endl;
        std::cout << "Balance: " << balance << std::endl;
        std::cout << "Transaction Fee: " << transactionFee << std::endl;
    }
};

#endif // ACCOUNT_H
