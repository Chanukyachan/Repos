#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;

	while(t--)
	{
	    int num;
	    cin>>num;
	    int arr[num];
	    int arrMax[num];
	    for(int i=0;i<num;i++)
	    {
	        cin>>arr[i];
	        arrMax[i] = arr[i];
	    }

	    for(int i=1;i<num;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(arr[i] > arr[j] && arrMax[i] < (arr[i]+arrMax[j]))
	            {
	                arrMax[i] = arrMax[j] + arr[i];
	            }
	        }
	    }

	    cout<<*std::max_element(arrMax,arrMax+num)<<endl;
	}
	return 0;
}
