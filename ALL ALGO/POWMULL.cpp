#include <bits/stdc++.h>


#define up(i , a , b) for(int i = a ; i <= b; ++i)
#define up2(i , a , b , c) for(int i = a ; i <= b; i += c)
#define down(i , a , b) for (int i = a; i >= b; --i)
#define down2(i , a , b , c) for (int i = a; i >= b; i -= c)

#define II pair <ll, ll>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "POWMULL"

#define _ << ", " <<
#define db(x) cout << #x << " ~~ " << x <<endl>

#define X first
#define Y second

#define gc getchar
#define pc putchar
#define Len length

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int N = 110000;
const int oo = 1000000007;
bool DEBUG = 1;

II a[N], b[N];
ll n;

void Init()
{
    scanf("%lld", &n);

    up(i , 1 , n)
        scanf("%lld%lld", &a[i].X, &a[i].Y);

    up(i , 1 , n)
        scanf("%lld%lld", &b[i].X, &b[i].Y);
}

ll Mul(ll x, ll y)
{
    if(y == 0) return 0;
    ll cur = Mul(x , y / 2);
    if(y % 2 == 1) return ((cur + cur) % oo + x) % oo;
    else return (cur + cur) % oo;
}

ll Pow(ll x, ll y)
{
    if(y == 0) return 1;
    ll cur = Pow(x , y / 2);
    if(y % 2 == 1) return Mul(Mul(cur , cur) % oo, x) % oo;
    return Mul(cur , cur) % oo;
}

void Solve()
{
    up(i , 1 , n)
        printf("%lld ", Mul(a[i].X, a[i].Y));

    printf("\n");

    up(i , 1 , n)
        printf("%lld ", Pow(b[i].X, b[i].Y));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
 // freopen(TITLE".OUT", "w", stdout);

    int Test = 1;
    //scanf("%ld", &Test);
    up(i , 1 , Test) {
        Init();
        Solve();
    }
}


//-----------------------------------------------------
/// SOLUTION
///
///
//-----------------------------------------------------



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
