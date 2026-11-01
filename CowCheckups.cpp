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


const int MOD = 1e9+9;


int main() {
    int n; cin >> n;
    vi a(n), b(n);
    vector<vi> g1(n), g2(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        g1[a[i]].push_back(min(i+1, n-i));
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i]; b[i]--;
        g2[b[i]].push_back(min(i+1, n-i));
    }
    for (int i = 0; i < n; i++) {
        sort(g1[i].begin(), g1[i].end());
        sort(g2[i].begin(), g2[i].end());
    }
    vector<vll> pref(n);
    ll fans = 0;
    for (int i = 0; i < n; i++) {
        int sz = g1[i].size();
        pref[i].resize(sz+1);
        for (int j = 1; j <= sz; j++) {
            pref[i][j] = pref[i][j-1]+g1[i][j-1];
        }
        for (ll u: g2[i]) {
            int l = 0, r = sz-1, ans = -1;
            while (r >= l) {
                int m = (r+l)/2;
                if (g1[i][m] <= u) {
                    ans = m;
                    l = m+1;
                }else {
                    r = m-1;
                }
            }
            fans += pref[i][ans+1]+(sz-1-ans)*u;
        }
        if (a[i] == b[i]) {
            ll c = i;
            fans += (c*(c+1))/2;
            c = n-1-i;
            fans += (c*(c+1))/2;
        }
    }
    printf("%lld\n", fans);
    return 0;

}
