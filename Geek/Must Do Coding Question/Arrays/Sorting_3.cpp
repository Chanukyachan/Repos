#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[],int start,int end)
{
    int pivot = arr[end];
    int pIndex = start;

    for(int i=start;i<end;i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[pIndex],arr[i]);
            pIndex++;
        }
    }
    swap(arr[end],arr[pIndex]);

    return pIndex;
}

void QuickSort(int arr[],int start,int end)
{
    if(start < end)
    {
        int pIndex = partition(arr,start,end);
        QuickSort(arr,start,pIndex -1);
        QuickSort(arr,pIndex + 1,end);
    }
}

void print(int arr[],int end)
{
    for(int i=0;i<=end;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}
int main()
{
    int a[] = {9,8,18,6,71,82,3,2,1};
    cout<<"Before Sorting :";
    print(a,8);
    QuickSort(a,0,8);
    cout<<"After Sorting :";
    print(a,8);
   return 0;
}
