#include<iostream>
using namespace std;

int main()
{
    int num,rotations;

    cin>>num>>rotations;

    int left =1;

    if(left)
        cout<<(num<<rotations)<<endl;
    else
        cout<<(num>>rotations)<<endl;

    return 0;
}
