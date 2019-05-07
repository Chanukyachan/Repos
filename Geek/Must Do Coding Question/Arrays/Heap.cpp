#include<iostream>
using namespace std;
///Heap Declaration
struct Heap{
    int *arr;
    int number;///number of elements in heap
    int capacity;///size of the heap
    int heap_type;///Min Heap or Max Heap
};
///Creating a Heap
struct Heap *CreateHeap(int capacity,int heap_type)///O(1)
{
    struct Heap *h = (struct Heap *)malloc(sizeof(struct Heap));

    if(h==NULL)
    {
        cout<<"Memory Error";
        return;
    }
    h->heap_type = heap_type;
    h->number = 0;
    h->capacity = capacity;

    h->arr = (int *)malloc(sizeof(int)*h->capacity);

    if(h->arr == NULL)
    {
        cout<<"Memory Error";
        return;
    }

    return h;
}

int parent(struct Heap *h,int i)///O(1)
{
    if(i<=0 || i >= h->number)
        return -1;

    return i-1/2;
}

int leftChild(struct Heap *h,int i)
{
    int left = 2*i + 1;

    if(left >= h->number)
        return -1;

    return left;
}

int rightChild(struct Heap *h,int i)
{
    int right = 2*i +2;
    if(right >= h->number)
        return -1;

    return right;
}

int getMaxElement(struct Heap *h)
{
    if(h->number == 0)
        return -1;

    return h->arr[0];
}

void PercolateDown(struct Heap *h,int i)///O(Log n)
{
    int L,R,Max,temp;
    L = leftChild(h,i);
    R = rightChild(h,i);

    if(L != -1 && h->arr[L] > h->arr[i])
        Max = L;
    else
        Max = i;
    if(R != -1 && h->arr[R] > h->arr[i])
        Max = R;


    if(Max != i)
    {
        temp = h->arr[i];
        h->arr[i] = h->arr[Max];
        h->arr[Max] = temp;
    }

    PercolateDown(h,Max);
}

