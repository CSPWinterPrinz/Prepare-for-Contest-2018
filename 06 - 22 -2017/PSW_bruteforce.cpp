#include <bits/stdc++.h>

//-----------------------------------------------------
/// DFS TRÂU để mò đường đi
/// Ăn Sub 1 nhỏ;
//-----------------------------------------------------

#define N 2001
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "PSW"

#define gc getchar
#define pc putchar

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

vector <int> e[N], w[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
stack <int> st;
string s;

bool avail[N][N], ok = false;
ll a, b, x, y, m;
char ans[N];
ll cnt = 0;

void Init()
{
    cin >> a >> b >> x >> y >> m;
    memset(avail , 0, sizeof(avail));
    ans[0] = '0';
}

void Solve(ll cnt, char ans[])
{
    char res[N];
    ll dem = 0;
    ll cur = 1;
    ans[++cnt] = '@';
    up(i , 1 , cnt) {
        if(ans[i] == ans[i - 1]) cur++;
        else {
            if(ans[i - 1] != '0') cout <<  ans[i - 1];
            if(cur != 1) cout << cur;
            cur = 1;
        }
    }

}

void Visit(ll u, ll v)
{
    if(ok) return;
    if(avail[u][v]) return;
    avail[u][v] = true;

    if(u == x && v == y) {
        Solve(cnt , ans);
        ok = true;
        return;
    }

    ans[++cnt] = 'W';    /// Trace
    Visit(v , u);        /// Visit W
    cnt--;               /// Comeback

    if(u + v <= m) {
        ans[++cnt] = 'P';    /// Trace
        Visit(u + v, v);     /// Visit P
        cnt--;
    }
    if(u - v >= 0) {
        ans[++cnt] = 'S';    /// Trace
        Visit(u - v, v);     /// Visit S
        cnt--;               /// Comeback
    }

}

int main()
{
  //  ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    Init();
    Visit(a , b);
}



