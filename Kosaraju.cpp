#include<bits/stdc++.h>
using namespace std;

#define pb push_back

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)){if(ch == '-')f = -1; ch = getchar();}
    while(isdigit(ch))x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
template<typename T>
void read(T &x){
    x = 0; T f = 1;
    char ch = getchar();
    while(!isdigit(ch)){if(ch == '-')f = -1; ch = getchar();}
    while(isdigit(ch))x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
}
template<typename T, typename... Args>
void read(T &x, Args &...args){read(x),read(args...);}

const int MAXN = 5e5 + 7;

int n, m, scccnt;
vector<int> e1[MAXN], e2[MAXN], pt[MAXN];
int s[MAXN], top;
bool vis[MAXN];
int scc[MAXN], siz[MAXN];

void dfs1(int u)
{
    vis[u] = true;
    for(auto v : e1[u])
       if(!vis[v]) dfs1(v);
    s[++top] = u;
}

void dfs2(int u)
{
    scc[u] = scccnt;
    siz[scccnt]++;
    for(auto v : e2[u])
        if(!scc[v]) dfs2(v);
}

void Kosaraju()
{
    scccnt = 0, top = 0;
    for(int i = 1; i <= n; i++)
        if(!vis[i]) dfs1(i);
    for(int i = n; i >= 1; i--)
    {
        if(!scc[s[i]])
        {
            ++scccnt;
            dfs2(s[i]);
        }
    }
}

int main()
{
    read(n, m);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        read(u, v);
        e1[u].pb(v);
        e2[v].pb(u);
    }
    Kosaraju();
    for(int i = 1; i <= n; i++)
    {
        pt[scc[i]].push_back(i);
    }
    printf("%d\n", scccnt);
    for(int i = 1; i <= scccnt; i++)
    {
        printf("%d ", siz[i]);
        for(auto j : pt[i])
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}