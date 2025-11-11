#include <iostream>
#include <string>
#include <cassert>
#include <iomanip> 
using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;

class Account {
protected:
    string owner_;
    double bal_;

public:
    Account(const string& owner = "", double balance = 0.0)
        : owner_(owner), bal_(balance) {}

    virtual ~Account() {
        cout << "Account closed for " << owner_ << '\n';
    }

    double getBalance() const noexcept { return bal_; }

    virtual bool deposit(double amount) {
        if (amount <= 0) return false;
        bal_ += amount;
        return true;
    }

    virtual bool withdraw(double amount) {
        if (amount <= 0 || amount > bal_) return false;
        bal_ -= amount;
        return true;
    }

    virtual void display(ostream& os = cout) const {
        os << "Owner: " << owner_ << '\n';
        os << "Balance: " << bal_ << '\n';
    }

    virtual Account* clone() const { return new Account(*this); }

    Account operator+(const Account& other) const {
        string combinedOwner = owner_ + " & " + other.owner_;
        return Account(combinedOwner, bal_ + other.bal_);
    }

    double operator-(const Account& other) const noexcept {
        return bal_ - other.bal_;
    }

    bool operator==(const Account& other) const noexcept {
        return bal_ == other.bal_;
    }

    friend ostream& operator<<(ostream& os, const Account& a) {
        a.display(os); 
        return os;
    }

    friend istream& operator>>(istream& is, Account& a) {
        is >> a.owner_ >> a.bal_;
        return is;
    }
};

class SavingsAccount : public Account {
private:
    double ratePercent_; 

public:
    SavingsAccount(const string& owner = "", double balance = 0.0, double rate = 0.0)
        : Account(owner, balance), ratePercent_(rate) {}

    void display(ostream& os = cout) const override {
        os << "Owner: " << owner_ << '\n';
        os << "Balance: " << bal_ << '\n';
        os << "Interest Rate: " << std::fixed << std::setprecision(1) << ratePercent_ << "%\n";
    }

    ~SavingsAccount() override {
        cout << "Account closed for " << owner_ << '\n';
    }

    Account* clone() const override { return new SavingsAccount(*this); }

    void applyAnnualInterest() { bal_ += bal_ * (ratePercent_ / 100.0); }
};

class CheckingAccount : public Account {
private:
    double feePerTransaction_;

public:
    CheckingAccount(const string& owner = "", double balance = 0.0, double fee = 0.0)
        : Account(owner, balance), feePerTransaction_(fee) {}

    void display(ostream& os = cout) const override {
        os << "Owner: " << owner_ << '\n';
        os << "Balance: " << bal_ << '\n';
        os << "Transaction Fee: " << feePerTransaction_ << '\n';
    }

    ~CheckingAccount() override {
        cout << "Account closed for " << owner_ << '\n';
    }

    Account* clone() const override { return new CheckingAccount(*this); }

    bool withdraw(double amount) override {
        if (amount <= 0) return false;
        double total = amount + feePerTransaction_;
        if (total > bal_) return false;
        bal_ -= total;
        return true;
    }
};
