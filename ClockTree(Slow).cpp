#include <bits/stdc++.h>

using namespace std;
#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(filename) do{freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);}while(0);
#define f first
#define s second
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>

vi c;
vector<vi> g;

void dfs(int u, int p) {
    for (int v: g[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        c[u] += (11-c[v]);
        c[v] = 11;
        c[u] %= 12;
    }
}

int main() {
    usopen("clocktree")
    int n; cin >> n;
    c.resize(n);
    vi co(n);
    for (int i = 0; i < n; i++) {
        cin >> co[i]; co[i]--;
    }
    g.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[j] = co[j];
        }
        dfs(i, -1);
        ans += (c[i] == 11 || c[i] == 0);
    }
    cout << ans << endl;
    return 0;
}
