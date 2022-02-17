#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// f(i) : Giá trị max <= i trong dãy.
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
#define TITLE ""

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
ll f[N], m, n, a[N], res = 0;

struct T
{

};

void Init()
{
    cin >> n >> m;
    up(i , 1 , n)
        cin >> a[i];
    sort(a + 1, a + n + 1);
}


void Solve()
{
    up(i , a[1] , m) {
        f[i] = a[upper_bound(a + 1, a + n + 1, i) - a - 1];
        cout << f[i] << " " << i << endl;
    }

    up(i , 1 , n - 2)
        up(j , i + 1, n - 1)
            {
                ll cur = f[m - a[i] - a[j]];
                if(m - a[i] - a[j] > 1 && cur > a[j]) res = max(res , cur + a[i] + a[j]);
            }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 //   freopen(TITLE".INP", "r", stdin);
   // freopen(TITLE".OUT", "w", stdout);

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
