#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 1001
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; ++i)
#define down(i , a , b) for (int i = a; i >= b; --i)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "PATH"

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

bool avail[N];
ll edgeX[9] = {0 , 1 , 0, -1, 1 , -1 , 1 , -1};
ll edgeY[9] = {-1 , 0 , 1, 0, 1 , -1 , -1 , 1};

ll Dis[N][N], m, n, Q;
char a[N][N];


struct Pair
{
    ll x, y;
};
//Pair d[N];
deque <Pair> Dq;

void Init()
{
    cin >> m >> n;
    up(i , 1 , m)
        up(j , 1 , n)
            cin >> a[i][j];

    up(i , 1 , n)
        up(j , 1 , n)
            Dis[i][j] = oo;



    up(i , 2 , m - 1) {
        Pair z; z.y = i; z.x = 1;
        if(a[1][i] == '.') Dq.pb(z);
        Dis[1][i] = a[1][i] == '#' ? 0 : 1;
    }
    up(i , 2 , m - 1) {
        Pair z; z.y = i; z.x = 1;
        if(a[1][i] == '#') Dq.pb(z);
        Dis[1][i] = a[1][i] == '#' ? 0 : 1;
    }

}

void BFS()
{
    while(!Dq.empty())
    {
        Pair u = Dq.front(); Dq.pop_front();

        up(z , 0 , 7) {
            Pair v;
            v.x = u.x + edgeX[z];
            v.y = u.y + edgeY[z];
            if(v.x > 1 && v.x < m && v.y > 0 && v.y <= n) { /// B - > W = 1, W -> W = 1, W -> B = 0, B -> B = 0
                ll Cp = (a[v.x][v.y] == '#' && (a[u.x][u.y] == '.' || a[u.x][u.y] == '#')) ? 0 : 1;
                if(Dis[u.x][u.y] + Cp < Dis[v.x][v.y]) {
                    Dis[v.x][v.y] = Dis[u.x][u.y] + Cp;
                    if(Cp == 0)  Dq.push_front(v);
                    else Dq.pb(v);
                }
            }
        }
    }
}

void Solve()
{
    ll res = oo;
    up(i , 2 , m - 1)
        {res = min(res , Dis[i][n]);}// cout << Dis[i][n] << endl;}
    cout << res;
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
/// Moore Bellman

