#include<iostream>
using namespace std;

int main()
{
    int x;
    cin>>x;

    cout<<__builtin_popcount(x)<<endl;
    unsigned int cou = 0;
    while(x)
    {
        x = x & (x-1);
        cou++;
    }
    cout<<cou<<endl;

}
