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
#define TITLE "433BDv1"

#define gc getchar
#define pc putchar
#define length Len

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int N = 100006;
const int oo = 1000000000;
bool DEBUG = 1;
struct Pair
{
    ll day, cost;
}
;

ll n, m, k, pre[N], res = 0;
vector <Pair> Di[N], Ve[N];

void Print()
{
    up(i , 1 , n) {
        cout << "City (" << i << ")" << endl << endl;
        cout << setw(4) << "Di :" << endl << endl;
        up(j , 0 , (int) Di[i].size() - 1)
            cout << setw(8) << Di[i][j].day << " " << Di[i][j].cost << endl;
        cout << setw(4) << "Ve :" << endl << endl;
        up(j , 0 , (int) Ve[i].size() - 1)
            cout << setw(8) << Ve[i][j].day << " " << Ve[i][j].cost << endl;
        cout << endl << endl << endl;
    }
}

void Init()
{
    cin >> n >> m >> k;

    up(i , 1 , m) {
        ll ngay, val, u, v, cost;
        cin >> ngay >> u >> v >> val;
        if(v == 0) {
            Pair cur; cur.day = ngay; cur.cost = val;
            Di[u].pb(cur);
        }
        if(u == 0) {
            Pair cur; cur.day = ngay; cur.cost = val;
            Ve[v].pb(cur);
        }
    }
}

void Sort()
{
    up(i , 1 , n) {
        sort(Di[i].begin(), Di[i].end(), [] (const Pair &p, const Pair &q)
             {
                 return p.day < q.day;
             });

        sort(Ve[i].begin(), Ve[i].end(), [] (const Pair &p, const Pair &q)
             {
                 return p.day < q.day;
             });
    }
    if(DEBUG) Print();
}

void Solve()
{
    up(i , 1 , n) {
        ll curans = oo;

        fill(pre + 1, pre + Ve[i].size() + 1, oo);
        down(j , (int) Ve[i].size() - 1 , 0) {
            pre[j] = min(pre[j + 1], Ve[i][j].cost);
            //cout << pre[j] << " ";
        }

        if(Ve[i].size() == 0) {cout << -1; exit(0);}

        up(j , 0 , (int) Di[i].size() - 1) {

            ll id = (upper_bound(Ve[i].begin() , Ve[i].end(), Pair {Di[i][j].day + k, 0} , [] (const Pair &p, const Pair &q)
                                {
                                    return p.day < q.day;
                                }) - Ve[i].begin());

            if(DEBUG) cout <<  "(" << id << ", " << Di[i][j].day + k << ", " << pre[id] + Di[i][j].cost << ")   ";

            if(id < Ve[i].size())
                curans = min(curans, pre[id] + Di[i][j].cost);
        }

        res += curans;
        if(curans == oo) {cout << -1 << " " << curans << " " << i; exit(0);}
        //cout << endl;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
//    freopen(TITLE".OUT", "w", stdout);

    int Test = 1;
  //  cin >> Test;
    up(i , 1 , Test) {
        Init();
        Sort();
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
