#include<iostream>
#include <algorithm>//std::min_element, std::max_element
using namespace std;

void findMaxSubArray(int arr[],int n)
{
    int local_max = 0;
    int global_max = 0;
    //cout<<"n : "<<n<<endl;
    int flag = 0;
    for(int i=0 ; i <n ; i++)
    {
        local_max = local_max + arr[i];

        if(arr[i]<0)
        {
            flag++;
        }
        if(local_max < 0)
            local_max = 0;

        if(global_max < local_max)
            global_max = local_max;

    }
    if(flag == n)
    {
        global_max = *std::max_element(arr,arr+n);
    }

    cout<<global_max<<endl;

}
int main() {
	//code
	int testcases;
	cin>>testcases;

	while(testcases--)
	{
	    int numberOfElements;
	    cin>>numberOfElements;
	    int arr[numberOfElements];
	    for(int i=0;i<numberOfElements;i++)
	        cin>>arr[i];

	   findMaxSubArray(arr,numberOfElements);
	}
	return 0;
}
