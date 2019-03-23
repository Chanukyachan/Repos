// Subarray with given sum

#include<iostream>
using namespace std;

void findSubArray(int arr[],int sum,int n)
{
    int start=1,i=2,curr_sum = arr[1],flag=0;
    while(i<=(n+1))
    {
        while(curr_sum > sum && start<i-1)
        {
            curr_sum -=arr[start];
            start++;
        }

        if(curr_sum == sum)
        {
            flag = 1;
            cout<<start<<" "<<i-1<<endl;
            break;
        }

        if(i<=n)
            curr_sum +=arr[i];

        i++;
    }
    if(flag==0)
        cout<<"-1"<<endl;
}
int main() {
	//code
	int testcases;
	cin>>testcases;

	while(testcases--)
	{
	    int numOfElements;
	    int sumReq;
	    cin>>numOfElements>>sumReq;
	    int arr[numOfElements];
	    for(int i=1;i<=numOfElements;i++)
	        cin>>arr[i];

	   findSubArray(arr,sumReq,numOfElements);
	}
	return 0;
}
