#include <bits/stdc++.h>

//-----------------------------------------------------
/// m < 10^9 ko ăn đc -> Chuyển về địa điểm trung gian cho 2 thằng tìm nhau
/// Tìm được nhau khó thế nào???
/// Lạc nhau có phải muôn đời???
/// No, tìm đc hết. Đưa về tìm (a,b) => (GCD(a , b) , 0) và (c, d) => (GCD(x , y), 0)
/// ĐK cần và đủ để tìm đc nhau là GCD(a , b) == GCD(x , y) ; Ta sẽ biểu diễn các đi đó
//-----------------------------------------------------

#define N 1001
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <char, int>
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
bool l;

ll a, b, x, y, m;

void Init()
{
    cin >> a >> b >> x >> y >> m;
}

void GCD(ll m, ll n, vector <II> &ans)
{
    while(n != 0)
    {
        if(m >= n) {
            ans.pb(mp('S' , m / n));
            ans.pb(mp('W' , 1));
            ll r = m % n;
            m = n; n = r;
        }//cout << m << " " << n;
        else{
            ans.pb(mp('W' , 1));
            swap(m , n);
        }
    }
}

void Solve()
{
    vector <II> ab_to_gcd;
    vector <II> xy_to_gcd;

    GCD(a , b , ab_to_gcd);
    GCD(x , y , xy_to_gcd);

    //cout << ab_to_gcd.size() << " " << xy_to_gcd.size() << endl;

    up(i , 0 , ab_to_gcd.size() - 1) {
        cout << ab_to_gcd[i].first;
        if(ab_to_gcd[i].second != 1) cout << ab_to_gcd[i].second;
    }

    down(i , xy_to_gcd.size() - 1 , 0) {
        if (xy_to_gcd[i].first == 'S') cout << 'P';
        else if(xy_to_gcd[i].first == 'W') cout << '2';
        if(xy_to_gcd[i].second != 1) cout << xy_to_gcd[i].second;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);
    Init();
    Solve();
}


