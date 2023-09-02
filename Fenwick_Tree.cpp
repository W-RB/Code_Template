#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ppb pop_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

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

int n, m;

int a[MAXN], t[MAXN];

int lowbit(int x){return x & (-x);}

void update(int k, int x)
{
    while(k <= n) t[k] += x, k += lowbit(k);
}

int query(int k)
{
    int res = 0;
    while(k) res += t[k], k -= lowbit(k);
    return res;
}

signed main()
{
    read(n, m);
    for(int i = 1; i <= n; i++) read(a[i]), update(i, a[i]);
    while(m--)
    {
        int op, x, y;
        read(op, x, y);
        if(op == 1) update(x, y);
        else printf("%d\n", query(y) - query(x - 1));
    }
    return 0;
}