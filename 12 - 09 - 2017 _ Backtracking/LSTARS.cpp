#include <bits/stdc++.h>

/// ---------------SOL------------------
/// Quay lui, đặt cận laoị TH 12!, lấy kết quả đầu tiên
/// Coi các vị trí chưa x hoặc ký tự, sắp thành 1 mảng.
/// Đánh số lần lượt các đỉnh của sao David là 1, 2, .. 12
///
/// ---------------SOL------------------

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

ll c[N], Const[N], cnt = 0, a[N], Star[25], res[25], CountX = 0;
char Ch[N][N];
ll V[N], vc = 0, V2[N], vc2 = 0;
bool DEBUG = 0;

string s[N];

/// V[i] : vị trí là đã được điền ở đỉnh của sao. vc là đếm số đỉnh đã ghi chữ cái
/// V2[i] : Tên chữ cái đc điền tương ứng vs vị trí V[i] (chữ cái convert sang số)
/// c[i] : đỉnh thứ i đã được điền hay chưa (bool)

/// Sao David đã đc điền x vị trí, như test đề là 3, 7, 9.
/// Vậy trong mảng quay lui ta phải giữ nguyên các vị trí ấy.
/// Star : mảng lưu các kết quả quay lui.

void Init()
{
    memset(c , 0 , sizeof(c));
    memset(Star, 0 ,sizeof(Star));
    fill(res, res + 20 + 1, 1000);

    up(i , 1 , 5) {
        cin >> s[i];
        up(j , 1,  9) {
            Ch[i][j] = s[i][j - 1];
            char x = Ch[i][j];    if(x == 'x') CountX++;

            if(x != '.') {
                Const[++cnt] = x; ///
                if(x - 'A' >= 0 && x - 'A' <= 11) {
                    c[x - 'A' + 1] = 1, V[++vc] = cnt;   /// Danh dau
                    V2[++vc2] = x - 'A' + 1;
                }
            }
        }
    }

    if(DEBUG) {
        up(i , 1 , 12) cout << c[i] <<  " "; cout << endl;
        up(i , 1 , vc) cout << V[i] << " "; cout << endl;
        up(i , 1 , vc2) cout << V2[i] << " "; cout << endl;
    }
}

void Print()
{
    ll id_a = 0;
    up(i , 1 , 12)
        if(Star[i] == 0) Star[i] = a[++id_a];
/*
    up(i , 1 , 12)
        cout << Star[i] << " ";
    cout << endl;
    */
}

bool Check_Sum() /// O(1)
{
    return ((Star[1] + Star[3] + Star[6] + Star[8] == 26)
        && (Star[1] + Star[4] + Star[7] + Star[11] == 26)
        && (Star[2] + Star[3] + Star[4] + Star[5] == 26)
        && (Star[2] + Star[6] + Star[9] + Star[12] == 26)
        && (Star[5] + Star[7] + Star[10] + Star[12] == 26)
        && (Star[8] + Star[9] + Star[10] + Star[11] == 26));
}

void Update()
{
    up(i , 1 , 12)
        if(Star[i] != res[i]) {
            if(Star[i] < res[i])
                 swap(res , Star);
            break;
        }
}

void Solve()
{
    ll xyz = 0, hadz = 0;
    up(i , 1 , 12) if(!c[i]) a[++xyz] = i;             /// Mảng chứa các số chưa đc điền vào, dùng để quay lui

    ///up(i , 1 , xyz) cout << a[i] << " "; cout << endl;

    do
    {
        memset(Star, 0 , sizeof(Star));
        ll id = 0, id2 = 0;
        up(i , 1 , 12)
            if(c[i]) Star[V[++id]] = V2[++id2];         /// Điền các vị trí bất biến (đã đc điền từ đầu) vào mảng quay lui.

        Print();                                        /// Quay lui hoán vị các phần tử mảng a, để gán lại cho mảng Star

        if(Check_Sum()) {                               /// Kiểm tra tổng các hàng có đều = 26 hay ko
            Update();                                   /// Nếu có thì Update kết quả vào mảng res;
            break;
        }

    }
    while(next_permutation(a + 1, a + xyz + 1));        /// Sinh hoán vị mảng a cho trc.

    if(DEBUG) {
        up(i , 1 , 12)
            cout << (char) (res[i] - 1 + 'A')  << " ";
        cout << endl;
    }
}

void PrintResult()
{

    ll cur = 0;
    up(i , 1 , 5) {
        up(j , 1 , 9) {
            if(Ch[i][j] != '.') cout << (char) (res[++cur] - 1 + 'A');
            else cout << '.';
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen(TITTLE".inp", "r", stdin);
    //freopen(TITTLE".out", "w", stdout);

    int Test = 1;
    up(i , 1 , Test) {
         Init();
         if(CountX == 12) {                            /// Cả 12 đỉnh đều là 'x'.
            string t = "ABDLHJFKECGI";
            up(i , 1 , 12)
                res[i] = (ll) (t[i - 1] - 'A' + 1);
         }
         else Solve();
         PrintResult();
    }
}
