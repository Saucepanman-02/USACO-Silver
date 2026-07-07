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
vi str;
vi fmdist;

void dfs(int u, int p) {
    int mx1 = 0, mx2 = 0;
    int x = -1;
    for (int v: g[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        if (mdist[v]+1 > mx1) {
            mx2 = mx1;
            mx1 = mdist[v]+1;
            x = v;
        }else if (mdist[v]+1 > mx2) {
            mx2 = mdist[v]+1;
        }else if (smdist[v]+1 > mx1) {
            mx2 = mx1;
            mx1 = smdist[v]+1;
        }else if (smdist[v]+1 > mx2) {
            mx2 = smdist[v]+1;
        }
    }
    mdist[u] = mx1;
    smdist[u] = mx2;
    str[u] = x;
}


void dfs1(int u, int p) {

    if (p != -1) {
        if (mdist[u] < mdist[p]+1 && u != str[p]) {
            smdist[u] = mdist[u];
            mdist[u] = mdist[p]+1;
            str[u] = p;
        }
        if (mdist[u] < smdist[p]+1) {
            smdist[u] = mdist[u];
            mdist[u] = smdist[p]+1;
        }
    }
    fmdist[u] = mdist[u]+smdist[u];
    for (int v: g[u]) {
        if (v == p)
            continue;
        if (mdist[v] < mdist[u]+1) {
            if (v == str[u]) {
                if (mdist[v] < smdist[u]+1) {
                    smdist[v] = mdist[v];
                    mdist[v] = smdist[u]+1;
                    str[v] = u;
                }else if (smdist[v] < smdist[u]+1) {
                    smdist[v] = smdist[u]+1;
                }
            }else {
                if (mdist[v] < mdist[u]+1) {
                    smdist[v] = mdist[v];
                    mdist[v] = mdist[u]+1;
                    str[v] = u;
                }else if (smdist[v] < mdist[u]+1) {
                    smdist[v] = mdist[u]+1;
                }
            }
        }
        dfs1(v, u);
    }

}

int main() {
    speedup
    int n; cin >> n; g.resize(n);
    mdist.resize(n);
    smdist.resize(n);
    str.resize(n);
    fmdist.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    dfs1(0, -1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, fmdist[i]);
        //cout << fmdist[i] << endl;
    }
    cout << ans << endl;
    return 0;
}
