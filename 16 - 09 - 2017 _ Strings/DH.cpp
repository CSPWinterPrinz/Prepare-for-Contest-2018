#include<bits/stdc++.h>
#define finc(i,a,b) for (int i = (a), _b = (b); i <= _b; ++i)
#define fdec(i,a,b) for (int i = (a), _b = (b); i >= _b; --i)
#define ms(a, i) memset(a, i, sizeof(a))
#define sqr(a) (long long)(a) * (a)
#define X first
#define Y second
#define ii pair<int, int>
#define db(x) cerr << #x << " = " << x << endl;
#define eb(x, y) emplace_back(x, y)
#define ll long long
#define pb(x) push_back(x)
#define endl '\n'
#define sd(x) scanf("%d", &x)
#define mx(l, r) *max_element(l, r);

using namespace std;

const int oo = 1e9 + 7;
const int maxn = 5007;
int n, LCP[maxn][maxn];
ll pre[maxn][maxn], f[maxn][maxn];
string s;

void nhap() {
	cin >> n;
	cin >> s;
	s = '~' + s;
}

inline void Init(){
	fdec(i, n, 1)
		fdec(j, n, 1)
			if (s[i] == s[j])
				LCP[i][j] = LCP[i + 1][j + 1] + 1;
			else
				LCP[i][j] = 0;
}

inline int Cmp(int l, int r, int u, int v){
	int x = LCP[l][u];
	if (l + x - 1 < r){
		if (s[l + x] < s[u + x])
			return -1;
		else
			return 1;
	}
	else
		return 0;
}

void solve(){
	Init();
	finc(i, 1, n)
		finc(j, 1, i){
			if (s[j] == '0'){
				f[j][i] = pre[j][i] = 0;
			}
			else
			if (j == 1){
				f[j][i] = pre[j][i] = 1;
			}
			else{
				int r = j - 1;
				int l = r - i + j;
				f[j][i] += (pre[r][r] - pre[max(0, l)][r]) % oo;
				f[j][i] %= oo;
				if (l > 0 && Cmp(l, r, j, i) == -1){
					f[j][i] += (pre[l][r] - pre[l - 1][r]);
					f[j][i] %= oo;
				}
			}
			pre[j][i] = (pre[j - 1][i] + f[j][i]) % oo;
		}
}

void print(){
	cout << (pre[n][n] + oo) % oo;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	///		freopen("test.out", "w", stdout);
	#endif
	nhap();
	solve();
	print();
}
