#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// QHD : dp(i , j) : Số cách split xâu vs phần tử cuối là {i, j}
/// All  dp(i , j) += dp(k , i - 1) neeus {k, i - 1} < {i , j} && k != 0;
/// ta chỉ xét {a , i - 1} sao cho length (a , i - 1) <= length (i , j) <=> a >= 2i - j;

// Suy ra dp(i, j) += dp (k , i - 1) : k từ 2i - j -> i - 1;

/// Next(i, j) : Id phan tu 1st != nhau tinh tu i && j = Next(i + 1, j + 1); (i < j)
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
#define TITLE "2015D"

#define gc getchar
#define pc putchar

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int N = 5007;
const int oo = 1000000000;
bool DEBUG = 0;

struct T
{

};
ll n, sum[N][N], f[N][N];
int Next[N][N];
string s;

void Init()
{
    cin >> n;
    cin >> s;
    s = " " + s;
}

void Build_Next()
{
    down(i , n - 1 , 1)
        down(j , n , i) {
            if(s[i] != s[j]) Next[i][j] = 0;
            else Next[i][j] = Next[i + 1][j + 1] + 1;
        }

    if(DEBUG)
                up(i , 1 , n - 1) {
                    up(j , i + 1 , n)
                        cout << Next[i][j] << " " << i << " " << j << endl;
                    cout << endl;
                }
}

void Solve()
{
    up(j , 1 , n)
        up(i , 1,  j) {

            if(s[i] == '0') f[i][j] = sum[i][j] = 0;
            else
                if(i == 1)  f[i][j] = sum[i][j] = 1;
                else {
                    ll piv = 2 * i - j - 1;

                    f[i][j] += (sum[i - 1][i - 1] - sum[max((ll) 0, piv)][i - 1]) % oo;
                    f[i][j] %= oo;

                    if(piv >= 1 && (piv + Next[piv][i]) < i)
                        if(s[piv + Next[piv][i]] < s[i + Next[piv][i]])
                            {f[i][j] += (sum[piv][i - 1] - sum[piv - 1][i - 1]); f[i][j] %= oo;}
                }
            sum[i][j] = (sum[i - 1][j] + f[i][j]) % oo;
            //cout << i << " " << j << endl;
        }

    cout << (sum[n][n] + oo) % oo;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  //  freopen(TITLE".INP", "r", stdin);
   // freopen(TITLE".OUT", "w", stdout);

    int Test = 1;
  //  cin >> Test;
    up(i , 1 , Test) {
        Init();
        Build_Next();
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
