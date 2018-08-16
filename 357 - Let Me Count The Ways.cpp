#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long way[30000+1];
    int coin[]={0,1,5,10,25,50};
    int k=5;
    memset(way,0,sizeof(way));
    way[0]=1;
    for(int j=1;j<=k;j++)
    {
        for(int i=1;i<=30000;i++)
        {
            if(i>=coin[j])
                way[i]+=way[i-coin[j]];
        }
    }
    int n;
    while(scanf("%d",&n)==1)
    {
        if(way[n]==1)
            printf("There is only 1 way to produce %d cents change.\n",n);
        else printf("There are %lld ways to produce %d cents change.\n",way[n],n);
    }

    return 0;
}
