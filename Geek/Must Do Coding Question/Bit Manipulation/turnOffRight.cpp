#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    unsigned int a = n & (n-1);
    cout<<a<<endl;
    return 0;
}
