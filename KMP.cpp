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

const int MAXN = 1e6 + 7;

string T, S;
string Str;
int pi[MAXN << 1];
int nxt[MAXN];

void get_nxt()
{
    pi[0] = 0;
    int n = Str.length();
    for(int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while(j > 0 && Str[i] != Str[j + 1]) j = pi[j];
        if(Str[i] == Str[j + 1] && j + 1 < i) pi[i] = j + 1;
    }
}

void get_nxt_S()
{
    nxt[0] = 0;
    int n = S.length();
    for(int i = 1; i < n; i++)
    {
        int j = nxt[i - 1];
        while(j > 0 && S[i] != S[j + 1]) j = nxt[j];
        if(S[i] == S[j + 1] && j + 1 < i) nxt[i] = j + 1;
    }
}

int main()
{
    cin >> T >> S;
    Str = " " + S + "#" + T;
    get_nxt();
    for(int i = S.length() + 1; i < Str.length(); i++)
    {
        if(pi[i] == S.length()) printf("%d\n", i - S.length() - S.length());
    }
    S = " " + S;
    get_nxt_S();
    for(int i = 1; i < S.length(); i++)
        printf("%d ", nxt[i]);
    return 0;
}