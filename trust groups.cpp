#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define rev1(i,n) for(i=n;i>=1;i--)
#define REP(i,a,b) for(i=a;i<b;i++)
#define REP1(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define pq priority_queue
#define mem(i,n) memset(i,n,sizeof(i))
#define Fill(ar,siz,val) fill(ar,ar+siz,val)
#define eps 1e-7
#define INF 2000000000L
#define debug printf("here\n")
#define sz size()
#define em empty()
#define cl clear()
#define fi first
#define se second
#define Sort(v) sort( v.begin(),v.end() )


/*Knight direction*/
long kx[]={2,-2,2,-2,1,-1,1,-1};
long ky[]={1,1,-1,-1,2,2,-2,-2};
/*4 & 8 move direction*/
long dx[]={1,-1,0,0,1,-1,1,-1};
long dy[]={0,0,1,-1,1,1,-1,-1};
/*for 3-D move*/
//long dx[]={1,-1,0,0,0,0};
//long dy[]={0,0,1,-1,0,0};
long dz[]={0,0,0,0,1,-1};
//#define check(c,a,b,l,row,column) ( (c>=0 && c<l) && (a>=0 && a<row) && //(b>=0&&b<column))
//#define check(a,b,row,column) ((a>=0 && a<row) && (b>=0 && b<column))

/*Bit Mask DP Macros*/
#define Set(n,pos) ( n | (1<<pos) )
#define reset(n,pos) (n & (~(1<<pos)))
#define check(n,pos) ((bool)(n&(1<<pos)))

/*input && output*/
#define sf3(x,y,z) scanf("%ld %ld %ld",&x,&y,&z)
#define sf2(x,y) scanf("%ld %ld",&x,&y)
#define sf1(x) scanf("%ld",&x)
#define pf2(x,y) printf("%ld %ld\n",x,y)
#define pf1(x) printf("%ld\n",x)
#define NL puts("")
/*typedef*/
typedef long L;
typedef long long LL;
typedef pair<string,string> pll;
typedef vector <L> vl;
typedef map < string, L > msl;
typedef map < L,string > mls;
typedef map < char, L > mcl;
typedef map < L,char > mlc;
typedef map < L, L > mll;
typedef queue <L> Queue;
typedef vector <string> vs;
typedef vector <pll> vp;
#define mx 1009
vl g[mx],trans[mx];
bool vis[mx];
stack <L> vec;
void dfs(L src)
{
    vis[src]=1;
    L i,y,siz=g[src].sz;
    rep(i,siz)
    {
        y=g[src][i];
        if(vis[y]==0)
        {
            dfs(y);
        }
    }
    vec.push(src);
}
void dfs1(L src)
{
    vis[src]=1;
    L i,y,siz=trans[src].sz;
    rep(i,siz)
    {
        y=trans[src][i];
        if(vis[y]==0)
        {
            dfs1(y);
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    L x,y,z,i,j,k,l,m,n,p,q,r,u,v,w,t,cas,edge,node,a,b,c,d,e,f,ans,cnt,ass;
    while(sf2(node,edge)==2)
    {
        if(!node && !edge) break;
        map <pll,L> ma;
        ass=0;
        rep(i,node)
        {
            string s1,s2;
            cin>>s1>>s2;
            s1.erase(s1.sz-1,s1.sz-1);
            ma[ pll(s1,s2) ]=ass++;

        }
        node=ass;
        rep(i,edge)
        {
            string s1,s2,s3,s4;
            cin>>s1>>s2;
            s1.erase(s1.sz-1,s1.sz-1);
            cin>>s3>>s4;
            s3.erase(s3.sz-1,s3.sz-1);

            u=ma[ pll(s1,s2) ];
            v=ma[ pll(s3,s4) ];
            g[u].pb(v);
            trans[v].pb(u);
        }
        mem(vis,0);
        rep(i,node)
        {
            if(vis[i]==0)
            {
                dfs(i);
            }
        }
        mem(vis,0);
        cnt=0;
        while(!vec.em)
        {
            y=vec.top();
            vec.pop();
            if(vis[y]==0)
            {
                dfs1(y);
                cnt++;
            }
        }
        pf1(cnt);

        rep(i,node)
        {
            g[i].cl;
            trans[i].cl;
        }
    }

    return 0;
}






