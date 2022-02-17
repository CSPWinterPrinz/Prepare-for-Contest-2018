#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// Cho Q truy vấn x, y; Tìm chi phí min từ (x , y) đến một ô '*' bất kỳ
/// Dijkstra quá tgian
/// Nghĩ đến lập mảng L(x , y) là Sol;
/// Nghĩ típ Loang, từ các ô '*';
/// Cài đặt dùng Pair, giống Labudovi
//-----------------------------------------------------

#define N 1006
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; ++i)
#define down(i , a , b) for (int i = a; i >= b; --i)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "PATHGAME"

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

vector <int> e[N], w[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
//queue <int> Q;
deque <int> DQ;
stack <int> st;
string s;
bool l;
ll edgeX[5] = {0 , 1 , 0, -1};
ll edgeY[5] = {-1 , 0 , 1, 0};

ll Dis[N][N], m, n, Q;
char a[N][N];
bool avail[N];

struct Pair
{
    ll x, y;
};
//Pair d[N];
deque <Pair> Dq;

void Init()
{
    //read(m); read(n); read(Q);
    cin >> m >> n >> Q;
    up(i , 1 , m)
        up(j , 1 , n)
            Dis[i][j] = oo;

    up(i , 1 , m)
        up(j , 1 , n) {
            cin >> a[i][j];
            if(a[i][j] == '*') {
                Dis[i][j] = 0;
                Pair z; z.x = i; z.y = j;
                Dq.pb(z);
            }
        }
}

void BFS()
{
    while(!Dq.empty())
    {
        Pair u;
        u.x = Dq.front().x; u.y = Dq.front().y; Dq.pop_front();

        up(z , 0 , 3) {
            Pair v;
            v.x = u.x + edgeX[z];
            v.y = u.y + edgeY[z];
            if(v.x > 0 && v.x <= m && v.y > 0 && v.y <= n) {
                ll Cp = a[u.x][u.y] == a[v.x][v.y] ? 0 : 1;
                if(Dis[u.x][u.y] + Cp < Dis[v.x][v.y]) {
                    Dis[v.x][v.y] = Dis[u.x][u.y] + Cp;
                    if(Cp == 1) Dq.pb(v);
                    else Dq.push_front(v);
                }
            }
        }
    }
}

void Solve()
{
    up(i , 1 , Q)
    {
        int u, v;
        cin >> u >> v;
        cout << Dis[u][v] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    Init();
    BFS();
    Solve();
}


