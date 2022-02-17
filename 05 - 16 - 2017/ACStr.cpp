///-///////     ///////////     ////////        ///////////
///             //       //     //      //      //
///             //       //     //       //     ///////////
///             //       //     //       //     ///////////
///             //       //     //      //      //
///-///////     ///////////     ////////        ///////////


#include <bits/stdc++.h>
#define N 524

using namespace std;
long  long n, k;
string s;

/// Tao mang thong ke : tk[i][ch] = số lần ký tự c xuất hiện ở vị trí i (tương ứng khi nhân xâu W = S)
/// Tao mang tong :
/// Tao mang Max

void Init(string w)
{
    memset(tk, 0, sizeof(tk));
    int WL = w.length(), SL = s.length();
    for(int i = 0; i < WL; i++)
        for(int ch = i; ch < SL; ch += WL)
            tk[i][s[ch] - 'a']++;
}

void Solve()
{

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("ACStr.INP", "r", stdin);
    freopen("ACStr.OUT", "w", stdout);

    cin >> n >> k;

    cin >> s;
    for(int i = 1; i <= k; i++)
    {
        string w;
        cin >> w;
        Init(w);
        Solve(w);
    }
}

/*
*/

/// bài cuối : sub 1 : dãy con tăng
/// sub 2 : xâu con chung
/// sub 3 :


