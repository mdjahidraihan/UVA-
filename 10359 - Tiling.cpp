#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int f(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    else return dp[n]=2*f(n-1)+f(n-2);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cout<<f(8)<<endl;
    return 0;
}
