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

const int MOD = 998244353;

int main() {
    int n; cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll fans = 0;
    for (int b = 0; b < 31; b++) {
        ll ev = 1, od = 0;
        ll evs = 0, ods = 0;
        int c  =0;
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            c += (((1LL<<b)&a[i]) == (1LL<<b));
            c %= 2;
            if (c) {
                ans += (ev*(i+1)-evs)%MOD*(1LL<<b)%MOD;
            }else {
                ans += (od*(i+1)-ods)%MOD*(1LL<<b)%MOD;
            }
            ans %= MOD;
            if (c) {
                od++;
                ods += (i+1);
                ods %= MOD;
            }else {
                ev++;
                evs += (i+1);
                evs %= MOD;
            }
        }
        //cout << ans << '\n';
        fans += ans;
        fans %= MOD;
    }
    cout << fans << '\n';
    return 0;
}
