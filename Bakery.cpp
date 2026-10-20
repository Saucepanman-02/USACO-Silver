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
//#define max(a, b) (a >= b? a: b)
//#define min(a, b) (a <= b? a: b)

int n;

ll tc, tr;
vll a, b, c;

bool solve(ll k) {
    db lo = max(0LL, k-tr+1), hi = min(k, tc-1);
    for (int i = 0; i < n; i++) {
        db den = b[i]-a[i];
        db num = c[i] - a[i]*tc - b[i]*tr + b[i]*k;
        if (num <= 0 && den < 0) {
            lo = max(lo, num/den);
        }else if (num < 0 && den >= 0) {
            return false;
        }else if (num >= 0 && den == 0) {
            continue;
        }else if (num >= 0 && den > 0) {
            hi = min(hi, num/den);
        }
    }
    if (hi >= lo) {
        ll cx = lo;
        if (abs(lo-cx) > 1e-9) {
            cx++;
        }
        return cx <= hi;
    }
    return false;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> tc >> tr;
        a.resize(n);
        b.resize(n);
        c.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        ll l = 0, r = tr+tc-2, ans = r;
        while (r >= l) {
            ll m = (r+l)/2;
            if (solve(m)) {
                r = m-1;
                ans = m;
            }else {
                l = m+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
