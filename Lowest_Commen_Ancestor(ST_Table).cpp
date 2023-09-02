#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template <class T>
T read(T &num) {
    T    x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0') {
        if (ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + ch - '0';
        ch = getchar();
    }
    num = x * f;
    return num;
}

const int N = 500000 + 10;

struct edge{
    int v, next;
}e[N << 1];

int h[N], tot;
int n, m, s, cnt;
int dep[N << 1], fir[N], dfn[N << 1];
int f[N << 1][20];
bool vis[N];

void dfs(int u, int de){
    ++cnt;
    fir[u] = cnt;
    dep[cnt] = de;
    dfn[cnt] = u;
    vis[u] = true;
    for(int i = h[u]; i; i = e[i].next){
        int v = e[i].v;
        if(vis[v]) continue;
        dfs(v, de + 1);
        ++cnt;
        dep[cnt] = de;
        dfn[cnt] = u;
    }
}

void pre_solve(){
    for(int i = 1; i <= cnt; i++) {
        f[i][0] = i;
    }
    for(int j = 1; j <= 20; j++){
        for(int i = 1; i + (1 << j) - 1 <= cnt; i++){
            int x = f[i][j - 1], y = f[i + (1 << (j - 1))][j - 1];
            f[i][j] = dep[x] < dep[y] ? x : y;
        }
    }
}

void add_edge(int u, int v){
    e[++tot].v = v;
    e[tot].next = h[u];
    h[u] = tot;
}

int lca(int x, int y){
    if(fir[x] > fir[y]) swap(x, y);
    int s = fir[x], t = fir[y];
    int tmp = log2(t - s + 1);
    x = f[s][tmp], y = f[t - (1 << tmp) + 1][tmp];
    return dep[x] < dep[y] ? dfn[x] : dfn[y];
}

signed main() {
    memset(vis, false, sizeof vis);
    read(n), read(m), read(s);
    for(int i = 1; i < n; i++) {
        int x, y;
        read(x), read(y);
        add_edge(x, y);
        add_edge(y, x);
    }
    dfs(s, 0);
    // for(int i = 1; i <= n * 2 + 1; i++){
    //     printf("%lld ", dfn[i]);
    // }
    pre_solve();
    while(m--){
        int x, y;
        read(x), read(y);
        printf("%lld\n", lca(x, y));
    }
    return 0;
}
