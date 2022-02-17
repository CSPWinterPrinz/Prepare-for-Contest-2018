/*
𝑎1, 𝑎2, . . , 𝑎𝑛 (cásố nguyên dương 𝑘. Người chơi cần thực hiện không
quá 𝑘 phép biến đổi để từ số 𝑎1 nhận được số 𝑎𝑛. Mỗi lần thực hiện biến đổi, từ số 𝑎𝑖 có thể biến
đổi thành số 𝑎𝑗 nếu 6 × 𝑎𝑖 + 𝑎𝑗là một số nguyên tố.
*/
///Hãy đếm số cách biến đổi không
///quá 𝑘 bước để từ 𝑎1 nhận được 𝑎𝑛 chia dư cho � a1 -> an có ? cách đi

///SOL : Ma trận A : ô(i,j) : Số đường đi từ i -> j qua k cạnh
///

#include <bits/stdc++.h>
#include <ctime>
#define N 24

using namespace std;
string s;
int n, k, M, cntP = 0, Prime[N], z[N];
bool f[N];

struct Matrix
{
    int Data[N][N];
};
Matrix A, Const;

void Eratos()
{
    memset(f, 1, sizeof(f)); f[0] = 0; f[1] = 0;
    for(int i = 2; i <= 100000; i++)
    {
        if(f[i])
            for(int j = i * 2; j <= 100000; j++)
                f[i] = 0;
    }

    for(int i = 1; i <= 100000; i++)
        if(f[i]) Prime[++cntP] = i;
}

bool Rela (int x, int y)
{
    return binary_search(Prime + 1, Prime + n + 1, 6 * x + y);
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

Matrix Build(int z[N])
{
    Matrix Z;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            Z.Data[i][j]= 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(Rela(z[i], z[j]))
                Z.Data[i][j] = 1;

    return Z;
}

int main()
{
    freopen("CNGAME.INP", "r", stdin);
    freopen("CNGAME.OUT", "w", stdout);

    Eratos();
    int T; cin >> T;

    for(int i = 1; i <= T; i++)
    {
        cin >> n >> k >> M;
        for(int j = 1; j <= n; j++)
            cin >> z[j];

        Matrix Const = Build(z);
        Matrix Ans = Solve(Const , k);

        cout << Ans.Data[1][n] << endl;
    }

}
/// Code rút ngắn ko đc => đổi


