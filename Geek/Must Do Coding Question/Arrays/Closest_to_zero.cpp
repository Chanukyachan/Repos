#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        sort(arr,arr+n);
        int sum,min_sum = INT_MAX;
        int l = 0, r = n-1;
        int min_l = l,min_r = r;
        while(l < r)
        {
            sum = arr[l]+arr[r];
            if(abs(sum) < abs(min_sum))
            {
                min_sum = sum;
                min_l = l;
                min_r = r;
            }

            if(sum < 0)
                l++;
            else
                r--;

        }

        cout<<arr[min_l]<<" "<<arr[min_r]<<endl;
    }

}
