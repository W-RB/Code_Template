#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ls (k << 1)
#define rs (k << 1 | 1)

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

int n, m;
int a[MAXN];

struct Seg_Tree
{
	int l, r;
	int sum, lazy;
}tr[MAXN << 2];

inline void f(int k, int v)
{
	tr[k].lazy += v;
	tr[k].sum += v * (tr[k].r - tr[k].l + 1);
}

inline void pushup(int k)
{
	tr[k].sum = tr[ls].sum + tr[rs].sum;
}

inline void pushdown(int k)
{
	int mid = (tr[k].l + tr[k].r) >> 1;
	f(ls, tr[k].lazy);
	f(rs, tr[k].lazy);
	tr[k].lazy = 0;
}

void build(int k,int l, int r)
{
	tr[k].lazy = 0;
	tr[k].l = l;
	tr[k].r = r;
	if(l == r)
	{
		tr[k].sum = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(k);
}

void update(int k, int L, int R, int v)
{
	if(L <= tr[k].l && tr[k].r <= R)
	{
		f(k, v);
		return;
	}
	pushdown(k);
	int mid = (tr[k].l + tr[k].r) >> 1;
	if(L <= mid) update(ls, L, R, v);
	if(R > mid) update(rs, L, R, v);
	pushup(k);
}

int query(int k, int L, int R)
{
	int res = 0;
	if(L <= tr[k].l && tr[k].r <= R) return tr[k].sum;
	int mid = (tr[k].l + tr[k].r) >> 1;
	pushdown(k);
	if(L <= mid) res += query(ls, L, R);
	if(R > mid) res += query(rs, L, R);
	return res;
}

signed main()
{
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	build(1, 1, n);
	int temp;
	while(m--)
	{
		int x, y, q;
		scanf("%lld", &temp);
		if(temp == 1)
		{
			scanf("%lld%lld%lld", &x, &y, &q);
			update(1, x, y, q);
		}
		else
		{
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", query(1, x, y));
		}
	}
	return 0;
}