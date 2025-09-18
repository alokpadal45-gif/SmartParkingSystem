#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Bank {
    string acc_no;
    double balance;
    vector<string> statement;

public:
    Bank(string acc_no) {
        this->acc_no = acc_no;
        this->balance = 0.0;
    }

    void withdraw(double amt) {
        if (this->balance < amt) {
            cout << "Insufficient balance!!" << endl;
            return;
        }
        this->balance -= amt;
        string st = to_string(amt) + " Withdrawn";
        statement.push_back(st);
    }

    void deposit(double amt) {
        this->balance += amt;
        string st = to_string(amt) + " Deposited";
        statement.push_back(st);
    }

    void check_info() {
        cout << "Hello! Account " << this->acc_no << ":" << endl;
        cout << "Balance Amount Rs. " << this->balance << endl;
    }

    void show_history() {
        cout << "Transaction History for Account " << this->acc_no << ":" << endl;
        for (string s : statement) {
            cout << "- " << s << endl;
        }
    }
};

int main() {
    Bank ob("10010");
    ob.check_info();
    ob.withdraw(1000);
    ob.deposit(5000);
    ob.check_info();
    ob.withdraw(3000);
    ob.check_info();
    ob.show_history();
    return 0;
}
