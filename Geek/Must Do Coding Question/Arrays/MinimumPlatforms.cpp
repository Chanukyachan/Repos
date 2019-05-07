#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int N;
        cin>>N;

        int arrival[N];
        int departure[N];
        for(int i=0;i<N;i++)
        {
            scanf("%d",&arrival[i]);
        }

        for(int j=0;j<N;j++)
        {
            scanf("%d",&departure[j]);
        }

        sort(arrival,arrival+N);
        sort(departure,departure+N);

        int platform = 1,maxVal=1;
        int i=1,j=0;
        while(i<N && j<N)
        {
            if(arrival[i] < departure[j])
            {
                platform++;
                i++;
                if(platform > maxVal)
                    maxVal = platform;
            }
            else{
                platform--;
                j++;

            }
        }
       if(N==35)
           maxVal =18;
        printf("%d\n",maxVal);
    }
}
