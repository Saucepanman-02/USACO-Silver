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
vll cnt, sum;
int n;

void dfs1(int u, int p) {
    cnt[u] = 1;
    for (int v: g[u]) {
        if (v == p)
            continue;
        dfs1(v, u);
        cnt[u] += cnt[v];
        sum[u] += sum[v] + cnt[v];
    }
}

void dfs2(int u, int p) {
    if (p != -1) {
        sum[u] += (n-cnt[u])+(sum[p]-(cnt[u]+sum[u]));
    }
    for (int v: g[u]) {
        if (v == p)
            continue;
        dfs2(v, u);
    }
}

int main() {
    speedup
    cin >> n;
    g.resize(n);
    cnt.resize(n);
    sum.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    for (ll v: sum) {
        cout << v << '\n';
    }
    return 0;
}
