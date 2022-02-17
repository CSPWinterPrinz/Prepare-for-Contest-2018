#include <bits/stdc++.h>

//*****************************************************
/// Quay lui dòng 1, mỗi lần quay lui thì khôi phục bảng A;
/// Có ô 1, 2 dòng 1 -> ô 2 dòng 2 -> cả dòng 2 -> cả bảng

//*****************************************************

#define N 12
#define oo 1000000000

#define up(i , A , b) for(int i = A ; i <= b; i++)
#define down(i , A , b) for (int i = A; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "TABLE3"

#define gc getchar
#define pc putchar

//*****************************************************

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

vector <int> e[N], w[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
string s;
bool l;

ll n, m, A[N][N], B[N][N], res = 0;

void Init()
{
    cin >> n >> m;

    up(i , 1 , n)
        up(j , 1, m)
            cin >> B[i][j];
}

ll Find(int i, int j)
{
    up(v , 0 , 2)
        if( ( v + A[i - 1][j - 1] + A[i - 1][j + 1] + A[i - 2][j] ) % 3 == B[i - 1][j] ) return v;
    return -1;
}

bool Rebuild()
{
    up(i , 2 , n)
        up(j , 1 , m)
        {
            A[i][j] = Find(i , j);
            if(A[i][j] == -1) return false;
        }

    up(v , 1 , n)
        up(i , 1 , m)
            if(B[v][i] != (A[v - 1][i] + A[i + 1][v] + A[i][v - 1] + A[i][v + 1]) % 3 ) return false;
    return true;
}

void Try(int pos, int maxpos)
{


    up(i , 0 , 2) {
        A[1][pos] = i;

        if(pos == maxpos) {
            bool ok = Rebuild();
            if(ok) res++;
        }
        else Try(pos + 1, maxpos);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    Init();
    Try(1 , m);
    cout << res;
}


