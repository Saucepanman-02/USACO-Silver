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


int main() {
    speedup
    int a, b, c; cin >> a >> b >> c;
    int m; cin >> m;
    multiset<ll> usb, ps;
    multiset<ll> net;
    for (int i = 0; i < m; i++) {
        int ct; cin >> ct;
        string st; cin >> st;
        if (st == "USB") {
            usb.insert(ct);
        }else {
            ps.insert(ct);
        }
    }
    ll ans = 0, cnt = 0;
    int sz = usb.size();
    for (int i = 0; i < min(a, sz); i++) {
        auto it = usb.begin();
        ans += *it; cnt++; usb.erase(it);
    }
    sz = ps.size();
    for (int i = 0; i < min(b, sz); i++) {
        auto it =  ps.begin();
        ans += *it; cnt++; ps.erase(it);
    }
    for (ll r: usb) {
        net.insert(r);
    }
    for (ll r: ps) {
        net.insert(r);
    }
    sz = net.size();
    for (int i = 0; i < min(c, sz); i++) {
        auto it = net.begin();
        ans += *it; cnt++;
        net.erase(it);
    }
    cout << cnt << ' ' << ans << endl;
    return 0;
}
