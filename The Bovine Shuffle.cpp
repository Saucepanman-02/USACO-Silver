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
#define usopen(file) do {                                      \
freopen((std::string(file) + ".in").c_str(), "r", stdin);  \
freopen((std::string(file) + ".out").c_str(), "w", stdout);\
} while (0);

vll a;

int main() {
    usopen("shuffle")
    int n; cin >> n;
    a.resize(n);
    vll deg(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--; deg[a[i]]++;
    }
    ll ans = n;
    queue<ll> q;
    for (int i = 0; i < n; i++) {
        if (!deg[i]) {
            q.push(i);
            while (!q.empty()) {
                ll u = q.front(); q.pop();
                ans--;
                deg[u] = 1;
                deg[a[u]]--;
                if (!deg[a[u]]) {
                    q.push(a[u]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
