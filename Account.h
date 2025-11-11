#include <iostream>
#include <string>

class Account {
protected:
    std::string ownerName;
    double balance;

public:
    Account(std::string name, double bal) : ownerName(name), balance(bal) {}
    
    double getBalance() {
        return balance;
    }

    virtual void display() {
        std::cout << "Owner: " << ownerName << "\nBalance: " << balance << std::endl;
    }

    virtual ~Account() {
        std::cout << "Account closed for " << ownerName << std::endl;
    }

    Account operator+(const Account& other) {
        return Account(ownerName, balance + other.balance);
    }

    double operator-(const Account& other) {
        return balance - other.balance;
    }

    bool operator==(const Account& other) {
        return balance == other.balance;
    }

    friend std::ostream& operator<<(std::ostream& os, const Account& acc) {
        os << "Owner: " << acc.ownerName << "\nBalance: " << acc.balance;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Account& acc) {
        is >> acc.ownerName >> acc.balance;
        return is;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(std::string name, double bal, double rate) : Account(name, bal), interestRate(rate) {}

    void display() override {
        std::cout << "Owner: " << ownerName << "\nBalance: " << balance << "\nInterest Rate: " << interestRate << "%" << std::endl;
    }
};

class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(std::string name, double bal, double fee) : Account(name, bal), transactionFee(fee) {}

    void display() override {
        std::cout << "Owner: " << ownerName << "\nBalance: " << balance << "\nTransaction Fee: " << transactionFee << std::endl;
    }
};
