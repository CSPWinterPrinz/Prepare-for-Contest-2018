  #include <bits/stdc++.h>
#define N 1000024

using namespace std;
long long f[N], n, m, a[N];
bool Prime[N], Check[N];

void Eratos()
{
    memset(Prime, 1, sizeof(Prime));
    Prime[1] = 0; Prime[0] = 0;
    for(int i = 2; i <= N; i++)
    {
        if(Prime[i]) {
            for(int j = i * 2; j <= N; j += i) {
                Prime[j] = 0;
            }
        }
    }
}

void Init()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int x;cin >> x;
            a[(i - 1) * m + j] = x;
            Check[(i - 1) * m + j] = Prime[x];
        //    cout << Check[(i - 1) * m + j] << " ";
        }
      //  cout << endl;
    }
}
/// f(i * m + j) Số số nguyên tố từ 1,1 đến i,j;
void Solve()
{
    //cout << endl;
    memset(f, 0, sizeof(f)); f[0] = 0;
    for(int i = 1; i <= m; i++)
        {if(Check[i]) f[i] = f[i - 1] + 1;
        else f[i] = f[i - 1];
        //cout << f[i] << " ";
        }

    for(int i = m + 1; i <= m * (n - 1) + 1; i += m)
        {if(Check[i]) f[i] = f[i - m] + 1;
        else f[i] = f[i - m];
        //cout << f[i] << " ";
        }
        //cout<<endl;

    for(int i = 2; i <= n; i++)
    {
        for(int j = 2; j <= m; j++)
        {
            //f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
            f[i * m + j - m] = f[(i - 2) * m + j] + f[i * m + j - 1 - m] - f[(i - 2) * m + j - 1];
            if(Check[i * m + j - m]) f[i * m + j - m]++;
            //cout << f[(i - 1) * m + j] << " ";
        }
        //cout << endl;
    }
}
bool Perfect_Square(int i, int j, int k)
{
    long long cnt = 0;
    //cnt = f[i][j] - f[i - k][j] - f[i][j - k] + f[i - k][j - k];
    cnt = f[(i - 1) * m + j] - f[(i - k - 1) * m + j] - f[(i - 1) * m + j - k] + f[(i - k - 1) * m + j - k];
   // cout << (i - k) * (j - k) << " " << cnt << endl;
    return k * k - cnt == 1 || k * k - cnt == 0;
}

void ANSWER()
{
    long long res =   0;

    for(int i = 1; i <= n; i++)
    {
        bool l = true;
        for(int j = 1; j <= m; j++)
        {
            for(int k = res + 1; k <= min(m , n); k++)
            {
                if( Perfect_Square(i, j, k)) {
                    l = false;
                    res = k - 1;
                }
            }
            if(l) break;
        }
        if(l) break;
    }
    cout << res * res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//
    freopen("PSQ2.INP", "r", stdin);
    freopen("PSQ2.OUT", "w", stdout);

    Eratos();
    Init();
    Solve();
    ANSWER();

}

/*
*/
