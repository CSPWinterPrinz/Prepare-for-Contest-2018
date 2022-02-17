#include <bits/stdc++.h>
#define N 1000001
using namespace std;

long long n, H[N], res, c[N * 2 + 1];
string s;

void Init()
{
    s.insert(0, "N");
    res = 0; H[0] = 0;
    fill(c + 0, c + N * 2 + 1, 1000000000);
    c[N] = 0;
    for(int i = 1; i < s.length(); i++)
    {
        H[i] = s[i] == 'A' ? H[i - 1] + 1 : H[i - 1] - 1;
        c[H[i] + N] = min(c[H[i] + N] , (long long) i);
    }

    for(int i = 1; i < s.length(); i++)
    {
        res = max(res , max(i - c[H[i] + N - 1], i - c[H[i] + N + 1]));
    }

    cout << res << endl;

}

 /// H(i) : Chenh lech (A - B) tu 1 -> i : H(i) = H(i - 1) + 1 neu s(i) = A
 ///                                       H(i) = H(i - 1) - 1 neu s(i) = B
/// ABBBBBBBBBBBAAAAAAAAAAAAAABABABABBABABABBAAAAAAAAAAAAAAAAAAAAAABAABAAAAAAABABABBABAABBBBBBBBBBBBBABABABABABBBB


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("ABSS.INP", "r", stdin);
    freopen("ABSS.OUT", "w", stdout);
    while(cin >> s)
    {
        Init();
    }
}
/*

#include <bits/stdc++.h>
#define N 1000124
using namespace std;

int n, k, res = 0, cnt1 = 0, cnt2 = 0, sumA[N], sumB[N], fir, las;
string s;

void Init()
{
    res = 0; cnt1 = 0; cnt2 = 0;
    sumA[0] = 0;  /// 1 den i co bnh so A
    sumB[0] = 0;  /// 1 den i co bnh so B
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'A') cnt1++;
        else cnt2++;
        sumA[i + 1] = cnt1;
        sumB[i + 1] = cnt2;
    }
}
 /// H(i) : Chenh lech cua A va B tu 1 -> i : H(i) = H(i - 1) + 1 neu s(i) = A
 ///                                          H(i) = H(i - 1) - 1 neu s(i) = B
void Solve()
{
    for(int i = 1; i < s.length(); i++)
    {
        for(int j = i + 1; j <= s.length(); j++)
        {
            if(abs((sumA[j] - sumA[i - 1]) - (sumB[j] - sumB[i - 1])) <= 1)
            {
                res = max(res, j - i + 1);
                if(res == j - i + 1) {
                    fir = i;
                    las = j;
                }
            }
        }
    }
    cout << res << endl;
    //cout << res << " " << fir << " " << las << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("ABSS.INP", "r", stdin);
    freopen("ABSS.OUT", "w", stdout);
    while(cin >> s)
    {
        Init();
        Solve();
    }
}
*/
