#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    string s = "CHANUKYA";
    sort(s.begin(),s.end());
    for(auto c : s)
        cout<<c;
    return 0;

}
