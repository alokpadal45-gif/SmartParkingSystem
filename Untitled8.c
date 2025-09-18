#include<iostream>
using namespace std;
int main()
int sizel
int *arr;
cout<<"Enter number of elements: ";
cin>>size;
arr = new int(size);
cout<<"Enter "<<size<<"elemnts "<<endl;
for(int i=0; i<size; i++)
{
int elem;
cin>>elem;
arr[i] = elem;
}
cout<<" Following are array elements: "<<endl;
for(inr i=0;i<size,i++)
{

cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}
