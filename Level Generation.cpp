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


ll n;

bool solve(ll k) {
    return (k*(k+1) <= 2*n);
}

int main() {
    int t; cin >> t;
    while (t--){
        cin >> n;
        ll l = 1, r = n, ans;
        while (r >= l) {
            ll md = (r+l)/2;
            if (solve(md)) {
                l = md+1;
                ans = md;
            }else {
                r = md-1;
            }
        }
        ll k = ans;
        ll extra = n-k-3-k*(k-1)/2;
        ll cur = n-k+k*(k-1)/2;
        cout << (extra >= 0? extra+1: 0)+cur << '\n';
    }
    return 0;
}
