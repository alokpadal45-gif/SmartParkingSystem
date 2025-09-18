//write a program that asks user to enter a number check whether given number is: positive negative or zero
#include<iostream>
int main()

{
    int  number;
    std::cout<<"Enter a number:";
    std::cin>> number;
    if (number>0){
        std::cout<<"Number is positive:"<<std::endl;
    }
    else if (number<0){
        std::cout<<"Number is negative:"<<std::endl;
    }
    else{
        std::cout<<"Number is zero:" <<  std::endl;
    }
    return 0;
}
