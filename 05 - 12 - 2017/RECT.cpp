#include <bits/stdc++.h>
#define N 1024

using namespace std;
long long n, m, a[N][N], f[N][N];
long long minij[300][300][300];

void Init()
{
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
}

void Build()
{
    long long mincur;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j < n; j++) {
            mincur = 1000000000;
            for(int t = j + 1; t < n; t++) {
                for(int z = j; z <= t; z++)
                    mincur = min(mincur , a[i][z]);
                minij[i][j][t] = mincur;
            }
        }
    }
}

void Solve()
{
    long long res = 0;
    //fill(f + 1, f + m * n + 1, 0);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            for(int x = i; x <= m; x++)
                for(int y = j; y <= m; y++) {
                    long long mincur = 1000000000;
                    for(int t = i; t <= x; t++)
                        mincur = min(mincur, minij[t][j][y]);

                    res = max(res, mincur * (f[x][y] + f[i - 1][j - 1] - f[i - 1][y] - f[x - 1][j]));
                }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("RECT.INP", "r", stdin);
    freopen("RECT.OUT", "w", stdout);

    Init();
    Build();
    Solve();
}
