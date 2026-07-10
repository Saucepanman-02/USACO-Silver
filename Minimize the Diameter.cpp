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

vector<vi> g;
vi mdist;
vi smdist;
vi src;

void dfs1(int u, int p) {
    for (int v: g[u]) {
        if (v == p) {
            continue;
        }
        dfs1(v, u);
        if (mdist[u] < mdist[v]+1) {
            smdist[u]  = mdist[u];
            mdist[u] = mdist[v]+1;
            src[u] = v;
        }else if (smdist[u] < mdist[v]+1) {
            smdist[u] = mdist[v]+1;
        }
    }
}

void dfs2(int u, int p) {
    if (p != -1) {
        if (u == src[p]) {
            if (mdist[u] < smdist[p]+1) {
                smdist[u] = mdist[u];
                mdist[u] = smdist[p]+1;
                src[u] = p;
            }else if (smdist[u] < smdist[p]+1) {
                smdist[u] = smdist[p]+1;
            }
        }else {
            if (mdist[u] < mdist[p]+1) {
                smdist[u] = mdist[u];
                mdist[u] = mdist[p]+1;
                src[u] = p;
            }else if (smdist[u] < mdist[p]+1) {
                smdist[u] = mdist[p]+1;
            }
        }
    }
    for (int v: g[u]) {
        if (v == p)
            continue;
        dfs2(v, u);
    }
}

int main() {
    int n; cin >> n;
    g.assign(n, vi());
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    mdist.assign(n, 0), smdist.assign(n, 0), src.assign(n, 0);
    dfs1(0, -1);
    dfs2(0, -1);
    int ans1 = 0;
    int min1 = 1e9;
    for (int i = 0; i < n; i++) {
        ans1 = max(ans1, mdist[i]+smdist[i]);
        min1 = min(min1, mdist[i]);
    }
    cin >> n;
    g.assign(n, vi());
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    mdist.assign(n, 0), smdist.assign(n, 0), src.assign(n, 0);
    dfs1(0, -1);
    dfs2(0, -1);
    int ans2 = 0;
    int min2 = 1e9;
    for (int i = 0; i < n; i++) {
        ans2 = max(ans2, mdist[i]+smdist[i]);
        min2 = min(min2, mdist[i]);
    }
    cout << max(max(ans1, ans2), min1+min2+1) << endl;
    return 0;
}
