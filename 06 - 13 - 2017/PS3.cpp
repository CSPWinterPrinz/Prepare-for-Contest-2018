#include <bits/stdc++.h>
#define N 1024
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ull n, m, d[N], MOD, bin[N];
ll cnt = -1, cnt_road = 0;

/// Sup 1 : chuyển n sang hệ cơ số 2, bỏ bit đầu,
void Convert(unsigned long long x)
{
    if (x > 1) Convert(x / 2);
    bin[++cnt] = x % 2;
}

void Init()
{
    cin >> n >> MOD;
    Convert(n);
    int start = 1;
    if(bin[1] == 0) {start = 0; bin[0] = 0;}

    d[++cnt_road] = 1;
    for(int i = start + 1; i <= cnt; i++) {
        if(bin[i] == bin[i - 1]) d[cnt_road]++;
        else d[++cnt_road] = 1;
    }
}

ll Mul(ll x, ll y, ll b) //x * y % b;
{
     if (y == 0) return 0;
     ll q = Mul (x, y / 2, b);
     if (y % 2 == 0) return (q + q) % b;
        else return (q + q + x) % b;
}

void Solve()
{
    long long a1 = 0, b1 = 1;
    long long a2 = 1, b2 = 0;
    long long u = a1 + b1, v = a2 + b2;

    for(int i = 1; i <= cnt; i++)
    {
        cin >> d[i];
        if(d[i] == 0) {a2 = u; b2 = v;}
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
    cout << (v) % MOD << " " << (u) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);

    freopen("PS3.INP", "r", stdin);
    //freopen("PS3.OUT", "w", stdout);

    Init();
    Solve();
}



