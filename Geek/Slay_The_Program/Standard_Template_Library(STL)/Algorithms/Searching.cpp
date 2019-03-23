#include<iostream>
#include<algorithm>
using namespace std;

void print_all(int a[],int arrSize)
{
    for(int i=0;i<arrSize;i++)
        cout<<a[i];
    cout<<endl;
}
int main()
{
    int arr[10];
    for(int i=0;i<10;i++)
        arr[i] = i;
    cout<<"Before Sorting";
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    print_all(arr,arrSize);
    sort(arr,arr+arrSize);
    cout<<"After Sorting:";
    print_all(arr,arrSize);

    if(binary_search(arr,arr+arrSize,5))
        cout<<" 5 Found"<<endl;
    else
        cout<<"5  Not Found"<<endl;

    if(binary_search(arr,arr+arrSize,12))
        cout<<" 12 Found"<<endl;
    else
        cout<<"12  Not Found"<<endl;

    return 0;
}
