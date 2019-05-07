///377 10 174 504 888 255 674 58 482 824 930 397 45 943 281 13 210 856 748 855 367 135 760 282 743 974 402 639 172 414 959 900 423 485 756 662 91 781 72 924 604 1 321 1 943 953 13 505 808 760 359 526 895 118 159 637 91 561 627 615 974 938 866 749 422 621 410 864 401

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	//code
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

	    int first_min,second_min;
	    first_min = arr[0];
	    second_min = arr[1];

        int printFlag = 1;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i] == arr[i+1])
            {
                continue;
            }
            else
            {
                cout<<arr[i]<<" "<<arr[i+1]<<endl;
                printFlag = 0;
                break;
            }

        }
        if(printFlag)
            cout<<"-1"<<endl;
	}

	return 0;
}
