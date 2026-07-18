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
 
vector<vi> g;
vi c;
 
void dfs(int u) {
    for (int v: g[u]) {
        if (c[v] == -1) {
            c[v] = 1-c[u];
            dfs(v);
        }
    }
}
 
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        g.assign(n, vi());
        c.assign(n, -1);
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        c[0] = 0;
        dfs(0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += c[i];
        }
        if (cnt >= (n-cnt)) {
            cout << n-cnt << endl;
            for (int i = 0; i < n; i++) {
                if (c[i] == 0) {
                    cout << i+1 << ' ';
                }
            }
            cout << '\n';
        }else {
            cout << cnt << endl;
            for (int i = 0; i < n; i++) {
                if (c[i] == 1) {
                    cout << i+1 << ' ';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}
