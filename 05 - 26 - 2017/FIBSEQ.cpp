#include <bits/stdc++.h>
#include <ctime>
#define N 501
#define M 123456789

//---------------------------------------
/// YÊU CẦU :
/// T test, mỗi Test~~~~ Nhập  : n , p , k;
/// Hỏi có tồn tại trong [p , p + n - 1] 1 đoạn gồm các số liên tiếp CHIA HẾT K hay không;

using namespace std;
string s;

void Fibo()
{
    Fb[1] = 0; Fb[2] = 1;
    for(int i = 3; i <= 10000000; i++)
        Fb[i] = Fb[i - 1] + Fb[i - 2];
}

void Init()

{
    cin >> n >> p >> k;
}

void Solve()
{

}

int main()
{
  //  freopen("FIBSEQ.INP", "r", stdin);
    //freopen("FIBSEQ.OUT", "w", stdout);

    Fibo();
    int T; scanf("%lld", &T);
    for(;T >= 1;T--)
    {
        Init();
        Solve();
    }
}
