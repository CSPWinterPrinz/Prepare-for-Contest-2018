#include <bits/stdc++.h>
#define N 1024

using namespace std;
long long n, k, Left[N], Right[N], Up[N], Down[N], a[N][N], f[N][N];

void Init()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
}

void Array_Up()
{
    for(int i = 1; i <= n; i++)
        f[i][0] = f[0][i] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];

    /// Up(i)
    for(int i = k; i <= n; i++) {
         Up[i] = 0;
         for(int j = 1; j <= n; j++)
            Up[i] = max(Up[i] , f[i][j] - f[i - k][j] - f[i][j - k] +  f[i - k][j - k]);
        cout << Up[i] << " " << i << " ";
    }
    cout << endl;
}

void Array_Down()
{
    for(int i = 1; i <= n; i++)
        f[i][0] = f[0][i] = 0;

    for(int i = n; i >= 1; i--)
        for(int j = n; j >= 1; j--)
            f[i][j] = f[i + 1][j + 1] - f[i + 1][j] - f[i][j + 1] + a[i][j];

    for(int i = n - k + 1; i >= 0; i--) {
        Down[i] = 0;
        for(int j = n - k + 1; j >= 0; j--)
            Down[i] = max(Down[i] , f[i][j] - f[i + k][j] - f[i][j + k] + f[i + k][j + k]);
        cout << Down[i] << " " << i << " ";
    }
    cout << endl;
}

void Array_Left()
{
    for(int i = 1; i <= n; i++)
        f[i][0] = f[0][i] = 0;

    for(int i = n; i >= 1; i--)
        for(int j = 1; j <= n; j++)
            f[i][j] = f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1] + a[i][j];

    for(int i = k; i <= n; i++) {
        Left[i] = 0;
        for(int j = 1; j <= n; j++)
            Left[i] = max(Left[i], f[i][j] - f[i][j - k] - f[i + k][j] - f[i + k][j - k]);
        cout << Left[i] << " " << i << " ";
    }
    cout << endl;
}

void Array_Right()
{
    for(int i = 1; i <= n; i++)
        f[i][0] = f[0][i] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = n; j >= 0; j--)
            f[i][j] = f[i - 1][j] + f[i][j + 1] - f[i - 1][j + 1] + a[i][j];

    for(int i = k; i <= n; i++) {
        Right[i] = 0;
        for(int j = 1; j <= n - k + 1; j++)
            Right[i] = max(Right[i] , f[i][j] - f[i - k][j] - f[i][j + k] + f[i - k][j + k]);
        cout << Right[i] << " " << i << " ";
    }
    cout << endl;
}

void Build()
{
    Array_Up();
    Array_Down();
    Array_Left();
    Array_Right();
}

void Solve()
{
    long long res = 0;

    for(int j = 1; j <= n; j++)
    {
        res = max(Left[j] + Right[j + 1 - k] , res);
        res = max(Left[j] + Right[j - k + 1] , res);
    }

    for(int i = 1; i <= n; i++)
    {
        res = max(Up[i] + Down[i - k + 1] , res);
        res = max(Up[i] + Down[i + 1 - k] , res);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("BONUS2.INP", "r", stdin);
    //freopen("BONUS2.OUT", "w", stdout);

    Init();
    Build();
    Solve();
}
