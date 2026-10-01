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
#define l(p) (p << 1)
#define r(p) ((p<<1)+1)

#define max(a, b) (a >= b? a: b)
#define min(a, b) (a <= b? a: b)

vi a;
int n;
vll ps, px;
int idx;

bool solve(int ln) {
    ll tgt = ps[n]-px[n];
    for (int i = 0; i <= n-ln; i++) {
        int j = i+ln-1;
        if ((ps[j+1]-ps[i]-(px[j+1]^px[i])) == tgt) {
            idx = i;
            return true;
        }
    }
    return false;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int q; cin >> n >> q;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ps.resize(n+1), px.resize(n+1);
        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i-1]+a[i-1];
        }
        for (int i = 1; i <= n; i++) {
            px[i] = px[i-1]^a[i-1];
        }
        int duf; cin >> duf >> duf;
        idx = 1;
        int ci = 1;
        int l = 1, r = n, ans = n;
        while (r >= l) {
            int md = (r+l)/2;
            if (solve(md)) {
                ci = idx+1;
                ans = md;
                r = md-1;
            }else {
                l = md+1;
            }
        }
        cout << ci << ' ' << ci+ans-1 << '\n';
    }
    return 0;
}
