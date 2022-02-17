#include <bits/stdc++.h>
#define N 124

using namespace std;
long long n, m, k, d[N][N], trace[N][N];

void Solve()
{
    long long p, q;

    while(cin >> p >> q)
    {
        if(p == 1 && q == 1) break;
        long long a = 0, b = 1, x = 1, y = 0;

        while(true)
        {
            long long u = a + x, v = b + y;
            if(u == p && v == q) break;
            if(p * v > q * u) {
                cout << "R";
                a = u; b = v;
            }
            else {
                cout << "L";
                x = u; y = v;
            }
        }
        cout << endl;
    }
}

int main()
{
    freopen("PS.INP", "r", stdin);
    freopen("PS.OUT", "w", stdout);

    Solve();
}


