
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int x=10;
double y=2.3456;
cout<<x<<endl;
cout<<setfill('-')<<setw(20)<<x<<endl;
cout<<y<<endl;
cout<<setprecision(4)<<y<<endl;
return 0;
}
