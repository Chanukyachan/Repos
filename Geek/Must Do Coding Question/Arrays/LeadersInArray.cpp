#include<iostream>
using namespace std;


//*memory efficient  0.68 SEC
void fn(int arr[],int num,int max)
{
    int flag=0;

	for(int i=num;i>=0;i--)
	{
	    flag++;

	    if(max <= arr[i])
	    {
	       max = arr[i];

	       fn(arr,(num-flag),max);

	       cout<<max<<" ";

	       break;
	    }
	 }


}
int main() {
	//code
	int t;
	cin>>t;

	while(t--)
	{
	    int num;
	    cin>>num;
	    int arr[num];
	    int arr2[num];
	    for(int i=0;i<num;i++)
	        cin>>arr[i];

	   // memory efficient 0.68 SEC
	    int max = 0;
	    fn(arr,num-1,max);
	    cout<<endl;
	 }

	return 0;
}
