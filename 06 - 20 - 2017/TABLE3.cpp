#include <bits/stdc++.h>

//-----------------------------------------------------

#define N 32
#define oo 1000000000

#define up(i , a , B) for(int i = a ; i <= B; i++)
#define down(i , a , B) for (int i = a; i >= B; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "TABLE3"

#define gc getchar
#define pc putchar

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
string s;
bool l;

ll m, n, B[N][N], a[N][N], h[N * N][N][N], b[N * N], res = 0;

void Init()
{
    cin >> m >> n;
    up(i , 1 , m)
        up(j , 1 , n)
            cin >> B[i][j];
}

void BuildH()
{
    up(len , 1 , m * n)
    {
        int y = len % n, x = len / n;
        h[len][x - 1][y] += x > 1 ? 1 : 0;
        h[len][x + 1][y] += x < n ? 1 : 0;
        h[len][x][y - 1] += y > 1 ? 1 : 0;
        h[len][x][y + 1] += y < n ? 1 : 0;

        b[len] = B[x][y];
    }
}
/// b[i] : ánh xạ mảng b;

void Solve()
{
    up(len , 1 , m * n - 1)
    {
        int y = len % n, x = len / n;

        if(h[len][x][y] == h[len + 1][x][y]) {
            bool ck = true;
            up(i, 1 , m)
                up(j , 1 , n) {
                    h[len][i][j] = (2 * h[len][i][j] + h[len + 1][i][j]) % 3;

                    if(h[len][i][j] != 0) ck = false;
                }

            b[len] = (b[len] * 2 + b[len + 1]) % 3;
            if(ck && b[len] == 0) res++;
        }

        else {
            bool ck = true;
            up(i, 1 , m)
                up(j , 1 , n) {
                    h[len][i][j] = (h[len][i][j] + h[len + 1][i][j]) % 3;

                    if(h[len][i][j] != 0) ck = false;
                }

            b[len] = (b[len] + b[len + 1]) % 3;
            if(ck && b[len] == 0) res++;
        }
    }

    int ans = 1;
    up(i , 1 , res) ans = (ans * 3) % 111539786;
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  //  freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    Init();
    BuildH();
    Solve();
}

