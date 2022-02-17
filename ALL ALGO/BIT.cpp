#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// NKLAND, AREA, QBCAKE
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
#define TITLE "BIT"

#define _ << ", " <<
#define db(x) cout << #x << " ~~ " << x << endl

#define X first
#define Y second

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

ll n, a[N], cnt = 0, res = 0;


void Init()
{
    scanf("%lld", &n);
}

void Print()
{
    up(i , 1 , n)
        printf("%lld ", a[i]);
    printf("\n");
    res++;
}

void Attempt(int x)
{
    if(x > n) {
        Print();
        return;
    }

    up(i , 0 , 1) {
        a[++cnt] = i;
        Attempt(x + 1);
        cnt--;
    }
}

void Solve()
{
    Attempt(1);
    printf("%lld \n", res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
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
