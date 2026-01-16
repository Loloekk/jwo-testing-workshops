#include <bits/stdc++.h>

using namespace std;

const int N = 300100;

vector<vector<int>> g(N);

int dis[N];
int par[N];

void dfs(int s, int p)
{
    par[s] = p;
    dis[s]= dis[p] + 1;
    for(auto u : g[s]) if(u!=p)
    {
        dfs(u,s);
    }
}

int solve(int a, int b)
{
    if(dis[a] > dis[b])
        swap(a,b);
    int r = 0;
    while(dis[b]>dis[a])
    {
        r++;
        b=par[b];
    }
    while(a!=b)
    {
        r+=2;
        a=par[a];
        b=par[b];
    }
    return r;
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
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<solve(x,y)<<'\n';
    }
}