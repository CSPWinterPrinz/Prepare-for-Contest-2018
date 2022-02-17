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
#define TITLE "CONVEXHULL"

#define gc getchar
#define pc putchar
#define length Len

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int N = 10004 ;
const int oo = 1000000000;
bool DEBUG = 1;

ll n;


struct Point
{
	ll x, y;
}
a[N];
vector <Point> Convex;

ll CWCC(Point A, Point B, Point C)
{
	ll X1 = A.x - B.x, Y1 = A.y - B.y, X2 = A.x - C.x, Y2 = A.y - C.y;
	return X1 * Y2 - X2 * Y1;
}

ll Dis(Point A, Point B)
{
	return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

void Print()
{
	up(i , 1 , n) {
		cout << a[i].x << " " << a[i].y << endl;
	}
}

void Init()
{
    Convex.clear();
    up(i , 1 , n)
		cin >> a[i].x >> a[i].y;

	sort(a + 1, a + n + 1, [] (Point p, Point q)
		{
			return p.x < q.x;
		});

	sort(a + 2, a + n + 1, [] (const Point &p, const Point &q)
		{
			if(CWCC(a[1] , p , q) == 0)
				return Dis(a[1] , p) < Dis(a[1] , q);
			return CWCC(a[1] , p , q) < 0;
		});
	//Print();

	}

void Solve()
{
    Convex.pb(a[1]); Convex.pb(a[2]);

	up(i , 3 , n) {
        while(Convex.size() > 1 && (CWCC(Convex[Convex.size() - 2], Convex[Convex.size() - 1] , a[i]) >= 0 || Convex[i].x == Convex[i - 1].x && Convex[i].y == Convex[i - 1].y)) /// Re trai || thẳng hàng
            Convex.pop_back();
        Convex.pb(a[i]);
	}
    if(Convex.size() == 2 && Convex[0].x == Convex[1].x && Convex[0].y == Convex[1].y) Convex.pop_back();
	cout << Convex.size() << endl;
    up(i , 0 , Convex.size() - 1)
        cout << Convex[i].x << " " << Convex[i].y << endl;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
   // freopen(TITLE".OUT", "w", stdout);

    int Test = 1;
    //cin >> Test;
    while(cin >> n) {
        if(n == 0) exit(0);
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

/*
SPOJ submission 20230249 (CPP14) plaintext list. Status: AC, problem METERAIN, contest SPOJVN. By long10024070 (long10024070), 2017-09-26 16:24:50.

 */
