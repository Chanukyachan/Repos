#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void printfn(struct Node* newHead)
{
    struct Node* CurrentHead = newHead;
    int counter=0;
    while(CurrentHead != NULL)
    {
        counter++;
        printf("%d  %d \n",CurrentHead->data,counter);
        CurrentHead =  CurrentHead->next;
    }
}
int main()
{
    struct Node *Head = NULL;
    Head = (struct Node*)malloc(sizeof(struct Node));

    struct Node *First = NULL;
    First = (struct Node*)malloc(sizeof(struct Node));

    struct Node *Second = NULL;
    Second = (struct Node*)malloc(sizeof(struct Node));

    Head->data = 10;
    Head->next = First;
    First->data = 20;
    First->next = Second;
    Second->data = 30;
    Second->next = NULL;
    printfn(Head);
    return 0;
}
