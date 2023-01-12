#include <iostream>
#include <cmath>
using namespace std;

class Deposit {
protected:
    double rate;
    double startSum;

  

public:
    Deposit() {
        this->rate = 0;
        this->startSum = 0;
    }


    Deposit(double rate, double startSum) {
        this->rate = rate;
        this->startSum = startSum;

    }

    virtual double Calculate() = 0;
    virtual void Input() = 0;
    virtual void Print() = 0;

};

class TermDeposit : public Deposit {

protected:
    int term;
    const double KOEFICIENT_SHORT = 0.1;
    const double KOEFICIENT_MEDIUM = 0.15;
    const double KOEFICIENT_LONG = 0.2;
    
public:
    TermDeposit() : Deposit() {
        this->term = 0;
    }

    TermDeposit(double rate, double startSum, int term) : Deposit(rate, startSum) {
        this->term = term;
    }

    void Input() override {
        cout << "Start sum : " << endl;
        cin >> startSum;
        cout << "Rate : " << endl;
        cin >> rate;
        cout << "Term : " << endl;
        cin >> term;
    }

    virtual double Calculate() override = 0;
    virtual void Print() override = 0;
};

class ShortDeposit : public TermDeposit {

public:
    ShortDeposit() : TermDeposit() {

    }

    ShortDeposit(double rate, double startSum, int term) : TermDeposit(rate, startSum, term) {

    }
   double Calculate() override {
        return startSum + startSum * (rate/100) * KOEFICIENT_SHORT * term;
     }

   void Print() override {
       cout << "Short deposit. Total amount " << Calculate() << endl;
       cout << "Month count: " << term << ". Start sum: " << startSum << endl;
    }

};

class LongDeposit : public TermDeposit {

public:
    LongDeposit() : TermDeposit() {}

    LongDeposit(double rate, double startSum, int term) : TermDeposit(rate, startSum, term) {}

        double Calculate() override {
            return startSum + startSum * (rate/100) * KOEFICIENT_LONG * term;
        }

        void Print() override {
            cout << "Long deposit. Total amount " << Calculate() << endl;
            cout << "Month count: " << term << ". Start sum: " << startSum << endl;

        }
};

class TargetedDeposit : public Deposit {
private:
    double target;

public:
    TargetedDeposit() : Deposit() {
        this->target = 0;
    }

    TargetedDeposit(double rate, double startSum, double target) : Deposit(rate, startSum) {
        this->target = target;
    }

    void Input() override{
        cout << "Start sum : " << endl;
        cin >> startSum;
        cout << "Rate : " << endl;
        cin >> rate;
        cout << "Target : " << endl;
        cin >> target;
    }

    void Print() override {
        cout << "Month count to target sum: " << Calculate() << endl;
        cout << "Result sum: " << CalculateResult() << endl;
    }

    double Calculate() override {
        return trunc(target / (startSum + (rate/100) * startSum ));
    }

    double CalculateResult() {
        return (startSum + rate * startSum) * Calculate() + startSum;
    }
};

int main() {
    TargetedDeposit targetDeposit(20, 1000.0, 10000.0), targetDeposit1;
    targetDeposit.Print();
    targetDeposit1.Input();
    targetDeposit1.Print();
    ShortDeposit shortDeposit(20, 1000.0, 24);
    shortDeposit.Print();
    LongDeposit longDeposit(20, 1000.0, 24);
    longDeposit.Print();


};