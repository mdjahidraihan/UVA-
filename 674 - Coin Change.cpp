#include<bits/stdc++.h>
using namespace std;
int main()
{
    int way[7490];
    int coin[]={0,1,5,10,25,50};
    int k=5;
    memset(way,0,sizeof(way));
    way[0]=1;
    for(int j=1;j<=k;j++)
    {
        for(int i=1;i<=7489;i++)
        {
            if(i>=coin[j])
            way[i]+=way[i-coin[j]];

        }
    }
    int n;
    while(scanf("%d",&n)==1)
        printf("%d\n",way[n]);
    return 0;
}
