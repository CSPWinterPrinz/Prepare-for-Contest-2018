#include <bits/stdc++.h>
#define N 1001
#define M 123456789

using namespace std;
string s;
long long n, Next[N][N], L;

void Build_Next()
{
    //s = s + "@";
    L = s.length() - 1;

  //  for(int i = 1; i < L; i++) {
    //    Next[i][i + 1] = s[i] == s[i + 1]
//zcaabcaaaa
    for(int i = L - 1; i >= 0; i--)
        for(int j = L; j >= i + 1; j--)
            Next[i][j] = s[i] == s[j] ? Next[i + 1][j + 1] : i;
    for(int i = 0; i <= L; i++)
    {
        for(int j = i + 1; j <= L; j++)
           {
                if(Next[i][j] == 0 && i != 0 && j != 0) Next[i][j] = L + 1;
                cout << Next[i][j] << " ";
           }
           cout << endl;
    }
}

void Solve(int k)
{
    long long res = 0;
    for(int i = 0; i <= L; i++)
        for(int j = i + 1; j <= L; j++)
        {
            long long cnt = 0, p = i, pre = i;
            while(true) {
                cout << p << " ";
                p = Next[i][j];
                p = p == pre ? pre + 1 : p;
                pre = p;
                cnt++;
                if(cnt == k) {
                    break;
                }
                if(p > j - 1) break;
                if(p == L) break;
            }
            if(cnt == k && p > j - 1) res = max(res , (long long) j - i + 1);
        }
    cout << res << endl;
}

// 9 5 -4 1 6 2 4 7 3 2
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("VIRUS.INP", "r", stdin);
   // freopen("VIRUS.OUT", "w", stdout);

    cin >> n;
    cin >> s; //cout << s.length() << endl;
    Build_Next();
    for(int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        Solve(x);
    }
}

/// Sub 3 : vòng for n^2, kiểm tra O (1)
/// f(i , j) ~ k = l : độ dài dài nhất để [i , i + l - 1] và [j , j + l - 1] ;
/// f(i , j) ~ k = s(i) == s(j) ? f(i + 1 , j + 1) ~ k + 1 : f(i + 1, j + 1) ~ (k - 1);


/// Chuẩn bị : Next(i , j) = p  : vị trí đầu tiên sai khác từ i ứng vs p;
///                                s(p) != s(j + p - i);
/// Next(i , j) = s(i) == s(j) ? Next(i + 1, j + 1) : i;


// --------------------------
Thử 2 điểm cắt : Tạo 3 xâu, tìm cách ghép lại = xâu thứ 2 ko, -> 6 cách
từ i -> j of xâu S1 có = đoạn u - > v of xâu S2 ko O(1) : Hash vs k = 0
//------------------
4mn cách đặt chồng
đặt chồng 2 bảng -> tìm HCN có toàn số 1 MAX
//---------------------------

/*
#include <bits/stdc++.h>
#define N 1001
#define M 123456789

using namespace std;
string s;
long long n, k, f[N][N];

void Hash()
{
    for(int i = 0; i < s.length() - 1; i++)
    {
        f[i][i] = s[i] - 'a' + 1;
        for(int j = i + 1; j < s.length(); j++)
        {
            f[i][j] = (f[i][j - 1] * 26 + (s[j] - 'a' + 1)) % M;
           // cout << f[i][j] << " ";
        }
       // cout << endl;
    }


}

void Solve(int k)
{
    long long res = 0;
    if(k != 0) {
        for(int len = 1; len <= s.length() / 2; len++){
            bool l = true;
            for(int i = 0; i < s.length() - len + 1; i++) {
                int cnt = 0;
                for(int j = i; j < i + len - 1; j++) {
                    if(s[j] != s[j + len]) {cnt++;}
                    if(cnt == k) {
                        if(res < len) {
                            res = max(res , (long long) len);
                            //cout << i << " " << i + len - 1 << endl;
                        }
                        l = false;
                        break;
                    }
                }
                if(!l) break;
            }
        }
        cout << res - 1 << endl;
    }

    else {
        for(int len = 1; len <= s.length() / 2; len++)
            for(int i = 0; i < s.length() - len * 2 + 1; i++)
                if(f[i][i + len - 1] == f[i + len][i + len + len - 1])
                    res = max(res , (long long) len);
        cout << res << endl;
    }

}

// 9 5 -4 1 6 2 4 7 3 2
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("VIRUS.INP", "r", stdin);
    freopen("VIRUS.OUT", "w", stdout);

    cin >> n;
    cin >> s; //cout << s.length() << endl;
    Hash();
    for(int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        Solve(x);
    }
}
*/
