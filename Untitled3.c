#include<iostream>
using namespace std;
namespace X{
int a=10;
}
namespace Y{
int a=20;
}
int main()
{
cout<<"a in x="<<X::a<<endl;
cout<<"a in y="<<Y::a<<endl;
return 0;
}
