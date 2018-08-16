#include<cstdio>
#include<cstring>
using namespace std;

#define mx 5001
long long dp[mx];
long long f(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    else return dp[n] = f(n-1)+f(n-2);

}
int main()
{

    memset(dp,-1,sizeof(dp));
    dp[1]=1;
    f(5000);
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("The Fibonacci number for %d is %lld\n",n,dp[n]);
    }
    return 0;
}
