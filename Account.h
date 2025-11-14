#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

// =====================================
// Base Class: CoreAccount
// =====================================
class CoreAccount {
protected:
    std::string holder;
    double funds;

public:
    CoreAccount(const std::string& name, double amount)
        : holder(name), funds(amount) {}

    virtual ~CoreAccount() {
        std::cout << "Account terminated for " << holder << std::endl;
    }

    double getFunds() const {
        return funds;
    }

    virtual void print() const {
        std::cout << "Holder : " << holder << "\n"
                  << "Funds  : " << funds << "\n";
    }

    // Operators rewritten but same functionality
    CoreAccount operator+(const CoreAccount& other) const {
        return CoreAccount(holder, funds + other.funds);
    }

    CoreAccount operator-(const CoreAccount& other) const {
        return CoreAccount(holder, funds - other.funds);
    }

    bool operator==(const CoreAccount& other) const {
        return funds == other.funds;
    }

    friend std::ostream& operator<<(std::ostream& out, const CoreAccount& acc) {
        out << "Holder : " << acc.holder << "\n"
            << "Funds  : " << acc.funds << "\n";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, CoreAccount& acc) {
        in >> acc.holder >> acc.funds;
        return in;
    }
};

// =====================================
// SavingsAccount
// =====================================
class SavingsAccount : public CoreAccount {
private:
    double rate;

public:
    SavingsAccount(const std::string& name, double amount, double interest)
        : CoreAccount(name, amount), rate(interest) {}

    void print() const override {
        std::cout << "Savings Account\n"
                  << "Holder        : " << holder << "\n"
                  << "Funds         : " << funds << "\n"
                  << "Interest Rate : " << rate << "%\n";
    }

    ~SavingsAccount() override = default;
};

// =====================================
// CheckingAccount
// =====================================
class CheckingAccount : public CoreAccount {
private:
    double fee;

public:
    CheckingAccount(const std::string& name, double amount, double charge)
        : CoreAccount(name, amount), fee(charge) {}

    void print() const override {
        std::cout << "Checking Account\n"
                  << "Holder       : " << holder << "\n"
                  << "Funds        : " << funds << "\n"
                  << "Fee per Use  : " << fee << "\n";
    }

    ~CheckingAccount() override = default;
};

#endif
