#include<iostream>
#include<map>
#include<string>
using namespace std;
void permutations(string str,int cou[],int realCount,string Out = "")
{
    if(Out.size() == realCount)
    {
        cout<<Out<<endl;
        return;
    }
    for(int i=0;i<str.size();i++)
    {
        if(cou[i]==0)
            continue;
        Out = Out + str[i];
        cou[i]--;
        permutations(str,cou,realCount,Out);
        cou[i]++;
        Out = Out.substr(0,Out.size()-1);
    }
}
int main()
{
    string s;
    cin>>s;

    map<char,int> m;

    for(auto c : s)
    {
        m[c]++;
    }

    int cou[m.size()];

    string str = "";
    int i=0;
    for(auto c : m)
    {
        str = str + c.first;
        cou[i]=0;
        cou[i++]=c.second;
    }
    int realCount = s.size();
    permutations(str,cou,realCount);
}
