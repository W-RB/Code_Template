#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define int long long

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAXN = 1e6 + 7;

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

int a[MAXN], tr[MAXN << 1], tag[MAXN << 1];

int n, q, N;

void build()
{
    for(N = 1; N <= n + 1; N <<= 1);
    for(int i = 1; i <= n; i++) tr[N + i] = a[i];
    for(int i = N - 1; i >= 1; i--) tr[i] = tr[i << 1] + tr[i << 1 | 1];
}

void update(int l, int r, int v)
{
    int numl = 0, numr = 0, num = 1;
    for(l = N + l - 1, r = N + r + 1; l ^ r ^ 1; l >>= 1, r >>= 1, num <<= 1)
    {
        tr[l] += v * numl, tr[r] += v * numr;
        if(~l & 1) tag[l ^ 1] += v, tr[l ^ 1] += v * num, numl += num;
        if(r & 1) tag[r ^ 1] += v, tr[r ^ 1] += v * num, numr += num;
    }
    for(; l; l >>= 1, r >>= 1) tr[l] += v * numl, tr[r] += v * numr;
}

int query(int l, int r)
{
    int numl = 0, numr = 0, num = 1, ans = 0;
    for(l = N + l - 1, r = N + r + 1; l ^ r ^ 1; l >>= 1, r >>= 1, num <<= 1)
    {
        if(tag[l]) ans += tag[l] * numl;
        if(tag[r]) ans += tag[r] * numr;
        if(~l & 1) ans += tr[l ^ 1], numl += num;
        if(r & 1) ans += tr[r ^ 1], numr += num;
    }
    for(; l; l >>= 1, r >>= 1) ans += tag[l] * numl, ans += tag[r] * numr;
    return ans;
}

signed main()
{
    read(n, q);
    for(int i = 1; i <= n; i++) read(a[i]);
    build();
    while(q--)
    {
        int opt, x, y, k;
        read(opt);
        if(opt == 1) read(x, y, k), update(x, y, k);
        else read(x, y), printf("%lld\n", query(x, y));
    }
    return 0;
}