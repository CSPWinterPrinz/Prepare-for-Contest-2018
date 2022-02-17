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
#define TITLE "ERATOS"

#define gc getchar
#define pc putchar
#define length Len

//-----------------------------------------------------
/// 2:34

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int N = 100006;
const int oo = 1000000000;
bool DEBUG = 1;

ll n, sum[N];
bool Prime[N];

void Init()
{
    scanf("%lld", &n);
}

void Eratos()
{
    memset(Prime, 1, sizeof(Prime));
    Prime[0] = Prime[1] = 0;

    up(i , 2 , N)
        if(Prime[i])
            up2(j , i * 2, N , i)
                Prime[j] = 0;
}

void Solve()
{
    up(i , 1 , n)
        sum[i] = sum[i - 1] + (Prime[i] ? 1 : 0);

    printf("%lld\n", sum[n]);
    up(i , 1 , n)
        if(Prime[i]) printf("%lld ", i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(TITLE".INP", "r", stdin);
  //  freopen(TITLE".OUT", "w", stdout);

    int Test = 1;
  //  cin >> Test;
    up(i , 1 , Test) {
        Init();
        Eratos();
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
