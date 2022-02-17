#include<iostream>
#include<cmath>

using namespace std;

long long Muldiv( long long x, long long y, long long z)
  {
    long long m(x), n(z);
    while (n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
    x /= m; z /= m;
    return y / z * x;
  }

void PrintALine(int n)
{
    long long c(1);
    for (int k = 0 ; k < n; k++)
    {
        cout << c << " ";
        c = Muldiv(c, n-k, k+1);
    }
    cout << 1 << endl;
}

 int main ()
{
       long long m;
       cin >> m;
       for(int n1 = 0; n1 <= m; n1++)
         PrintALine(n1);

        for(int i = 1; i <= 1000; i++)
            cout << i << " ";
}
