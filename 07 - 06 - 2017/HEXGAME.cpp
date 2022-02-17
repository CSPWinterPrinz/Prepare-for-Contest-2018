#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// Mỗi trạng thái là đỉnh của đồ thị. Loang để đến trạng thái chuẩn.
/// Cho hinhf tam giác, mình lưu = mảng dài
/// Loang từ trạng thái gốc sang trạng thái cần tìm
/// bd(i , j) : Chỉ số của phép biến đổi thứ i vs phần tử j
//-----------------------------------------------------

#define N 101
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; ++i)
#define down(i , a , b) for (int i = a; i >= b; --i)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "HEXGAME"

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

vector <int> e[N], w[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <string> DQ;
stack <int> st;
string s;
bool l;

ll bd[N][N], n, Val[N];

struct T
{

};

void Build()
{
    string sz[7] = {"231456" , "143526" , "152436" , "125463" , "132456" , "123645"};
    up(i , 0 , 5) {
        up(j , 0 , 5)
            bd[i + 1][j + 1] = sz[i][j] - '0', cout << bd[i+1][j+1] << " ";
        cout << endl;
    }
}

ll Convert(string s)
{
    ll z = 0, ln = s.length() - 1;
    up(i , 0 , ln)
        z = z * (ln + 1) + (s[i] - '0');
    return z;
}

void Init()
{
    cin >> n;
    s = "";
    up(i , 1 , n * (n + 1) / 2)
        {char a; cin >> a; s = s + a;}
        cout << s << endl;
    DQ.pb(s);

    up(i , 1 , n) Val[i] = oo;
    Val[Convert(s)] = 0;
}

void Solve()
{
    while(!DQ.empty())
    {
        string u = DQ.front(); DQ.pop_front();

        up(i , 0 , 5) {
            string v; if(Convert(v) == 486) {cout << Val[Convert(v)]; exit(0);}
            up(j , 0 , 5)
                v[j] = u[bd[i][j]];
            ll cp = i < 4 ? 1 : 0;
            if(Val[Convert(v)] + cp < Val[Convert(u)]) {
                Val[Convert(u)] = Val[Convert(v)] + cp;

                if(cp == 0) DQ.pb(v);
                else DQ.push_front(v);
            }
        }
        cout << 1 << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    Build();
    Init();
    cout << 2;
    Solve();
}
