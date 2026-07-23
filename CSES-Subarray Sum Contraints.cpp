#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(file) do{freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);}while(0);
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define f first
#define s second
#define pdi pair<db, int>


vector<vector<pair<int, ll>>> g;
vector<bool> vis;
vll p;
bool flag = true;

void dfs(int u) {
    vis[u] = true;
    for (auto &[v, w]: g[u]) {
        if (!vis[v]) {
            p[v] = p[u]+w;
            dfs(v);
        }else {
            if (p[v] != p[u]+w) {
                flag = false;
            }
        }
    }
}
int main() {
    speedup
    int n, m; cin >> n >> m;
    g.resize(n+1);
    vis.assign(n+1, false);
    p.assign(n+1, 0);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w; u--;
        g[u].push_back({v, w});
        g[v].push_back({u, -w});
    }
    dfs(0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            p[i] = p[i-1];
            dfs(i);
        }
    }
    if (!flag) {
        cout << "NO" << endl;
    }else {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            cout << p[i]-p[i-1] << ' ';
        }
        cout << endl;
    }
    return 0;
}
