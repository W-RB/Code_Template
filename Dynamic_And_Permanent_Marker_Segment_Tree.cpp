#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define ls tr[k].lson
#define rs tr[k].rson

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

const int MAXN = 1e5 + 7;

int n, q, x;
int cnt, rt;
int a[MAXN];

struct Seg_Tree
{
	int sum, tag;
	int lson, rson;
}tr[MAXN << 1];

void update(int &k, int l, int r, int L, int R, int v)
{
	if(!k) k = ++cnt;
	if(L <= l && r <= R) return (void)(tr[k].tag += v);
	tr[k].sum += v * (min(R, r) - max(L, l) + 1);
	int mid = l + r >> 1;
	if(L <= mid) update(ls, l, mid, L, R, v);
	if(R > mid) update(rs, mid + 1, r, L, R, v);
}

int query(int k, int l, int r, int L, int R)
{
	if(!k) return 0;
	if(L <= l && r <= R) return tr[k].sum +(r - l + 1) * tr[k].tag;
	int res = (min(R, r) - max(L, l) + 1) * tr[k].tag;
	int mid = l + r >> 1;
	if(L <= mid) res += query(ls, l, mid, L, R);
	if(R > mid) res += query(rs, mid + 1, r , L, R);
	return res;
}

signed main()
{
	read(n, q);
	rt = 1, cnt = 1;
	tr[rt] = {0, 0, 0, 0};
	for(int i = 1; i <= n; i++) read(x), update(rt, 1, n, i, i, x);
	while(q--)
	{
		int opt, l, r, v;
		read(opt, l, r);
		if(opt == 1) read(v), update(rt, 1, n, l, r, v);
		else printf("%lld\n", query(rt, 1, n, l, r));
	}
	return 0;
}