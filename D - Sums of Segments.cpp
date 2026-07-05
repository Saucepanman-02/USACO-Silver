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

vll precomp;

pll search(ll x, int n) {
    ll l = 0, r = n, ans;
    while (r >= l) {
        ll md = ((r+l) >> 1);
        if (x > precomp[md]) {
            ans = md;
            l = md+1;
        }else {
            r = md-1;
        }
    }
    return {ans+1, (ans)+ x-precomp[ans]};
}

int main(){
    speedup
    int n; cin >> n;
    precomp.resize(n+1);
    for (int i = 1; i <= n; i++) {
        precomp[i] = precomp[i-1]+(n-i+1);
    }
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vll pref(n+1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1]+a[i-1];
    }
    vll prefp(n+1);
    for (int i = 1; i <= n; i++) {
        prefp[i] = prefp[i-1]+pref[i];
    }
    vll prefpp(n+1);
    prefpp[n] = a[n-1];
    for (int x = n-1; x >= 1; x--) {
        prefpp[x] = prefpp[x+1]+prefp[n]-prefp[x-1]-pref[x-1]*(n-x+1);
    }
    int q; cin >> q;
    while (q--) {
        ll l, r; cin >> l >> r;
        pll p1 = search(l, n), p2 = search(r, n);
        if (p1.f == p2.f) {
            ll l1 = p1.s, r1 = p2.s;
            ll x = p1.f;
            cout << prefp[r1]-prefp[x-1]-pref[x-1]*(r1-x+1)-(prefp[l1-1]-prefp[x-1]-pref[x-1]*(l1-1-x+1)) << '\n';
        }else {
            ll ans = 0;
            ll l1 = p1.s, x = p1.f;
            ans += prefp[n]-prefp[x-1]-pref[x-1]*(n-x+1)-(prefp[l1-1]-prefp[x-1]-pref[x-1]*(l1-1-x+1));
            /*x++;
            while (x < p2.f) {
                ans += prefp[n]-prefp[x-1]-pref[x-1]*(n-x+1);
                x++;
            }*/
            ans += prefpp[x+1] - prefpp[p2.f];
            x = p2.f;
            ll r1 = p2.s;
            ans += prefp[r1]-prefp[x-1]-pref[x-1]*(r1-x+1);
            cout << ans << '\n';
        }
    }
    return 0;
}
