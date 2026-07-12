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

set<int> s;
vi a; vll v;
ll ans = 0;
vi dfs_num;
vi l;

void dfs(int u) {
    dfs_num[u] = 0;
    if (dfs_num[a[u]] == -1) {
        dfs(a[u]);
    }else if (dfs_num[a[u]] == 0) {
        dfs_num[a[u]] = 5;
    }
    if (dfs_num[u] == 0)
        dfs_num[u] = 1;
}

int main() {
    int n; cin >> n;
    a.resize(n), v.resize(n);
    dfs_num.assign(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> v[i];
        a[i]--;
        ans += v[i];
    }
    for (int i = 0; i < n; i++) {
        if (dfs_num[i] == -1) {
            dfs(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (dfs_num[i] == 5) {
            ll mn = v[i];
            int c = a[i];
            while (c != i) {
                mn = min(mn, v[c]);
                c = a[c];
            }
            ans -= mn;
        }
    }
    cout << ans << endl;
    return 0;
}
