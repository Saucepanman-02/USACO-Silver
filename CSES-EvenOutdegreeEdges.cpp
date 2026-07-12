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

int n, m;
vector<vi> g;
vi deg;
vi dfs_num, vis;
int cnt = 1;

//-1-> unvisited; 0-> visited but not completed; 1-> visited and completed

void dfs(int u, int p) {
    vis[u] = 0;
    dfs_num[u] = cnt; cnt++;
    for (int v: g[u]) {
        if (v == p)
            continue;
        if (vis[v] == -1) {
            dfs(v, u);
            deg[u]++;
        }else if (vis[v] == 0) {
            deg[v]++;
        }
    }
    vis[u] = 1;
}

vector<bool> vs;

map<pair<int, int>, bool> mp;

void dfs1(int u, int p) {
    if (vs[u]) {
        return;
    }
    vs[u] = true;
    for (int v: g[u]) {
        if (v == p) {
            continue;
        }
        dfs1(v, u);
        if (deg[v]%2) {
            if (mp.find({u, v}) == mp.end() || mp[{u, v}] == false) {
                mp[{u, v}] = true;
                mp[{v, u}] = true;
                if (dfs_num[u] < dfs_num[v]) {
                    deg[v]++, deg[u]--;
                }else {
                    deg[v]--, deg[u]++;
                }
            }else {
                mp[{u, v}] = false;
                mp[{v, u}] = false;
                if (dfs_num[u] > dfs_num[v]) {
                    deg[v]++, deg[u]--;
                }else {
                    deg[v]--, deg[u]++;
                }
            }
        }
    }
}


int main() {
    speedup;
    cin >> n >> m;
    g.resize(n);
    deg.assign(n, 0);
    dfs_num.assign(n, 0);
    vis.assign(n, -1);
    vs.assign(n, false);
    int u, v;
    vector<pii> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u;
        --v;
        edges[i] = {u, v};
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (!vs[i]) {
            dfs(i, -1);
            dfs1(i, -1);
            if (deg[i]%2) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        tie(u, v) = edges[i];
        if (dfs_num[u] > dfs_num[v]) {
            swap(u, v);
        }
        if (mp.find({u, v}) != mp.end() && mp[{u, v}] == true){
            cout << v+1 << ' ' << u+1 << '\n';
        }else {
            cout << u+1 << ' ' << v+1 << '\n';
        }
    }
    return 0;
}
