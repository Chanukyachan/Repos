#include<iostream>
using namespace std;
void revRecursion(string a,int i)
{

    if(i<a.length())
    {
        i++;
        revRecursion(a,i);
        cout<<a[i-1];
    }

}
int main()
{
    string a;
    cin>>a;
    int length = a.length();
    revRecursion(a,0);
    return 0;
}
