#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

// ======================================
// Base Class: BankAccount (renamed)
// ======================================
class BankAccount {
protected:
    std::string owner;
    double currentBalance;

public:
    // Constructor rewritten with different order & naming
    BankAccount(const std::string& name, double initialAmount)
        : owner(name), currentBalance(initialAmount) {}

    virtual ~BankAccount() {
        std::cout << "Closing account for: " << owner << std::endl;
    }

    // Getter unchanged logically but reworded
    double balance() const {
        return currentBalance;
    }

    // Display rewritten with different formatting & wording
    virtual void show() const {
        std::cout << "[Account Info]\n"
                  << "Name   : " << owner << "\n"
                  << "Balance: " << currentBalance << "\n";
    }

    // -------- Operator Overloads --------

    // Addition operator rewritten differently
    BankAccount operator+(const BankAccount& rhs) const {
        BankAccount result(owner, currentBalance + rhs.currentBalance);
        return result;
    }

    // Subtraction operator rewritten differently
    BankAccount operator-(const BankAccount& rhs) const {
        BankAccount result(owner, currentBalance - rhs.currentBalance);
        return result;
    }

    // Equality rewritten
    bool operator==(const BankAccount& rhs) const {
        return currentBalance == rhs.currentBalance;
    }

    // Stream insertion rewritten
    friend std::ostream& operator<<(std::ostream& out, const BankAccount& acc) {
        out << "Owner: " << acc.owner << "\n"
            << "Balance: " << acc.currentBalance << "\n";
        return out;
    }

    // Stream extraction rewritten
    friend std::istream& operator>>(std::istream& in, BankAccount& acc) {
        in >> acc.owner >> acc.currentBalance;
        return in;
    }
};


// ========================================
// Derived Class: SavingsAccount
// ========================================
class SavingsAccount : public BankAccount {
private:
    double rate;

public:
    SavingsAccount(const std::string& name,
                   double amount,
                   double interest)
        : BankAccount(name, amount), rate(interest) {}

    // show() rewritten differently
    void show() const override {
        std::cout << "[Savings Account]\n"
                  << "Holder        : " << owner << "\n"
                  << "Current Funds : " << currentBalance << "\n"
                  << "Interest Rate : " << rate << "%\n";
    }

    ~SavingsAccount() override = default;
};


// ========================================
// Derived Class: CheckingAccount
// ========================================
class CheckingAccount : public BankAccount {
private:
    double fee;

public:
    CheckingAccount(const std::string& name,
                    double amount,
                    double transactionFee)
        : BankAccount(name, amount), fee(transactionFee) {}

    // show() rewritten differently
    void show() const override {
        std::cout << "[Checking Account]\n"
                  << "Holder        : " << owner << "\n"
                  << "Current Funds : " << currentBalance << "\n"
                  << "Fee per Use   : " << fee << "\n";
    }

    ~CheckingAccount() override = default;
};

#endif

    ~CheckingAccount() {}
};

#endif
