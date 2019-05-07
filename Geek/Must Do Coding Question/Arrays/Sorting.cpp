#include<iostream>
using namespace std;
void bubblesort(int a[],int num)
{
    int swapped =1;
    for(int i=num-1;i>=0 && swapped;i--)
    {
        swapped = 0;
        for(int j=0;j<=i-1;j++)
        {
            if(a[j] > a[j+1])
            {
                a[j+1] = a[j]+a[j+1]-(a[j]=a[j+1]);
                swapped = 1;
            }
        }
    }
}

void selectionSort(int a[],int num)
{
    for(int i=0;i<num-1;i++)
    {
        int pos = i;
        for(int j=(i+1);j<num;j++)
        {
            if(a[j] < a[pos])
                pos = j;
        }
        a[pos] = a[i] +a[pos]-(a[i]=a[pos]);
    }
}

void insertionSort(int a[],int num)
{
    for(int i=1;i<num;i++)
    {
        int value = a[i];
        int hole = i;

        while(hole > 0 && a[hole-1] > value)
        {
            a[hole] = a[hole-1];
            hole--;
        }
        a[hole]=value;
    }
}


void printAll(int a[],int num)
{
    for(int i=0;i<num;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    int a[] = {9,8,7,6,5,4,3,2,1};
    int num = 9;
    cout<<"Bubble Sort :";
    bubblesort(a,num);
    printAll(a,num);

    int b[] = {9,8,7,6,5,4,3,2,1};
    cout<<"Selection Sort :";
    selectionSort(b,num);
    printAll(b,num);

    int c[] = {9,8,7,6,13,4,3,2,1};
    cout<<"Insertion Sort :";
    insertionSort(c,num);
    printAll(c,num);

    return 0;
}
