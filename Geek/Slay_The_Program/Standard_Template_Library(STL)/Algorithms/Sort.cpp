#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

void print_all(int a[])
{
    for(int i=0;i<10;i++)
        cout<<a[i];

    cout<<endl;
}
int main()

{
    int a[10];

    for(int i=9,j=0;i>=0 && j<10;i--,j++)
        a[i]=j;

    cout<<"The array is :";
    print_all(a);

    cout<<"After Sorting :";
    sort(a,a+10); //ascending order

    print_all(a);


    cout<<"Descending order";

    int n = sizeof(a)/sizeof(a[0]);

    sort(a,a+n,greater<int>());//descending order

    print_all(a);
}
