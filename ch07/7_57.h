#ifndef CP5_ex7_57_h
#define CP5_ex7_57_h

#include <string>

using namespace std;

class Account {
public:
    void calculate() { amount += amount * interestRate; }

    static double rate() { return interestRate; }

    static void rate(double newRate) { interestRate = newRate; }

private:
    string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 42.42;

    static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();

#endif