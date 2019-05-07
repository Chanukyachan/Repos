#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        int remainder = n%k;
        int multiple = n/k;

        for(int i=1;i<=multiple;i++)
        {
            for(int j=k*i;j>((k*i)-k);j--)
                cout<<arr[j]<<" ";
        }
        if(remainder!=0)
        {
            for(int i=n;i>(n-remainder);i--)
                cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
