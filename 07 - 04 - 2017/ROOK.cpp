#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <mem.h>
#define up(i , a , b) for(i = a; i <= b; i += 2)
#define down(i , a , b) for (i = a; i >= b; i -= 2)
#define maxn 100001
#define endl '\n'
#define T TEMPLATE
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

    ll n, m, a[maxn], x, z, y, k, i, j, cnt = 0, res = 0;
    string s , t;

void Init()
{
    cin >> n;
    cin >> s;

}

void Solve()
{
    down(i , n - 2 , (n) % 2) cout << s[i];
    up(i , (n - 1) % 2 , n - 1) cout << s[i];
    cout << t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Init();
    Solve();

}
//
