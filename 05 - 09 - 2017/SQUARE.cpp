#include <bits/stdc++.h>
#define N 1001

using namespace std;
long long  n, m, k;
bool c[N][N];

void Init()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            c[i][j] = true;
    for(int i = 1; i <= k; i++)
    {

    }
}
/// Tu các điểm bị xóa, dụng lại toàn bộ 4 dạng hình vuông nhận điểm bị xóa làm Bằng && (Trái || Phải) || (Trên || Dưới) && Bằng
void Solve()
{
    for(int i = 1; i <= k; i++)
    {
        long long x, y;
        cin >> x >> y;
        c[x][y] = false;

        ///  Bang / Trai
        for(int len = x; len <= m; len++)
        {
            for(int h = 1; h < x; h++)
            {
                int x1, x2, x3, x4, y1, y2, y3, y4;

            }
        }

        /// Bang / Phai

        /// Tren / Bang

        /// Duoi / Bang
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  //  freopen("SQUARE.INP", "r", stdin);
    //freopen("SQUARE.OUT", "w", stdout);

    Init();

    long long cnt = 0;
    for(int i = 1; i <= min(m, n) - 1; i++)
        cnt += i * (m - i) * (n - i);
    cout << cnt;

    Solve();

}

/*
*/
