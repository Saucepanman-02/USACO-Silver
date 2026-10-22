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

int n, k;
vll a;


bool solve(ll m) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (a[i]/m);
    }
    return (cnt >= k/2);
}


ll calc(ll m) {
    vi b(n); ll cnt = 0;
    for (int i = 0; i < n; i++) {
        b[i] = a[i]%m;
        cnt += a[i]/m;
    }
    cnt = min(cnt, (ll)k);
    sort(b.begin(), b.end());
    ll ans = (cnt-k/2)*m;
    for (int i = 0; i < min(k-cnt, (ll)n); i++) {
        ans += b[n-1-i];
    }
    return ans;
}

int main() {
    usopen("berries")
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int l = 1, r = 1000, ans;
    while (r >= l) {
        int md = (r+l)/2;
        if (solve(md)) {
            l = md+1;
            ans = md;
        }else {
            r = md-1;
        }
    }
    ll fans = 0;
    for (int i = 1; i <= ans; i++) {
        fans = max(fans, calc(i));
    }
    cout << fans << endl;
    return 0;
}
