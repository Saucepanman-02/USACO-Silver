#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>

struct Epd {
    int x, y, z;
};
vector<vi> g;
vi dfs_num;
int cnt = 1;
vector<Epd> ans;

bool dfs(int u, int p) {
    dfs_num[u] = cnt; cnt++;
    int c = 0;
    vi l;
    for (int v: g[u]) {
        if (v == p)
            continue;
        if (dfs_num[v] == -1) {
            bool flag = dfs(v, u);
            if (flag) {
                c++;
                l.push_back(v);
            }
        }else if (dfs_num[v] > dfs_num[u]) {
            c++;
            l.push_back(v);
        }
    }
    if (c%2 && p != -1) {
        l.push_back(p);
        for (int i = 0; i <= c-1; i += 2) {
            ans.push_back({l[i], u, l[i+1]});
        }
    }else if (c%2 == 0) {
        for (int i = 0; i < c; i += 2) {
            ans.push_back({l[i], u, l[i+1]});
        }
    }else {
        for (int i = 0; i < c-1; i += 2) {
            ans.push_back({l[i], u, l[i+1]});
        }
    }
    return (c%2 == 0);
}

int main() {
    speedup;
    int n, m; cin >> n >> m;
    g.resize(n);
    dfs_num.assign(n, -1);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (dfs_num[i]==-1) {
            dfs(i, -1);
        }
    }
    cout << ans.size() << '\n';
    for (Epd &e: ans) {
        cout << e.x+1 << ' ' << e.y+1 << ' ' << e.z+1 << '\n';
    }
    return 0;
}
