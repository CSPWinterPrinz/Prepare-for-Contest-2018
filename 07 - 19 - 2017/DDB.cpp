#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define up(i , a , b) for(int i = a ; i <= b; ++i)
#define up2(i , a , b, c) for(int i = a ; i <= b; i += c)
#define down(i , a , b) for (int i = a; i >= b; --i)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "DDB"

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

const int N = 2000002;
const int oo = 1000000000;

vector <int> e[N], w[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q; deque <int> Dq; stack <int> st;
string s;
bool DEBUG = 0;

struct T
{

};
bool Prime[N];
ll n, sum[N];

void Eratos()
{
    up(i , 1 , N) Prime[i] = 1;
    Prime[0] = 0; Prime[1] = 0;
    up(i , 2 , N)
        if(Prime[i])
            up2(j , i * 2 , N , i)
                Prime[j] = 0;
    if(DEBUG)
        up(i , 1,  100)
            if(Prime[i]) cout << i << " ";
    sum[0] = 0;
    up(i , 1 , N)
        sum[i] = Prime[i] ? sum[i - 1] + 1 : sum[i - 1];
}

void Init()
{
    read(n);
}

void Solve()
{
    writeln(sum[2 * n] - sum[n]);
    pc('\n');
/*
    cout << 100 << endl;
    up(i , 1 , 100)
        cout << i << " ";
        */
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    Eratos();
    ll Test = 1;
    read(Test);
    up(i , 1 , Test) {
        Init();
        Solve();
    }
}

