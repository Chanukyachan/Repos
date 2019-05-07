#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

int main()
{
    int n;
    printf("Enter the number : \n");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        createNode()
    }
    return 0;
}
