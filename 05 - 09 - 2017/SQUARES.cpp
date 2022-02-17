#include <bits/stdc++.h>
#define N 1001

using namespace std;
long long  n, m, k;
bool c[N][N];

void Init()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            c[i][j] = true;
    for(int i = 1; i <= k; i++)
    {
        long long x, y;
        cin >> x >> y;
        c[x][y] = false;
    }
}

void Solve()
{
    long long res = 0;
    for(int r = 1; r < min(m , n); r++)
    {
        for(int x = 1; x <= n - r; x++)
        {
            for(int y = 1; y <= m - r; y++)
            {
                //if(c[x][y])
                for(int h = 0; h < r; h++)
                {
                    int x4, y4, x2, y2, x3, y3, x1, y1;
                    x1 = x; y1 = y + (r - h);
                    y2 = y; x2 = x + h;
                    x3 = x + r; y3 = y + h;
                    y4 = y + r; x4 = x + (r - h);

                    if(c[x2][y2] && c[x1][y1] && c[x3][y3] && c[x4][y4])
                        res++;
                }
            }
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  //  freopen("SQUARE.INP", "r", stdin);
    //freopen("SQUARE.OUT", "w", stdout);

    Init();

    if(k != 0) Solve();
    else {
        long long cnt = 0;
        for(int i = 1; i <= min(m, n) - 1; i++)
            cnt += i * (m - i) * (n - i);
        cout << cnt;
    }
}

/*
*/
