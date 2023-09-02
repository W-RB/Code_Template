#include<bits/stdc++.h>
using namespace std;

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

struct edge
{
    int to, nxt;
}e[MAXN];

int head[MAXN], cnt, dfncnt, scccnt;
int dfn[MAXN], low[MAXN];
int scc[MAXN], siz[MAXN];
vector<int> pt[MAXN];
bool vis[MAXN];
stack<int> st;

void add_edge(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

void Tarjan(int u)
{
    low[u] = ++dfncnt;
    dfn[u] = dfncnt;
    st.push(u);
    vis[u] = true;
    for(int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].to;
        if(!dfn[v])
        {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(vis[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u])
    {
        ++scccnt;
        while(st.top() != u)
        {
            scc[st.top()] = scccnt;
            siz[scccnt]++;
            vis[st.top()] = false;
            st.pop();
        }
        scc[st.top()] = scccnt;
        siz[scccnt]++;
        vis[st.top()] = false;
        st.pop();
    }
}


int n, m;

int main()
{
    read(n, m);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        read(u, v);
        add_edge(u, v);
    }
    for(int i = 1; i <= n; i++)
    {
		if(!dfn[i])
        {
			Tarjan(i);
		}
    }
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