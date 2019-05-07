#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void createNode(struct Node* getHead,int num)
{
    struct Node* copyHead = getHead;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;
    temp->next = NULL;

    if(getHead == NULL)
    {
        getHead->next = temp;
    }
    else
    {
            while(copyHead->next != NULL)
                copyHead = copyHead->next;

            copyHead->next = temp;
    }

}

void insertFront(struct Node* getHead,int data)
{
        struct Node* copyHead = getHead;
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        struct Node* tempHold = (struct Node*)malloc(sizeof(struct Node));


        temp->data = data;
        temp->next = NULL;

        if(getHead->next == NULL)
        {
            getHead->next = temp;
        }
        else
        {
            tempHold->next = getHead->next;
            temp->next = tempHold->next;
            getHead->next = temp;
        }
}

void printAllNodes(struct Node* recHead)
{
    cout<<endl;
    struct Node* tempHead = recHead;
    while(tempHead != NULL)
    {
        cout<<tempHead->data<<endl;
        tempHead = tempHead->next;
    }
}
int main()
{
    struct Node* head=NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        int data;
        cout<<"Enter Data :"<<endl;
        cin>>data;
        insertFront(head,data);
    }
    printAllNodes(head);
    return 0;
}
