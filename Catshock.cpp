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


vector<vector<int>> g;
vi c;

void dfs(int u) {
    for (int v: g[u]) {
        if (c[v] == -1) {
            c[v] = 1-c[u];
            dfs(v);
        }
    }
}

void solve() {
    int n; cin >> n;
    g.assign(n, vector<int>());
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    c.assign(n, -1);
    c[0] = 0;
    dfs(0);
    queue<int> q;
    vi deg(n);
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            q.push(i);
        }
        deg[i] = g[i].size();
    }
    int cur = c[0];
    vector<pii> ans;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == n-1) {
            continue;
        }
        if (c[u] == cur) {
            ans.push_back({1, -1});
            ans.push_back({2, u+1});
            cur = 1-cur;
        }else {
            ans.push_back({1, -1});
            ans.push_back({1, -1});
            ans.push_back({2, u+1});
        }

        for (int v: g[u]) {
            deg[v]--;
            if (deg[v] == 1) {
                q.push(v);
            }
        }
    }
    cout << ans.size() << '\n';
    for (pii &u: ans) {
        if (u.s == -1) {
            cout << u.f << '\n';
        }else {
            cout << u.f << ' ' << u.s << '\n';
        }
    }
}

int main() {
    speedup
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
