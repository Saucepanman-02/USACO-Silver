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

int main() {
    usopen("herding")
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mx = 0;
    for (int i = 0; i < n-1; i++) {
        mx += (a[i+1]-a[i]-1);
    }
    mx -= min(a[1]-a[0]-1, a[n-1]-a[n-2]-1);
    int mn = 1e9+10;
    int r = n-1;
    for (int l = n-2; l >= 0; l--) {
        while (r >= 0 && a[r]-a[l] >= n) {
            r--;
        }
        int cur = n-(r-l+1);
        if (r-l+1 == n-1 && a[r]-a[l]+1 == n-1) {
            cur += n-1;
        }
        mn = min(cur, mn);
    }
    cout << mn << '\n' << mx << '\n';
    return 0;
}
