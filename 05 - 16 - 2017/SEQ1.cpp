#include <bits/stdc++.h>
#define N 524

using namespace std;
long long n, a[N], res = 0, f[N][N];
void Init()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    for(int k = 1; k < n; k++)
    {
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                f[i][j] = 0;

        for(int i = 1; i <= k; i++)
            for(int j = k + 1; j <= n; j++)
                f[i][j] = a[j] > a[i] ? f[i - 1][j - 1] + 1 : max(f[i - 1][j], f[i][j - 1]);
        res = max(res, f[k][n]);
    }
    cout << res;
}

/// XÂU CON CHUNG DÀI NHẤT
/// SEQ2 : PALINDROME DÀI NHẤT
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("SEQ1.INP", "r", stdin);
    freopen("SEQ1.OUT", "w", stdout);

    Init();
    Solve();
}

/*
*/
