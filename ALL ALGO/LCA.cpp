SPOJ submission 20261222 (CPP14) plaintext list. Status: AC, problem TRIPHP, contest SPOJVN. By cspwprince711 (CSPWinterPrince), 2017-09-30 05:51:06.
#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// "NKLAND", AREA, QBCAKE
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
#define TITLE "TRIPHP"

#define gc getchar
#define pc putchar
#define length Len

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int N = 100004;
const int oo = 1000000000;
bool DEBUG = 1;

ll Log[N], n, h[N], par[N][20], m, cnt = 0;
vector <int> e[N];

struct T
{
	ll val, id;
}
;
vector <T> V,Place[N];

bool avail[N];

void BLog()
{
	Log[1] = 0;
	up(i , 2 , N) Log[i] = Log[i / 2] + 1;
}

void Init()
{
	cin >> n; m = n;
	up(i , 1 , n - 1) {
		int u, v; cin >> u >> v;
		e[u].pb(v); e[v].pb(u);
	}
	BLog();
	memset(avail , 0 , sizeof(avail));
}

void DFS(int u)
{
	up(i , 0 , (int) e[u].size() - 1) {
		int v = e[u][i];
		if(v != par[u][0]) {
			par[v][0] = u;
			h[v] = h[u] + 1;

			up(j , 1 , Log[N])
				par[v][j] = par[par[v][j - 1]][j - 1];
				//cout << u << " " << v << endl;
			T cur; cur.val = v;
			if(!avail[v]) cnt++, cur.id = cnt; V.pb(cur), avail[v] = 1;

			DFS(v);
		}
	}
}

ll LCA(int u, int v)
{
	/// Step 1

	if(h[u] < h[v]) swap(u , v);
	ll Dis = h[u] - h[v];

	up(i , 0 , Log[Dis])
		if((Dis >> i) & 1) u = par[u][i]; // nhay h(u) = h(v);
	if(u == v) return u;

	/// Step 2

	down(i , Log[N] , 0)
		if(par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

void Solve()
{
	V.pb({1 , 0});
	h[1] = 0;
	DFS(1);
	up(i , 0 , (int) V.size() - 1) V[i].id++;//, cout << V[i].val << " " << V[i].id << endl; cout << endl;

	sort(V.begin(), V.end(), [] (const T &p, const T &q)
		{
			return p.val < q.val;
		});
	//up(i , 0 , (int) V.size() - 1) cout << V[i].val << " "; cout << endl;


	///---------------------------------------------------------------

            up(i , 1 , m) Place[i].pb({1 , 0}); Place[1].pop_back();
            up(i , 1 , m){
                up2(j , i , m , i)
                    Place[i].pb(V[j - 1]);

                //(j , 0, Place[i].size() - 1) cout << Place[i][j].val << " "; cout << endl;

                sort(Place[i].begin(),Place[i].end(), [] (const T &p, const T &q)
                        {
                            return p.id < q.id;
                        });
            }






            up(i , 1 , m) Place[i].pb({1,0});

                        /*	up(i , 1,  m) {
                                cout << i << " ";
                                up(j , 0 , Place[i].size() - 1)
                                    cout << Place[i][j].val << " ";
                                cout << endl;
                            }
                        */

	///---------------------------------------------------------------

	ll res = 0;

	up(i , 1 , m) {
		res = 0;
		up(j , 1 , (int) Place[i].size() - 1)
			res += h[Place[i][j].val] + h[Place[i][j - 1].val] - h[LCA(Place[i][j].val , Place[i][j - 1].val)] * 2;//S, cout << Place[i][j].val << " " << Place[i][j - 1].val << " " << h[Place[i][j].val] << " " << h[Place[i][j - 1].val] << " " << h[LCA(Place[i][j].val , Place[i][j - 1].val)] << " ||  ";
		cout << res <<  endl;
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   // freopen(TITLE".INP", "r", stdin);
  //  freopen(TITLE".OUT", "w", stdout);

    int Test = 1;
    //cin >> Test;
    up(i , 1 , Test) {
        Init();
        Solve();
    }
}

/// https://open.kattis.com/problems/convexhull


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

