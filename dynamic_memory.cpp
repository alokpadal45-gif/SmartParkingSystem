#include<iostream>
using namespace std;
int main(){
    int *arr, size;
    cout << "Enter number of elements:";
    cin>>size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
    cout<<(arr+i)<< endl;
    }
    cout<<"Enter"<<size <<"numbers";
    for (int i=0; i<size;i++)
    {
        cin>>val;
        arr[i] = val;
    }
    cout<<"Array elements are: << endl;
    for(int i = 0; i<size; i++)
    {
        cout << arr[i]}<<" ";
}
cout<<endl;
delete []arr; //memory dellocation
return 0;
}
