#include <bits/stdc++.h>
#include <ctime>
#define N 501
#define M 123456789

using namespace std;
string s;
long long n, A[N][N], B[N][N], Mid[N], Mid2[N], D[N], E[N], F[N];
long long Right[N], Left[N];

Build()
{
    memset(Mid , 0 , sizeof(Mid));
    memset(Mid2 , 0 , sizeof(Mid2));
    for(int i = 1; i <= n; i++)
        Mid[i] = rand() % 10 + 2;
    for(int i = 1; i <= n; i++)
        {Mid2[i] = Mid[i]; }

}

void Init()
{
    memset(A, 0 , sizeof(A));
    memset(B, 0 , sizeof(B));

    scanf("%lld", &n);
    Build();

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%lld", &A[i][j]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%lld", &B[i][j]);
}

void Times_Matrix(long long x[N][N], long long y[N] , long long z[N])
{
    //memset(z , 0 , sizeof(z));
    for(int i = 1; i <= n; i++)
        for(int k = 1; k <= n; k++)
            z[i] += x[i][k] * y[k];
    //cout << 1 << " ";

   // for(int i = 1; i <= n; i++)
    //    cout << z[i] << " ";
    //cout << endl;
    return;
}

bool Check(long long x[N], long long y[N])
{
    for(int i = 1; i <= n; i++)
            if(x[i] != y[i]) return false;
    return true;
}

void Solve()
{
    memset(Right, 0, sizeof(Right));
    memset(Left, 0, sizeof(Left));

    Times_Matrix(B , Mid2 , Right);
    memset(D , 0 , sizeof(D)); memset(E , 0 , sizeof(E));  memset(F , 0 , sizeof(F));
    Times_Matrix(A , Mid, D); Times_Matrix(A , D , E); Times_Matrix(A , E , F);

    if(Check(Right , F)) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main()
{
    freopen("MMC.INP", "r", stdin);
    freopen("MMC.OUT", "w", stdout);


    int T; scanf("%lld", &T);
    for(;T >= 1;T--)
    {
        Init();
        Solve();
    }
}
/// Code rút ngắn ko đc => đổi
