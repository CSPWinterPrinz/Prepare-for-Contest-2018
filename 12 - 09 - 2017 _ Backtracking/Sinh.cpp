#include <bits/stdc++.h>

#define up(i , a , b) for(int i = a; i <= b; i++)
#define down(i , a , b) for(int i = a; i >= b; i--)

#define endl '\n'
#define TITTLE "LSTARS"

#define pb push_back
#define mp make_pair

#define pc putchar
#define gc getchar

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 15;
const int oo = 1000000000;

using namespace std;


void Init()
{

}

void Solve()
{
    ll s[N];
    cout << "(";
    up(i , 1 , 6)
    {
        up(z , 0 , 3) cin >> s[z];
        if(i > 1) cout << setw(5) << "(";
        else cout << "(";
        up(j , 0 , 3) {
            cout << "Star[" << s[j] << "]";
            if(j < 3) cout << " + ";
        }
        cout << " == 26) && ";
        cout << endl;
    }
    cout << ")";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen(TITTLE".inp", "r", stdin);
   // freopen(TITTLE".out", "w", stdout);

    int Test = 1;
    up(i , 1, Test) {
         Init();
         Solve();
    }

}
/*
1 3 6 8
1 4 7 11
2 3 4 5
2 6 9 12
5 7 10 12
8 9 10 11
*/
