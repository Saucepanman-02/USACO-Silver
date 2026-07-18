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
vi c;
 
void dfs(int u, int p) {
    for (int v: g[u]) {
        if (v == p)
            continue;
        c[v] = 1-c[u];
        dfs(v, u);
    }
}
 
int main() {
    int n; cin >> n;
    g.resize(n);
    c.assign(n, -1);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    c[0] = 0;
    dfs(0, -1);
    ll a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] == 0) {
            a++;
        }else {
            b++;
        }
    }
    cout << a*b-(n-1) << endl;
    return 0;
}
