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
    int n, m, k; cin >> n >> m >> k;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int w, at; cin >> w >> at;
        a[i] = {w, min(at, m)};
    }
    sort(a.begin(), a.end(), greater<pii>());
    deque<pair<int, ll>> q;
    q.push_back({INT_MAX, m});
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll cur = a[i].s;
        while (cur > 0) {
            if (q.front().f >= a[i].f+k) {
                if (q.front().s > cur) {
                    q.front().s -= cur; cur = 0;
                }else {
                    ll c = q.front().s;
                    q.pop_front();
                    cur -= c;
                }
            }else {
                break;
            }
        }
        ans += a[i].s-cur;
        q.push_back({a[i].f, a[i].s-cur});
    }
    cout << ans << endl;
    return 0;
}
