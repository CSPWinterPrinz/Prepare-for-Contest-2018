#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// Tập U : Tập ứng cử chứa các đỉnh có thể nhét vào tập C
/// Tập C : Tập các đỉnh đã chọn vào Clique
/// Tập N : Tập các đỉnh kề i
///

/// Ta sẽ gọi đệ quy nhét dần các đỉnh từ U sang C sao cho C luôn là Clique
//-----------------------------------------------------

#define up(i , a , b) for(int i = a ; i <= b; ++i)
#define down(i , a , b) for (int i = a; i >= b; --i)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "CLIQUE"

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
    for (; ((c<48 || c>57) && c != '-') ; c = gc());
    if(c=='-')
    {
        neg=1;
        c=gc();
    }
    for(; c>47 && c<58; c = gc())
    {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg) x=-x;
}

inline void writeln(long long x)
{
    char buffor[21];
    register int i=0;
    int neg=0;
    if (x<0)
    {
        neg=1;
        x= -x;
    }
    do
    {
        buffor[i++]=(x%10)+'0';
        x/=10;
    }
    while(x);
    i--;
    if (neg) pc('-');
    while(i>=0) pc(buffor[i--]);
    pc('\n');
}
/// ***************************** FAST I/O *****************************

const int N = 3002;
const int oo = 1000000000;

vector <int> e[N], w[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> Dq;
stack <int> st;
string s;
bool DEBUG = 0;

struct T
{

};
ll m, n, k, cnt = 0, res[N];
bool ok, f[N][N];

void Init()
{
    up(i, 1, 50) up(j, 1, 50) f[i][j] = 0;

    ok = 0;
    up(i, 1, n)
    e[i].clear();
    cin >> n >> m >> k;
    up(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        f[u][v] = f[v][u] = 1;
    }
}

void Print(ll C)
{
    up(i, 1, n)
    if(C & (ll) 1 << (i - 1) == (ll) (i - 1)) cout << i << " ";
    cout << endl;
}

void Visit(ll U, ll C)
{
    ll cntU = 0, cntC = 0;
    up(i, 0, n)
    {
        if(U & (ll) 1 << (i - 1) == (ll) 1 << (i - 1)) cntU++; /// Neu bit thu i cua U = 1;
        if(C & (ll) 1 << (i - 1) == (ll) 1 << (i - 1)) cntC++; /// TUong tu
    }
    if(ok || cntC + cntU < k) return;  /// Tong phan tu tap C, U < k return;
    if(cntC == k)
    {
        ok = true;
        Print(C);                      /// Luu kqua
        return;
    }

    up(i, 1, 50)
    if(U & ((ll) 1 << (i - 1)) == (ll) 1 << (i - 1))  /// If bit i cua U = 1
    {
        ll u1 = U, u2 = U, c1 = C, c2 = C;
        c1 = C | (1 << (i - 1));
        u2 = (U ^ (1 << (i - 1)));

        up(j , 1 , 50)
        if(!f[i][j] && ((u1 >> (j - 1) & 1) == 1))
            u1 = (u1 ^ (1 << (j - 1)));

        Visit(u1, c1);
        Visit(u2, c2);
    }
}

void Sub2()
{
    bool avail[N];
    memset(avail , 0, sizeof(avail));
    up(i , 1 , n)
        up(j , 1 , n)
            if(avail[i] == 0 && avail[j] == 0 && f[i][j] && i != j)
                avail[i] = 1, avail[j] = 1;
    ll cou = 0;
    up(i , 1 , n) {
        if(cou == k) break;
        if(!avail[i])
            cout << i << ' ', cou++;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    int Test = 1;
    cin >> Test;

    up(i , 1 , Test) {
        Init();
        if(n > 50)
            Sub2();
        else {
            Visit((ll) (1 << n) - 1, 0);
            if(!ok) cout << -1;
        }
    }
}


