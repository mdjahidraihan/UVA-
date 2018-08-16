#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long way[10000];
    long long coin[22];
    memset(way,0,sizeof(way));
    for(int i=1;i<=21;i++)
        coin[i]=i*i*i;
    way[0]=1;
    //int coin[]={1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,}
    for(int i=1;i<=21;i++)
    {
        for(int j=1;j<=10000;j++)
            if(j>=coin[i])
                way[j]+=way[j-coin[i]];
    }
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%lld\n",way[n]);
    }
    return 0;
}
