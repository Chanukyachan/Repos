#include<iostream>
using namespace std;
#define CHARBIT 8
int main()
{
    int num;
    cin>>num;

    int const mask = num >> (sizeof(int) * 8 - 1);

    cout << ((num + mask) ^ mask)<<endl;
    return 0;
}
