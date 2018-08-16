#include<bits/stdc++.h>
using  namespace std;
#define mx 100
vector<vector<int>>edge;
vector<int >cost[mx];
int dp[mx][mx];
int call(int u)
{
    if(u==src) return 0;
    if(u==dest) return;
    if(dp[u]!=-1) return dp[u];
    int ans = 1000000;
    for(int i=0;i<egde[u].size();i++)
    {
        int v = edge[u][i];
        ans=min(ans,dp[u]+cost[u][v]);


    }
      return dp[u] =  ans;
}
int main()
{

    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
        edge[x].push_back(w);
        edge[y].push_back(w);
    }

}
