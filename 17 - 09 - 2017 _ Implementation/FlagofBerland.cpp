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
#define TITLE ""

#define gc getchar
#define pc putchar
#define length Len

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int N = 106;
const int oo = 1000000000;
bool DEBUG = 1;

struct T
{

};
ll m, n;
char a[N][N];

void Init()
{
    cin >> n >> m;
    up(i , 1 , n) {
        string s; cin >> s;
        up(j , 1 , m)
            a[i][j] = s[j - 1];
    }

    if(n % 3 != 0 && m % 3 != 0) {cout << "NO"; exit(0);}
}

bool Check1(char x, ll f, ll l)
{
    up(i , f , l) {
        up(j , 1 , m)
            if(a[i][j] != x) return 0;
    }
    return 1;
}

bool Check2(char x, ll f, ll l)
{
    up(j , f , l) {
        up(i , 1 , n)
            if(a[i][j] != x) return 0;
    }
    return 1;
}

void Solve()
{
    bool ok1 = 0, ok2 = 0;

    if(n % 3 == 0) {
        char x = a[1][1], y = a[n / 3 + 1][1], z = a[n / 3 * 2 + 1][1];
        ok1 = (Check1(x, 1, n / 3) && Check1(y , n / 3 + 1, n / 3 * 2) && Check1(z , n / 3 * 2 + 1, n)) && x != y && y != z && z != x;
    }

    if(m % 3 == 0) {
        char x = a[1][1], y = a[1][m / 3 + 1], z = a[1][m / 3 * 2 + 1];
        ok2 = (Check2(x, 1, m / 3) && Check2(y , m / 3 + 1, m / 3 * 2) && Check2(z , m / 3 * 2 + 1, m)) && x != y && y != z && z != x;
    }

    if(ok1 || ok2) cout << "YES";
    else cout << "NO";
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
