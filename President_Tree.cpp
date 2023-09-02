#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define ls(k) tr[k].lson
#define rs(k) tr[k].rson

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 7;

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

struct Node
{
    int lson, rson;
    int val;
}tr[MAXN << 5];

int rt[MAXN << 5], a[MAXN], b[MAXN];

int cnt, n, m, q;

void build(int &k, int l, int r)
{
    if(!k) k = ++cnt;
    if(l == r) return;
    int mid = l + r >> 1;
    build(ls(k), l, mid);
    build(rs(k), mid + 1, r);
}

int update(int k, int l, int r, int v)
{
    int nk = ++cnt;
    tr[nk] = tr[k], tr[nk].val++;
    if(l == r) return nk;
    int mid = l + r >> 1;
    if(v <= mid) ls(nk) = update(ls(nk), l, mid, v);
    else rs(nk) = update(rs(nk), mid + 1, r, v);
    return nk;
}

int query(int x, int y, int l, int r, int v)
{
    if(l == r) return l;
    int mid = l + r >> 1;
    int num = tr[ls(y)].val - tr[ls(x)].val;
    if(num >= v) return query(ls(x), ls(y), l, mid, v);
    else return query(rs(x), rs(y), mid + 1, r, v - num);
}

signed main()
{
    read(n, q);
    for(int i = 1; i <= n; i++)
    {
        read(a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    m = unique(b + 1, b + 1 + n) - b - 1;
    build(rt[0], 1, m);
    for(int i = 1; i <= n; i++)
    {
        int t = lower_bound(b + 1, b + 1 + m, a[i]) - b;
        rt[i] = update(rt[i - 1], 1, m, t);
    }
    while(q--)
    {
        int x, y, z;
        read(x, y, z);
        printf("%d\n", b[query(rt[x - 1], rt[y], 1, m ,z)]);
    }
    return 0;
}