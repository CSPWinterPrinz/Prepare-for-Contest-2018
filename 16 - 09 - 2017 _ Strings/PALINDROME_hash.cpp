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
#define TITLE "PALIN"

#define gc getchar
#define pc putchar

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int N = 100006;
const int oo = 1000000007;
const int M = oo + 7;
bool DEBUG = 1;
ll n, Hash[N], Hash2[N], Pow26[N];
string s, t;

struct T
{

};

void Build_Power()
{
    Pow26[0] = 1;
    up(i , 1 , 100006)
        Pow26[i] = Pow26[i - 1] * 26 % oo;
}

ll GetHash(int i, int j)
{
    ll cur = (Hash[j] - Hash[i - 1] * Pow26[j - i + 1]) % oo;
    if(cur < 0) cur += oo;
    return cur;
}

ll GetHash2(int i, int j)
{
    ll cur = (Hash2[i] - Hash2[j + 1] * Pow26[j - i + 1]) % oo;
    if(cur < 0) cur += oo;
    return cur;
}

void Init()
{
    cin >> t;
    s = t + t;
    s.insert(s.length() - 1, "1");

    ll z = 0; s[z] = '~';
    up(i , 0 , t.length() - 1) {
        s[++z] = t[i];
        s[++z] = '~';
    }

    n = s.length();

    Hash[0] = s[0] - 'a';
    up(i , 1 , n - 1)
        Hash[i] = ((Hash[i - 1] * 26) % oo + (s[i] - 'a')) % oo;

    Hash2[n - 1] = '~' - 'a';

    down(i , n - 2 , 0)
        Hash2[i] = ((Hash2[i + 1] * 26) % oo + (s[i] - 'a')) % oo;

  /*  up(i , 0 , n - 1) cout << Hash[i] << " " << Hash2[i] << endl;
    up(i , 1 , 256) cout << (char) i << " "; */
}

bool ok(ll M)
{
    up(i , 0 , n - M) {
        if(GetHash(i , i + M - 1) == GetHash2(i , i + M - 1)) return 1;
    }
    return 0;
}

void Solve()
{
    ll L = 1, H = n, res = 0;
    while(L <= H) {
        ll M = (L + H) / 2;
        M -= 1 - M % 2;
        if(ok(M)) {
            res = M;
            L = M + 2;
        }
        else H = M - 2;
        ///cout << M << " ";
    }
    ///cout << (res - 1) / 2 << " " << res;

    cout << (res - 1) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    int Test = 1;
 //   cin >> Test;
    up(i , 1 , Test) {
        Init();
        Build_Power();
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
