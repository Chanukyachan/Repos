#include<iostream>
using namespace std;

int main()
{
    unsigned int x;

    cin>>x;
    unsigned int cou = sizeof(x) * 8 - 1;

    cout<<cou<<endl;

    unsigned int reverse_num = x;

    cout<<reverse_num<<endl;


    x >>=1;

    cout<<x<<endl;

    while(x)
    {
        reverse_num <<= 1;
        reverse_num  |= x &1;
        x >>=1;
        cou--;
    }

    reverse_num <<= cou;
    cout<<reverse_num<<endl;
    return 0;
}
