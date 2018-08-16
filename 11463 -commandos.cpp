#include <iostream>
#include <map>
#include <string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
#define pii pair<int,int>
map<int, int>mymap;
#define mx 105
#define inf 1000000
int mat[mx][mx],cost[mx][mx];
void set()
{
    for (int i = 0; i < mx; i++)
    {
        for (int j = 0; j < mx;j++)
        {
            if (i == j)
                cost[i][j] = 0;
            else
            cost[i][j] = inf;
        }
    }

}
void floyd_warshall(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++)
    {
        int n, m;
        cin >> n >> m;
        set();
        for (int i = 0; i < m; i++)
        {
            int x, y ;
            cin >> x >> y;
            mat[x][y] = mat[y][x] = 1;
            cost[x][y] = cost[y][x] = 1;
        }

        int src, dest;
        cin >> src >> dest;
        floyd_warshall(n);
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (cost[src][i] == 0 || cost[i][dest] == inf)
                continue;
            result = max(result, cost[src][i] + cost[i][dest]);
        }
        printf("Case %d: %d\n", cases, result);

    }
    return 0;
}
