#include <bits/stdc++.h>
#define N 1024

using namespace std;
long long n, m, d[N], MOD;

void Init()
{
    cin >> n >> MOD;
}

typedef long long T;


T Mul(T x, T y, T b) //x * y % b;
{
     if (y == 0) return 0;
     T q = Mul (x, y / 2, b);
     if (y % 2 == 0) return (q + q) % b;
        else return (q + q + x) % b;
}

void Solve()
{
    long long a1 = 0, b1 = 1;
    long long a2 = 1, b2 = 0;
    long long u = a1 + b1, v = a2 + b2;

    for(int i = 1; i <= n; i++)
    {
        cin >> d[i];
        if(i % 2 == 1) {
            long long a3 = Mul(a2, d[i], MOD);
            long long b3 = Mul(b2, d[i], MOD);
            u = (a3 + u) % MOD; v = (b3 + v) % MOD;
            a1 = (u + MOD - a2) % MOD;
            b1 = (v + MOD - b2) % MOD;
        }
        else {
            long long a3 = Mul(a1, d[i], MOD);
            long long b3 = Mul(b1, d[i], MOD);
            u = (a3 + u) % MOD; v = (b3 + v) % MOD;
            a2 = (u + MOD - a1) % MOD; b2 = (v + MOD - b1) % MOD;
        }
        //cout << a << " " << b << " " << x << " " << y <<  endl;
    }
    cout << (u) % MOD << " " << (v) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);

    freopen("PS2.INP", "r", stdin);
    freopen("PS2.OUT", "w", stdout);

    Init();
    Solve();
}


