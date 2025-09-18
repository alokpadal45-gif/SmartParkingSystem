#include<iostream>
using namespace std;
namespace Test{
float a=2.5;
int add(int x, int y){
return x+y;
}
}
using namespace Test;
int main(){
int a=10;
cout<<"a= "<<a<<endl;
cout<<"other a= "<<Test::a<<endl;
cout<<"sum= "<<Test::add(2,3)<<endl;
return 0;
}
