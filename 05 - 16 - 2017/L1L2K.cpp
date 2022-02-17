#include <bits/stdc++.h>

using namespace std;
long long a[100001], f[100001], n, res = 1, maxx = 0, k, truy[100001], cnt = 0;
long long d[100001]; // d[k] là phần tử last of dãy con tăng độ dài k.
void Init()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

int BS(int v)
{
    int L = 1, H = maxx;

    while(L <= H)
    {
        int M = (L + H) / 2;
        if(d[M] < v) L = M + 1;
        else H = M - 1;
    }
    return H;
}

void Solve()
{
    f[1] = 1; f[0] = 0;
    d[1] = a[1]; //a[0] = - 1e9;

    for(int i = 1; i <= n; i++)
    {
        k = BS(a[i]) + 1;
        f[i] = k;
        d[k] = a[i];
        if(maxx < f[i]) maxx = f[i];

    }

     cout << maxx;

}

// 9 5 -4 1 6 2 4 7 3 2
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("L1L2K.INP", "r", stdin);
    freopen("L1L2K.OUT", "w", stdout);

    Init();
    Solve();
}
