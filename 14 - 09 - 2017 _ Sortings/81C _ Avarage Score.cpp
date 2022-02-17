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
#define TITLE "81C"

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
    ll val, id, ans;
}
a[N];

ll n, p, q;
bool fir;

void Init()
{
    cin >> n >> p >> q;
}

void Solve()
{
    up(i , 1 , n) cin >> a[i].val, a[i].id = i;
    if(p == q) {
        up(i , 1 , p) cout << 1 << " ";
        up(i , 1 , p) cout << 2 << " ";
        exit(0);
    }

    if(p < q)
         sort(a + 1, a + n + 1, [] (const T &p, const T &q)
         {
             return p.val < q.val || (p.val == q.val && p.id > q.id);
         });

    else sort(a + 1, a + n + 1, [] (const T &p, const T &q)
         {
             return p.val < q.val || (p.val == q.val && p.id < q.id);
         });

    //up(i , 1 , n) cout << a[i].val << " " << a[i].id << endl;

    up(i , 1 , max(p, q)) a[i].ans = p < q ? 2 : 1;
    up(i , max(p , q) + 1, n) a[i].ans = p < q ? 1 : 2;


    sort(a + 1, a + n + 1, [] (const T &p, const T &q)
         {
             return p.id < q.id;
         });

    up(i , 1 , n)
        cout << a[i].ans << " ";
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
