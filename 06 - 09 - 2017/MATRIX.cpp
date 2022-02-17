#include <bits/stdc++.h>
#include <ctime>
#define N 24
#define M 123456789

using namespace std;
string s;
int n, k;

struct Matrix
{
    int Data[N][N];
};
Matrix A, Const;

/// Matrix A + B
void Init()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> A.Data[i][j];
}

Matrix Sum(Matrix A, Matrix B)
{
    Matrix C;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            C.Data[i][j] = (A.Data[i][j] + B.Data[i][j]) % 10;

    return C;
}

/// MAtrix A * B
Matrix Multi(Matrix A, Matrix B)
{
    Matrix C;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            C.Data[i][j] = 0;
            for(int k = 1; i <= n; k++)
                C.Data[i][j] = (C.Data[i][j] + A.Data[i][k] * B.Data[k][j] % 10) % 10;
        }
    return C;
}

/// Matrix A ^ k;
Matrix Power(Matrix A, int k)
{
    if(k == 1) return A;
    Matrix T = Power(A , k / 2);
    if(k % 2 == 0) return Multi(T , T);
    else return Multi(T , Multi(T , A));
}

/// Tinh' A^1 + A^2 + ... + A^k
Matrix Solve(Matrix A, int k)
{
    if(k == 1) return A;
    Matrix B = Solve(A , k / 2);
    Matrix D = Power(A , k / 2);
    Matrix C = Sum(B , Multi(D , B));

    if(k % 2 == 1) return Sum(C , Power(A , k));
    return C;
}

int main()
{
    freopen("MAXTRIX.INP", "r", stdin);
    freopen("MAXTRIX.OUT", "w", stdout);

    Init();
    Matrix ANS;
    ANS = Solve(A, k);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << ANS.Data[i][j] % 10 << " ";
        cout << endl;
    }
}
/// Code rút ngắn ko đc => đổi

