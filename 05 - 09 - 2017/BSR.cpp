#include <bits/stdc++.h>
#define N 524

using namespace std;
long long  n, m, k;
long long c[10], f[N][N], a[N][N];

void Init()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            f[i][j] = 0;
        }
    }
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            f[i][j] = f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1] + a[i][j];
        }
    }
}

void Solve()
{
    long long res = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int z = 1; z <= 10; z++)
                c[z] = 0;
            c[0] = 1;
            for(int z = 1; z <= n; z++)
            {
                res = res + c[(f[z][j] - f[z][i - 1]) % 9];
                c[(f[z][j] - f[z][i - 1]) % 9]++;
            }
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("BSR.INP", "r", stdin);
    freopen("BSR.OUT", "w", stdout);

    Init();
    Solve();

}

/*
*/
