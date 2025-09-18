#include<iostream>
using namespace std;
int main(){
int a = 10,*ptr;
ptr = &a;
cout<<"value of a= "<< a <<endl;
cout<<"address of a= "<< &a <<endl;

cout<<"value of a= "<<*(&a)<<endl;
cout<<"address of a= "<< ptr <<endl;

cout<<"value of a= "<< *ptr <<endl;
return 0;
}
