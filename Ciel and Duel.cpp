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


int main() {
    int n, m; cin >> n >> m;
    vector<pii> a;
    vi c(m);
    for (int i = 0; i < n; i++) {
        string st; cin >> st; int cr; cin >> cr;
        if (st == "ATK") {
            a.push_back({cr, 0});
        }else {
            a.push_back({cr, 1});
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    vector<pair<int, pii>> edges;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i] >= a[j].f && a[j].s == 0) {
                edges.push_back({c[i]-a[j].f, {i, j}});
            }
        }
    }
    vi fa(n), fc(m);
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    ll ans = 0;
    for (auto [w, p]: edges) {
        if (!fa[p.s] && !fc[p.f]) {
            fa[p.s] = fc[p.f] = 1;
            ans += w;
        }
    }
    ll ans1 = 0;
    bool flag = true;
    multiset<int> st;
    for (int i = 0; i < m; i++) {
        st.insert(c[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i].s == 1) {
            auto it = st.upper_bound(a[i].f);
            if (it != st.end()) {
                st.erase(it);
            }else {
                flag = false;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i].s == 0) {
            auto it = st.lower_bound(a[i].f);
            if (it != st.end()) {
                ans1 += *it-a[i].f;
                st.erase(it);
            }else {
                flag = false;
            }
        }
    }
    if (flag) {
        for (int r: st) {
            ans1 += r;
        }

        cout << max(ans, ans1) << '\n';
    }else {
        cout << ans << endl;
    }
    return 0;
}
