#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void pushFront(struct Node** headRef,int newData)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

void print(struct Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<"-->";
        n = n->next;
    }
}

int main()
{
    struct Node* head = NULL;
    int n,num;
    cout<<"# numbers to be entered : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the number "<<i+1<<" :";
        cin>>num;
        pushFront(&head,num);
        print(head);
        cout<<endl;
    }
    return 0;
}
