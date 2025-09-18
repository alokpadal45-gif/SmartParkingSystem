// write a c++ program to calclute SI. Ask user for: P,R and Time
#include <iostream>

int main() {
    float principal, rate, time, simpleInterest;

    std::cout << "Enter Principal: ";
    std::cin >> principal;
    std::cout << "Enter Rate of Interest: ";
    std::cin >> rate;

    std::cout << "Enter Time (T) in years: ";
    std::cin >> time;

    simpleInterest = (principal * rate * time) / 100;

    std::cout << "Simple Interest is: " << simpleInterest << std::endl;

    return 0;
}
