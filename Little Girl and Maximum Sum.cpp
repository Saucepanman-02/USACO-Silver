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

const int MAXN = 2*1e5+10;

int main() {
    speedup
    int n, q; cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vll p(n);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--, r--;
        p[l]++; if (r != n-1) {
            p[r+1]--;
        }
    }
    for (int i = 1; i < n; i++) {
        p[i] += p[i-1];
    }
    sort(a.begin(), a.end());
    sort(p.begin(), p.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i]*p[i];
    }
    cout << ans << '\n';
    return 0;
}
