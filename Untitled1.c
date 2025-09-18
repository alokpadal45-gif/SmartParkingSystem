#include<iostream>
using namespace std;
namespace Test{
float a=2.5;
}
int main(){
int a=10;
cout<<"a= "<<a<<endl;
cout<<"other a= "<<Test::a<<endl;
return 0;
}
