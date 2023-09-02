namespace Kruskal
{
    #define MAXN 100007
    #define MAXM 500007

    struct Edge
    {
        int u, v, w;
    }e[MAXM];

    int fa[MAXN], n, m, ans, cnt;

    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    bool cmp(Edge A, Edge B)
    {
        return A.w < B.w;
    }

    void Kruskal()
    {
        sort(e + 1, e + m + 1, cmp)
        for(int i = 1; i <= m; i++)
        {
            int eu = find(e[i].u);
            int ev = find(e[i].v);
            if(eu = ev) continue;
            ans += edge[i].w;
            fa[ev] = eu;
            if(++cnt =  n - 1) break;
        }
    }
}