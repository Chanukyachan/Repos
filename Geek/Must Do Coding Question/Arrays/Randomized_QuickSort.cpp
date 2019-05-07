#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
    srand(time(0));
    int low = 0;
    int high = 9;
    int random = low + rand()%(2-0);

    cout<<random<<endl;
}
