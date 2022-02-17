#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define up(i , a , b) for(int i = a ; i <= b; ++i)
#define up2(i , a , b , c) for(int i = a ; i <= b; i += c)
#define down(i , a , b) for (int i = a; i >= b; --i)
#define down2(i , a , b , c) for (int i = a; i >= b; i -= c)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "MINRANGE2"

#define gc getchar
#define pc putchar
#define length Len

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int N = 100005;
const int oo = 1000000000;
bool DEBUG = 1;

struct T
{

};
ll n, m , a[N], Lazy[N << 2], L[N << 2], H[N << 2], Min[N << 2];

void Build(ll pos, ll low, ll high)
{
    L[pos] = low; H[pos] = high; Lazy[pos] = 1e18;
    if(low == high) {
        Min[pos] = a[low]; return;
    }
    ll mid = (low + high) / 2;
    Build(pos << 1, low , mid);
    Build(pos * 2 + 1, mid + 1, high);

    Min[pos] = min(Min[pos << 1] , Min[pos << 1 | 1]);
}

void Down(ll pos)
{
    if(Lazy[pos] != 1e18)
    {

        Lazy[pos << 1] = Lazy[pos];
        Lazy[pos * 2 + 1] = Lazy[pos];

        Min[pos << 1] = Lazy[pos];
        Min[pos * 2 + 1] = Lazy[pos];

        Lazy[pos] = 1e18;
    }
}

void Update(ll pos, ll low, ll high, ll val)
{
    if(low > H[pos] || high < L[pos]) return;

    if(L[pos] >= low & H[pos] <= high) {
        Lazy[pos] = val;
        Min[pos] = val;
        return;
    }
    Down(pos);

    Update(pos << 1, low , high , val);
    Update(pos * 2 + 1, low, high , val);

    Min[pos] = min(Min[pos << 1] , Min[pos * 2 + 1]);
}

ll Querry(ll pos, ll low, ll high)
{
    if(low > H[pos] || high < L[pos])
        return 1e18;
    if(low <= L[pos] && high >= H[pos])
        return Min[pos];
    Down(pos);

    return min(Querry(pos << 1, low, high) , Querry(pos * 2 + 1, low, high));
}

void Init()
{
    memset(Lazy, 0 , sizeof(Lazy));
    cin >> n >> m;
    up(i , 1 , n)
        cin >> a[i];
    Build(1 , 1 , n);
}

void Solve()
{
    up(i , 1 , m)
    {
        int x; ll u, v, w;
        cin >> x;
        if(x == 1) {
            cin >> u >> v >> w;
            Update(1, u , v , w);
        }
        else {
            cin >> u >> v;
            cout << Querry(1 , u , v) << endl;
        }
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
}














/*
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
*/
