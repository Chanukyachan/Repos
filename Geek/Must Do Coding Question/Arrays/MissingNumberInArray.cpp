
#include<iostream>
using namespace std;

int main() {

	int testcase;
	cin>>testcase;

	while(testcase--)
	{
	    int numberOfElements;
	    cin>>numberOfElements;
	    int arr[numberOfElements-1];
	    int flag=0;
	    int sum = 0;
	    for(int i=0;i<(numberOfElements-1);i++)
	    {
	        cin>>arr[i];
	        sum = sum + arr[i];
	        flag++;
	    }
       int n = numberOfElements;
	   int total = (n*(n+1))/2;
	   //cout<<"Total :"<<total<<"  "<<"Sum : "<<sum<<endl;
	   cout<<total - sum<<endl;

	   //cout<<"Flag : "<<flag<<endl;
	}
	return 0;
}
