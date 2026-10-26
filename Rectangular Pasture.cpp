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


bool cmp1(pii &a, pii &b) {
    return a.f < b.f;
}

bool cmp2(pii &a, pii &b) {
    return a.s < b.s;
}
int main() {
    
    speedup
    int n; cin >> n;
    vector<pii> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i].f >> g[i].s;
    }
    sort(g.begin(), g.end(), cmp2);
    for (int i = 0; i < n; i++) {
        g[i].s = i+1;
    }
    sort(g.begin(), g.end(), cmp1);
    for (int i = 0; i < n; i++) {
        g[i].f = i+1;
    }
    vector<vector<int>> pref(n+1, vi(n+1));
    for (int i = 0; i < n; i++) {
        pref[g[i].f][g[i].s]++;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i) {
                pref[i][j] += pref[i-1][j];
            }
            if (j) {
                pref[i][j] += pref[i][j-1];
            }
            if (i && j) {
                pref[i][j] -= pref[i-1][j-1];
            }
        }
    }
    ll ans = n+1;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            //int x1 = min(g[i].f, g[j].f);
            int y1 = min(g[i].s, g[j].s);
            //int x2 = max(g[i].f, g[j].f);
            int y2 = max(g[i].s, g[j].s);
            ll tp = pref[j+1][n]-pref[j+1][y2]-pref[i+1][n]+pref[i+1][y2];
            ll dp = pref[j+1][y1-1]-pref[i+1][y1-1];
            ans += (tp+1)*(dp+1);
            //cout << i << ' ' << j << ' ' << (tp+1)*(dp+1) << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
