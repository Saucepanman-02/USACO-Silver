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

vector<vector<pii>> g;
vi cc;
vector<bool> vis;
int cnt;

void dfs(int u, int w0) {
    if (vis[u]) {
        return;
    }
    vis[u] = true;
    cc[u] = cnt;
    for (auto &[v, w]: g[u]) {
        if (w < w0) {
            continue;
        }
        dfs(v, w0);
    }
}

int main() {
    usopen("wormsort")
    speedup
    int n, m; cin >> n >> m;
    g.resize(n);
    vi p(n);
    cc.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i]; p[i]--;
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        flag = flag&(p[i] == i);
    }
    if (flag) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int l = 0, r = 1e9, ans = -1;
    while (r >= l) {
        int md = (r+l)/2;
        cnt = 0;
        vis.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, md);
                cnt++;
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            flag = flag&&(cc[p[i]] == cc[i]);
        }
        if (flag) {
            l = md+1;
            ans = md;
        }else {
            r = md-1;
        }
    }
    cout << ans << endl;
    return 0;
}
