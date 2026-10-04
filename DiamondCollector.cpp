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
#define ceil(n, r) (ll)((n+r-1)/r)
#define floor(n, r) (ll)(n/r)
#define pil pair<int, ll>
#define max(a, b) (a >= b? a: b)
#define min(a, b) (a <= b? a: b)

const int MOD = 998244353;


vi grind(int n, int k, vi & a) {
    int l = 0;
    vi b(n);
    for (int r = 0; r < n; r++) {
        while (l <= r && abs(a[r]-a[l]) > k) {
            l++;
        }
        if (l <= r) {
            b[r] = r-l+1;
            if (r)
                b[r] = max(b[r], b[r-1]);
        }
    }
    return b;
}

int main() {
    usopen("diamond")
    int n, k; cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vi pref = grind(n, k, a);
    reverse(a.begin(), a.end());
    vi suf = grind(n, k, a);
    reverse(suf.begin(), suf.end());
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        ans = max(ans, pref[i]+suf[i+1]);
    }
    cout << ans << endl;
    return 0;
}
