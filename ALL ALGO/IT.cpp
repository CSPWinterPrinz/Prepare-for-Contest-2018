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
#define TITLE "INVERSE2"

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

const int N = 100002;
const int oo = 1000000000;

vector <int> e[N], w[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q; deque <int> Dq; stack <int> st;
string s;
bool DEBUG = 0;
ll n, a[N];

struct T
{
    ll val, val2, id;
}
b[N];

ll L[N << 2], H[N << 2], sum[N << 2], leaf[N];   /// nút pos quản lý đoạn từ L(pos) đến H(pos), sum(pos) là tổng giá trị của đoạn nút pos quản lý

    void Build(ll pos, ll low, ll high)              /// Dựng cây nút pos, với đoạn cần nhét vào cây là đoạn từ low -> high
    {
        L[pos] = low; H[pos] = high; sum[pos] = 0;   /// L(pos) = low, H(pos) = high, vì low, hihg là đầu, cuối đoạn cần quản lý

        if(low == high) {                            /// Khi low = high, tức là pos quản lý từ nút low đến low;
                                                     /// => nút pos quản lý 1 nút con => pos quả lý pos => pos là nút lá
            leaf[low] = pos;                         /// pos là nút lá.
            return;
        }

        ll mid = (low + high) / 2;                  /// Chắc m hiểu đoạn này r
        Build(pos << 1 , low , mid);
        Build((pos << 1) + 1 , mid + 1, high);
    }

    void Update(ll pos , ll add)                     /// Tăng nút pos lên giá trị = add;
    {
        for(int i = leaf[pos]; i >= 1; i >>= 1)      /// Update nút pos, thì phải thay đổi giá trị từ nút lá pos đi lên
            sum[i] += add;                           /// Đi lên từ nút pos đến nút 1, sum(i) += add; (add là
    }

    ll Querry(ll pos, ll low, ll high) /// Trả về đoạn từ low đến high mà nút pos quản lý có tổng trọng số là bnh (là số số đã đc nhét vào)
    {
        if(L[pos] > high || H[pos] < low) return 0;
        if(L[pos] >= low && H[pos] <= high) return sum[pos];

        return Querry(pos << 1, low , high) + Querry((pos << 1) + 1, low , high);
    }

void Ranking()
{
    sort(b + 1, b + n + 1, [] (const T &p, const T &q)
         {
             return p.val < q.val;
         });

    up(i , 1 , n)
        b[i].val2 = b[i].val == b[i - 1].val ? b[i - 1].val2 : i;

    sort(b + 1, b + n + 1, [] (const T &p, const T &q)
         {
             return p.id < q.id;
         });
    up(i , 1 , n)
        a[i] = b[i].val2;//, cout << a[i] << " ";
}

void Init()
{
    cin >> n;
    up(i , 1 , n)
        cin >> a[i], b[i].val = a[i], b[i].id = i;
    Ranking();
    Build(1 , 1 , n);
}

void Solve()
{
    ll res = 0;
    up(i , 1 , n) {
        res += Querry(1 , a[i] + 1, 100001);
        Update(a[i] , 1);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    int Test = 1;
    //cin >> Test;
    up(i , 1 , Test) {
        Init();
        Solve();
    }
}



