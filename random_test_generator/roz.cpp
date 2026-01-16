#include <bits/stdc++.h>

using namespace std;

const int N = 300100;

vector<vector<int>> g(N);

int dis[N];
int ans[N][20];

void dfs(int s, int p)
{
    ans[s][0] = p;
    dis[s]= dis[p] + 1;
    for(auto u : g[s]) if(u!=p)
    {
        dfs(u,s);
    }
}

void comAns(int n)
{
    for(int i = 1; i < 20; i ++)
        for(int j = 1; j <=n ;j ++)
            ans[j][i] = ans[ans[j][i-1]][i-1];
}

int lca(int a, int b)
{
    if(dis[a] > dis[b])
        swap(a,b);
    for(int i = 19 ;i >= 0; i --)
    {
        if(dis[ans[b][i]]>=dis[a])
            b = ans[b][i];
    }
    if(a==b)
        return a;
    for(int i = 19 ;i >=0 ;i --)
    {
        if(ans[a][i] != ans[b][i])
        {
            a = ans[a][i];
            b = ans[b][i];
        }
    }
    return ans[a][0];
}

int disAns(int x, int y)
{
    if(x < y)
        swap(x,y);
    return dis[x]-dis[y];
}

int solve1(int a, int b)
{
    if(dis[a] > dis[b])
        swap(a,b);
    int r = 0;
    while(dis[b]>dis[a])
    {
        r++;
        b=ans[b][0];
    }
    while(a!=b)
    {
        r+=2;
        a=ans[a][0];
        b=ans[b][0];
    }
    return r;
}

int solve2(int a, int b)
{
        int l = lca(a,b);
        return disAns(a,l) + disAns(l,b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i < n; i ++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    comAns(n);
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(n <= 1000 && q <= 1000)
                cout<<solve1(x,y)<<'\n';
        else
                cout<<solve1(x,y)<<'\n';
    }
}