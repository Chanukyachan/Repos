//Normal Linked list creation without program assignment.

#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node* n)
{
    while(n != NULL)
    {
        cout<<n->data<<endl;
        n = n->next;
    }
}

int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head =(struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printList(head);
    return 0;
}
