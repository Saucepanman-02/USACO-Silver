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

struct E{
    int x, y, idx;
};

bool cmp(E &a, E &b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main() {
    speedup
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<E> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
            int mn = min(a[i].x, a[i].y);
            int mx = max(a[i].x, a[i].y);
            a[i].x = mn;
            a[i].y = mx;
            a[i].idx = i;
        }
        sort(a.begin(), a.end(), cmp);
        int mn = INT_MAX;
        int idx = -1;
        vi ans(n);
        vi pref_min(n);
        vi pref_min_idx(n);
        for (int i = 0; i < n; i++) {
            if (a[i].y > mn) {
                ans[a[i].idx] = idx;
            }else {
                ans[a[i].idx] = -1;
                mn = a[i].y;
                idx = a[i].idx+1;
            }
            pref_min[i] = a[i].y;
            pref_min_idx[i] = a[i].idx+1;
            if (i) {
                if (pref_min[i] > pref_min[i-1]) {
                    pref_min[i] = pref_min[i-1];
                    pref_min_idx[i] = pref_min_idx[i-1];
                }
            }
        }
        vi fans(n);
        for (int i = 0; i < n;) {
            int r = i;
            while (r+1 < n && a[r+1].x == a[i].x) {
                r++;
            }
            mn = INT_MAX, idx = -1;
            if (i) {
                mn = pref_min[i-1];
                idx = pref_min_idx[i-1];
            }
            for (int j = i; j <= r; j++) {
                if (a[j].y > mn) {
                    fans[a[j].idx] = idx;
                }else {
                    fans[a[j].idx] = -1;
                }
            }
            i = r+1;
        }
        for (int u: fans)
            cout << u << ' ';
        cout << '\n';
    }
    return 0;
}
