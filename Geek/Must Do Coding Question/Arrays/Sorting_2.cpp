#include<iostream>
using namespace std;
void merge(int a[],int l,int m,int r)
{
    int nL = m-l+1;
    int nR = r-m;
    int i=0,j=0,k=0;
    int left[nL],right[nR];
    for(int i=0;i<nL;i++)
        left[i]=a[i+l];
    for(int j=0;j<nR;j++)
        right[j]=a[j+m+1];

    i=0;j=0;k=l;

    while(i<nL && j<nR)
    {
        if(left[i]<=right[j])
        {
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<nL)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while(j<nR)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int a[],int l,int r)
{
    if(l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(a,l,m);

        mergeSort(a,m+1,r);

        merge(a,l,m,r);
    }

}

int main()
{
    int a[] = {5,4,12,2,1};

    mergeSort(a,0,4);
    for(int i=0;i<5;i++)
    cout<<a[i]<<" ";

}
