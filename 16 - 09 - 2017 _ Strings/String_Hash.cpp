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


//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int N = 100006;
const int oo = 1000000000;
bool DEBUG = 1;
string s, t;
ll Pow26[N], HashT[N], HashS[N];

struct T
{

};

void Powerup()
{
    Pow26[0] = 1;
    up(i , 1 , 100000) {
        Pow26[i] = Pow26[i - 1] * 26 % oo;
    }
}

void Init()
{
    cin >> s; HashS[0] = s[0] - 'a';
    up(i , 1 , s.length() - 1)
        HashS[i] = (HashS[i - 1] * 26 % oo + (s[i] - 'a')) % oo;

    cin >> t; HashT[0] = t[0] - 'a';
    up(i , 1 , t.length() - 1)
        HashT[i] = (HashT[i - 1] * 26 % oo + (t[i] - 'a')) % oo;
}

ll GetHash(ll i, ll j)
{
    ll cur = (HashS[j] - HashS[i - 1] * Pow26[j - i + 1]) % oo;
    if(cur < 0) cur += oo;
    return cur;
}

void Solve()
{
    ll res = 0;
    up(i , 0 , s.length() - t.length())
    {
        if(GetHash(i , i + t.length() - 1) == HashT[t.length() - 1]) res++;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen(TITLE".INP", "r", stdin);
  //  freopen(TITLE".OUT", "w", stdout);

    int Test = 1;
    //cin >> Test;
    up(i , 1 , Test) {
        Init();
        Powerup();
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

