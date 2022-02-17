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
#define TITLE "TRACING"

#define gc getchar
#define pc putchar
#define length Len

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int N = 100005;
const int oo = 1000000000;
bool DEBUG = 1;
ll n;

struct Point
{
    ll x, y;
}
a[N], A, B;

ll cnt1 = 0, cnt2 = 0, res = 0;
stack <Point> St;
vector <Point> Up, Dn;
Point Tren[N], Duoi[N];

ll Area (Point X, Point Y, Point Z)
{
    ll X1 = X.x -Y.x, Y1 = X.y - Y.y, X2 = X.x - Z.x, Y2 = X.y - Z.y;
    return X1 * Y2 - X2 * Y1;
}

/// S(XYZ) > 0 => Z re trai
/// S(XYZ) < 0 => Z re phai

void Init()
{
    A.x = oo; B.x = -oo;
    cin >> n;
    up(i , 1 , n) {
        cin >> a[i].x >> a[i].y;
    }

    sort(a + 1, a + n + 1, [] (const Point &p, const Point &q)
         {
             return p.x < q.x || (p.x == q.x && p.y < q.y);
         });

    A = a[1]; B = a[n];

  //  cout << Area(a[1], a[3], a[2]) << " ";
    //cout << Area(a[1], a[2], a[4]) << " ";
}

void Devide()
{
    up(i , 2 , n - 1) {
        if(Area(A , a[i] , B) < 0) Up.push_back(a[i]);
        else Dn.push_back(a[i]);
    }
    Up.push_back(a[n]);
    Dn.push_back(a[n]);


 //   up(i , 0 , Up.size() - 1) cout << Up[i].x << " " << Up[i].y << endl;
 //   up(i , 0 , Dn.size() - 1) cout << Dn[i].x << " " << Dn[i].y << endl;
}

void ArcAB()
{
    St.push(a[1]);

    up(i , 0 , Up.size() - 1) {

        while(St.size() > 1) {
            Point X, Y;
            X = St.top(); St.pop();
            Y = St.top();

            St.push(X); /// De doan sau pop thi pop thang nay chu ko phai pop thg C

            if(Area(Y , X , Up[i]) < 0) { break;}
            else St.pop();
        }
        St.push(Up[i]);
    }

    cnt1 = St.size();

    while(!St.empty()) {
        //cout << St.top().x << " " << St.top().y << endl;
        Tren[St.size()] = St.top();
        St.pop();
    }

    up(i , 1 , cnt1)
        cout << Tren[i].x << " " << Tren[i].y << endl;
}

void ArcBA()
{
    St.push(a[1]);

    up(i , 0 , Dn.size() - 1) {

        while(St.size() > 1) {
            Point X, Y;
            X = St.top(); St.pop();
            Y = St.top();

            St.push(X);
            if(Area(Y , X , Dn[i]) > 0) break;
            else St.pop();
        }
        St.push(Dn[i]);
    }

    cnt2 = St.size();

    while(!St.empty()) {
        //cout << St.top().x << " " << St.top().y << endl;
        Duoi[St.size()] = St.top();
        St.pop();
    }

    up(i , 1 , cnt2)
        cout << Duoi[i].x << " " << Duoi[i].y << endl;
}

ll Count()
{
    up(i , 1 , cnt1 - 1) {
        res += abs(Area(a[1] , Tren[i] , Tren[i + 1]));
    }

    up(i , 1 , cnt2 - 1) {
        res += abs(Area(a[1] , Duoi[i] , Duoi[i + 1]));
    }
    cout << res / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
   // freopen(TITLE".OUT", "w", stdout);

    int Test = 1;
    //cin >> Test;
    up(i , 1 , Test) {
        Init();
        Devide();
        ArcAB();
        ArcBA();
        Count();
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

/*
4
0 0
1 1
1 0
0 1
*/
