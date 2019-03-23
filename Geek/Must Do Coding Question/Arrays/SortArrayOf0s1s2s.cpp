
#include<iostream>
using namespace std;

int main() {
	//code
	int testcase;
	cin>>testcase;
	while(testcase--)
	{
	    int number;
	    cin>>number;
	    int flag0=0,flag1=0,flag2=0;
	    int arr[number];
	    for(int i=0;i<number;i++)
	    {
	        cin>>arr[i];
	        if(arr[i]==0)
	            flag0++;

	        if(arr[i]==1)
	            flag1++;

	        if(arr[i]==2)
	            flag2++;
	    }
	    for(int j=1;j<=flag0;j++)
	        cout<<"0"<<" ";
	    for(int j=1;j<=flag1;j++)
	        cout<<"1"<<" ";
	    for(int j=1;j<=flag2;j++)
	        cout<<"2"<<" ";

	  cout<<endl;
	}
	return 0;
}
