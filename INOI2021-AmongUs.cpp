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
vi c;
bool flag = false;
int pc, cnt;

void dfs(int u) {
    cnt++;
    pc += (1-c[u]);
    for (auto &[v, w]: g[u]) {
        if (c[u] == 0) { //parasite
            if (w == 1) {
                if (c[v] == -1) {
                    c[v] = 1;
                    dfs(v);
                }else if (c[v] == 0) {
                    flag = true;
                }
            }else {
                if (c[v] == -1) {
                    c[v] = 0;
                    dfs(v);
                }else if (c[v] == 1) {
                    flag = true;
                }
            }
        }else { //human
            if (w == 1) {
                if (c[v] == -1) {
                    c[v] = 0;
                    dfs(v);
                }else if (c[v] == 1) {
                    flag = true;
                }
            }else {
                if (c[v] == -1) {
                    c[v] = 1;
                    dfs(v);
                }else if (c[v] == 0) {
                    flag = true;
                }
            }
        }
    }

}

void solve() {
    int n, m; cin >> n >> m;
    g.assign(n, vector<pii>());
    c.assign(n, -1);
    for (int i = 0; i < m; i++) {
        int cl, u, v; cin >> cl >> u >> v;
        u--, v--;
        g[u].push_back({v, cl});
        g[v].push_back({u, cl});
    }
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (c[i] == -1) {
            cnt = 0; flag = false; pc = 0;
            c[i] = 0;
            dfs(i);
            if (flag) {
                cout << -1 << '\n'; return;
            }
            ans += max(cnt-pc, pc);
        }
    }
    cout << ans << '\n';
}

int main() {
    speedup
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
