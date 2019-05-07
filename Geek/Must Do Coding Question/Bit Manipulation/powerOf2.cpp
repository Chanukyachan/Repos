#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int inp;

    int number;

    cin>>number;

    if(ceil(log2(number)) == floor(log2(number)))
    {
        cout<<"It is a power of 2"<<endl;
    }
    else
        cout<<"Not a power of 2"<<endl;


    cout<<ceil(6.7)<<endl;
    cout<<floor(6.7)<<endl;

    return 0;
}
