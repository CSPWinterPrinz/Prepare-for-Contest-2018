#include <bits/stdc++.h>
#define N 10124
#define pc putchar
#define gc getchar

using namespace std;

inline void read(long long &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for (;((c<48 || c>57) && c != '-') ;c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

inline void writeln(long long x)
{
     char buffor[21];
     register int i=0;
     int neg=0; if (x<0) {neg=1; x= -x;}
     do{
           buffor[i++]=(x%10)+'0';
           x/=10;
        } while(x);
       i--;
       if (neg) pc('-');
       while(i>=0) pc(buffor[i--]);
}

long long n, a[N], res = 0, f[N][N];
void Init()
{
    read(n);
    for(int i = 1; i <= n; i++)
        read(a[i]);
}

void Solve()
{
    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= n + 1; j++)
            f[i][j] = 0;

    for(int i = 1; i < n; i++){
        for(int j = n; j > i; j--)
            f[i][j] = a[j] > a[i] ? max(f[i - 1][j + 1] + 1, max(f[i - 1][j], f[i][j + 1])) : max(f[i - 1][j + 1], max(f[i - 1][j], f[i][j + 1]));
        res = max(res, f[i][i + 1]);
    }

    writeln(res);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("SEQ2.INP", "r", stdin);
    freopen("SEQ2.OUT", "w", stdout);

    Init();
    Solve();
}

/*
10
2 6 8 1 6 84 49 4 10 1
*/
