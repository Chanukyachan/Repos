#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=1;i<=n;i++)
	        cin>>arr[i];

	    for(int i=1;i<=n-(k-1);i++)
	    {
	        int max=0;

	        for(int j=i;j<i+k;j++)
	        {
	            if(arr[j] > max)
	                max = arr[j];
	        }
	        cout<<max<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
