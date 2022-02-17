#include <bits/stdc++.h>

#define up(i , a , b) for(int i = a ; i <= b; ++i)
#define up2(i , a , b , c) for(int i = a ; i <= b; i += c)
#define down(i , a , b) for (int i = a; i >= b; --i)
#define down2(i , a , b , c) for (int i = a; i >= b; i -= c)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "HASH"

#define _ << ", " <<
#define db(x) cout << #x << " ~~ " << x <<endl

#define X first
#define Y second

#define gc getchar
#define pc putchar

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int N = 100005;
const int oo = 1000000000;
const int M = 1000000007;
bool DEBUG = 1;

string s, t;
ll n, m, HasUp[N], HasDow[N], HashT, Pow26[N];

void Init()
{
    cin >> s;
    cin >> t;
    n = s.length(); m = t.length();
    s = "@" + s; t = "@" + t;
    cout << s; cout << " " << s[n] << endl << m << " " << n << endl;;
    HasUp[1] = s[1] - 'a'; HasDow[n] = s[n] - 'a'; HashT = t[1] - 'a';

    up(i , 2 , n) HasUp[i] =  ((HasUp[i - 1] * 26) % M + (s[i] - 'a')) % M;
    down(i , n - 1 , 1) HasDow[i] =  ((HasDow[i + 1] * 26) % M + (s[i] - 'a')) % M;
    up(i , 2 , m) HashT = ((HashT * 26) % M + (t[i] - 'a')) % M;
}

ll GetHash(ll i, ll j)
{
    ll cur = ((HasUp[j] - (HasUp[i - 1] * Pow26[j - i + 1])) % M);
    if(cur < 0) cur += M;
    return cur;
}

ll GetHash2(ll i, ll j)
{
    ll cur = ((HasDow[i] - (HasDow[j + 1] * Pow26[j - i + 1])) % M);
    if(cur < 0) cur += M;
    return cur;
}

void Solve()
{
    up(i , 1 , n - 1)
        up(j , i + 1 , n)
            if(GetHash(i , j) == GetHash2(i , j))
                //cout << s.substr(i , j - i + 1) << endl;
                db(GetHash(i , j) _ GetHash2(i , j) _ i _ j);

    cout << "------------\n\n";

    up(i , 1 , n - m + 1)
        if(GetHash(i , i + m - 1) == HashT)
            cout << s.substr(i , m) << " " << i << endl;

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
        Pow26[0] = 1;
        up(i , 1 , N) Pow26[i] = (Pow26[i - 1] * 26) % M;
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
