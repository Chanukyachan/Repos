#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main()
{
    int a[] = {1,2,3,4,5,6};

    deque<int> dq(a,a+6);
    deque<int>::iterator j;
    deque<int>::iterator i;

    for(j = dq.begin();j!=dq.end();j++)
        cout<<*j<<" ";
    cout<<endl;

    dq.push_back(7);
    cout<<"push_back :";
    for(j = dq.begin();j!=dq.end();j++)
        cout<<*j<<" ";
    cout<<endl;

    dq.push_front(0);
    cout<<"push_front:";
    for(j = dq.begin();j!=dq.end();j++)
        cout<<*j<<" ";
    cout<<endl;

    i = dq.begin()+2;

    dq.insert(i,15);

    for(j = dq.begin();j!=dq.end();j++)
        cout<<*j<<" ";
    cout<<endl;

    int b[] = {4,4,4,4,4};

    dq.insert(dq.begin(),b,b+5);

    for(j = dq.begin();j!=dq.end();j++)
        cout<<*j<<" ";
    cout<<endl;

    dq.pop_back();

    for(j = dq.begin();j!=dq.end();j++)
        cout<<*j<<" ";
    cout<<endl;

    dq.pop_front();


    for(j = dq.begin();j!=dq.end();j++)
        cout<<*j<<" ";
    cout<<endl;

}
