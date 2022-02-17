#include <bits/stdc++.h>

using namespace std;
long long f[10001][10001], n, x, y, k, Q;
string s;

void Init()
{
    cin >> s;
    cin >> k >> Q;
    n = s.length() - 1;
    memset(f , 0 , sizeof(f));
    for(int i = 0; i < n; i++)
        if(s[i] == s[i + 1])
        {
            f[i][i + 1] = 0;
            f[i + 1][i] = 0;
        }
        else
        {
            f[i][i + 1] = 1;
            f[i + 1][i] = 1;
        }
}

void Solve()
{
    for(int len = 2; len <= n; len++)
        for(int i = 0; i <= n - len; i++)
        {
            int j = i + len;
            if(s[i] == s[j]) f[i][j] = f[i + 1][j - 1];
            else f[i][j] = f[i + 1][j - 1] + 1;
            if(f[i][j] <= k) ans
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("LRKPALIN.INP", "r", stdin);
    freopen("LRKPALIN.OUT", "w", stdout);

    Init();
    Solve();

    for(int i = 1; i <= Q; i++)
    {
        cin >> x >> y;
        cout << f[x][y] << endl;
    }

}

