#include <bits/stdc++.h>
#define N 124

using namespace std;
long long n, m, k, d[N], trace[N], trace_Ans[N][N], ans[N][N];
vector <int> e[N], w[N];
bool inque[N];

void Init()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u, v, W;
        cin >> u >> v >> W;
        e[u].push_back(v); w[u].push_back(W);
        e[v].push_back(u); w[v].push_back(W);
    }

}

void Dijkstra (int s)
{
    for(int i = 0; i <= n; i ++) d[i] = 1000000000;
    d[s] = 0;

    priority_queue < pair<int, int> , vector <pair<int, int> >, greater <pair<int,int> > > PQ;

    PQ.push(make_pair(d[s], s));

    while(!PQ.empty())
    {
        int u = PQ.top().second; PQ.pop();
        for(int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i];
            if(d[v] > d[u] + w[u][i]) {
                d[v] = d[u] + w[u][i];
                PQ.push(make_pair(d[v] , v));
                trace[v] = u;
            }
        }
    }
}
/// trace_Ans(i,j) : đỉnh trc j trong đoạn i -> j


void Build_Dijk ()
{
    for(int i = 1; i <= n; i++)
    {
        Dijkstra(i); //cout << i << " ";
        for(int j = 1; j <= n; j++)
        {
            ans[i][j] = d[j];
            trace_Ans[i][j] = trace[j];
            //cout << ans[i][j] << " ";
        }
    }
}

void Print_1(int u, int v)
{
    int i = v, cnt = 0, res[N];
    res[++cnt] = v;
    while(i != u) {
        res[++cnt] = trace_Ans[u][i];
        i = trace_Ans[u][i];
    }
    cout << cnt << " ";
    for(int i = cnt; i >= 1; i--)
        cout << res[i] << " ";
    cout << endl;
}

void Solve()
{
    for(int i = 1; i <= k; i++)
    {
        int x, u, v, res; cin >> x;
        switch (x)
        {
            case 0:
                cin >> u >> v;
                cout << ans[u][v] << endl;
                break;
            case 1:
                cin >> u >> v;
                Print_1(u,v);
                break;
        }
    }
}

int main()
{
    //freopen("FLOYD.INP", "r", stdin);
    //freopen("DIJKSTRA_n2.OUT", "w", stdout);

    Init();
    Build_Dijk();
    Solve();
  //  Dijkstra(1);
    //for(int i = 1; i <= n; i++) cout << d[i] << " ";
}

///http://vn.spoj.com/problems/QBSCHOOL/
/// DEBUG

