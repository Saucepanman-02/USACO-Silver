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
bool flag = false;
vector<bool> vis;

void dfs(int u, int p) {
    vis[u] = true;
    for (int v: g[u]) {
        if (v == p)
            continue;
        if (vis[v]) {
            flag = true;
        }else {
            dfs(v, u);
        }
    }
}

int main() {
    speedup
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        g.assign(n, vi());
        vi a(n, -1);
        for (int i = 0; i < n; i++) {
            int c; cin >> c; c--; a[i] = c;
            if (a[c] != i) {
                g[i].push_back(c);
                g[c].push_back(i);
            }
        }
        vis.assign(n, false);
        int cyc = 0, lin = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                flag = false;
                dfs(i, -1);
                if (flag) {
                    cyc++;
                }else {
                    lin++;
                }
            }
        }
        cout << cyc+(lin > 0) << ' ' << cyc+lin << '\n';
    }
    return 0;
}
