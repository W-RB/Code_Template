#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

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

const int MAXN = 1e5 + 7;
const int INF = 1e9 + 7;

int n, m, s;
vector<pii> e[MAXN];
int dis[MAXN];
bool vis[MAXN];
priority_queue<pii> q;

void Dijkstra(int s)
{
    for(int i = 0; i <= n + 1; i++) dis[i] = INF, vis[i] = false;
    q.push(mp(0, s));
    dis[s] = 0;
    while(!q.empty())
    {
        int u = q.top().se;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto i : e[u])
        {
            int v = i.fi, w = i.se;
            if(dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if(!vis[v]) q.push(mp(-dis[v], v));
            }
        }
    }
}

int main()
{
    read(n, m, s);
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        read(u, v, w);
        e[u].pb(mp(v, w));
    }
    Dijkstra(s);
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", dis[i]);
    }
    return 0;
}