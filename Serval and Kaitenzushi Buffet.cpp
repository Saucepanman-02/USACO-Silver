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

const int MOD = 1e9+7;


void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int prey = 0;
    priority_queue<int, vector<int>, greater<int>> pred;
    for (int i = n-1; i >= 0; i--) {
        if (prey >= k) {
            prey -= k;
            pred.push(a[i]);
        }else if (!pred.empty() && pred.top() < a[i]) {
            pred.pop();
            pred.push(a[i]); prey++;
        }else if (prey < k) {
            prey++;
        }
    }
    ll ans = 0;
    while (!pred.empty()) {
        ans += pred.top();
        pred.pop();
    }
    cout << ans << endl;
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
