#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// Chốt max : Dijkstra tìm MIN
/// Chốt cạnh max , chặt NP Min, xem có đường đi đi qua min, max hay ko *********
/// CHUYỂN TỪ BÀI TOÁN TỐI ƯU SANG CÁI THỎA ĐC

/// Chặt NP KQ của toàn bài. Xấy dựng danh sách cạnh. sort từ trên xuống dưới.
/// Trừ all cạnh cho KQ / 2;


/// Cài cặp ghép cực đại cơ bản
//-----------------------------------------------------

#define up(i , a , b) for(int i = a ; i <= b; ++i)
#define down(i , a , b) for (int i = a; i >= b; --i)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "BGAME"

#define gc getchar
#define pc putchar

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

/// ***************************** FAST I/O *****************************
inline void read(long long &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for (;((c<48 || c>57) && c != '-') ;c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

inline void writeln(long long x)
{
     char buffor[21];
     register int i=0;
     int neg=0; if (x<0) {neg=1; x= -x;}
     do{
           buffor[i++]=(x%10)+'0';
           x/=10;
        } while(x);
       i--;
       if (neg) pc('-');
       while(i>=0) pc(buffor[i--]);
       pc('\n');
}
/// ***************************** FAST I/O *****************************

const int N = 5006;
const int oo = 1e18;

vector <int> e[N], w[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q; deque <int> Dq; stack <int> st;
string s;
bool DEBUG = 1, avail[N], ok, appear;

ll m, n, c[N][N], res = -oo, start, Max;

void Init()
{
    cin >> n >> m;
    up(i , 1 , n) up(j , 1 , n) c[i][j] = -1;
    up(i , 1 , m) {
        ll x, y, z; cin >> x >> y >> z;
        if(c[x][y] == -1)
            c[x][y] = c[y][x] = z;
        else {
            res = max(res , c[x][y] + z);
            c[x][y] = c[y][x] = max(c[x][y] , z);
            Max = max(Max , c[x][y]);
        }
    }

    up(i , 1 , n)
        up(j , 1 , n)
            if(c[i][j] > -1)
                e[i].pb(j);
}

void DFS(ll i, ll j, ll mid)
{
    avail[i] = 1;
    up(z , 0 , e[i].size() - 1) {
        ll v = e[i][z]; /// w[i][z]


        if(c[i][v] != -1 && !avail[v] && c[i][v] >= mid) {
            DFS(v , j , mid);
        }
    }
    if(i == j) ok = true;
}

void Solve()
{
    /// Chot canh max la c(i , j) moi lan xet, cu khi tim dc duong di thoa man thi break.

    up(i , 1 , n)
        up(j , 1 , n)
            if(c[i][j] > -1) {
                Max = c[i][j];
                c[i][j] = c[j][i] = -1;

                ll L = 0, H = Max;
                while(L <= H) {
                    ll M = (L + H) / 2;
                    //if(DFS(i , j , M)) {
                    ok = 0;
                    if(Max + M > res) {
                        memset(avail , 0 , sizeof(avail));
                        (DFS(i , j , M));
                        if(ok) { /// NHÁNH CẬN
                            res = M + Max;
                            L = M + 1;
                        }
                        else H = M - 1;
                    }
                    else L = M + 1;
                }
                c[i][j] = c[j][i] = Max;
            }
        }


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    int Test = 1;
    //cin >> Test;
    up(i , 1 , Test) {
        Init();
        Solve();
    }
    cout << max(res , (ll) 0);
    exit(0);
}

