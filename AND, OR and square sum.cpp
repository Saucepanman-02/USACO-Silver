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
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vll ft(n);
    for (int b = 0; b < 20; b++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += ((a[i]&(1<<b)) == (1<<b));
        }
        int idx = n-1;
        while (cnt-- > 0) {
            ft[idx--] |= (1<<b);
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
       sum += ft[i]*ft[i];
    }
    cout << sum << '\n';
    return 0;
}
