
#include<iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;

	while(t--)
	{
	    int num,total = 0;
	    cin>>num;
	    int arr[num];
	    for(int i=0;i<num;i++)
	    {
	        cin>>arr[i];
	        total = total + arr[i];
	    }
	    //cout<<total<<endl;
	    int right = 0;
	    int flag =0;
	    for(int j=num-1;j>=0;j--)
	    {
	        //cout<<right<<"  ==  "<<total - (arr[j]+right)<<endl;
	        if(right == total - (arr[j]+right))
	        {
	            cout<<j + 1<<endl;
	            flag = 1;
	        }

	        right = right + arr[j];

	    }
	    if(flag == 0 )
	        cout<<-1<<endl;
	}
	return 0;
}
