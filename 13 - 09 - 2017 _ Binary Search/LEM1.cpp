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
#define TITLE "LEM1"

#define gc getchar
#define pc putchar
#define length Len

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int N = 10005;
const int oo = 1000000000;
bool DEBUG = 1;
ld a[N];
ll n;

struct T
{

};

void Init()
{
    cin >> n;
    up(i , 1 , n)
        cin >> a[i];
}

bool Compare(ld x, ll y)
{
    return abs(x - y) > 0.001;
}

ld Cos(ll x, ll y, ll M)
{
    return ((x + M) * (x + M) + (y + M) * (y + M) - (x + y) * (x + y)) / (2 * (x + M) * (y + M));
}

bool ok(ll M)
{
    ll cur = 0;
    up(i , 1 , n) {
        cur += acos(Cos(a[i % n], a[(i + 1) % n], M));
    }
    return cur < 360;
}

void Solve()
{
    ld L = 0, H = 100;
    ld res = 0;

    while(Compare(L , H)) {
        ll Mid = (L + H) / 2;
        cout << Mid << endl;
        if(ok(Mid)) {
            res = Mid;
            H = Mid;
        }
        else L = Mid;

    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
  //  freopen(TITLE".OUT", "w", stdout);

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

