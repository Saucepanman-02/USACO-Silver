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
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<pii> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].f;
            a[i].s = i;
        }
        sort(a.begin(), a.end());

        ll cur = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if (cur+a[i].f > m) {
                break;
            }
            cur += a[i].f; k++;
        }
        int r1 = 1;
        for (int i = 0; i < n; i++) {
            if (a[i].s+(i>=k) > k) {
                r1++;
            }
        }
        bool flag = false;
        for (int i = 0; i < k; i++) {
            flag = flag || (a[i].s == k);
        }
        int r2 = n+1;
        if (!flag) {
            int c = 0;
            for (int i = 0; i < n; i++) {
                if (a[i].s == k) {
                    c = i;
                }
            }
            int mx = m-a[c].f;
            if (mx >= 0) {
                cur = 0;
                int ck = 1;
                for (int i = 0; i < n; i++) {
                    if (a[i].f + cur > mx ) {
                        break;
                    }
                    cur += a[i].f; ck++;
                }
                r2 = 1;
                for (int i = 0; i < n; i++) {
                    if (a[i].s + (i < ck-1 && a[i].s != k) > ck) {
                        r2++;
                    }
                }
            }
        }
        cout << min(r1, r2) << '\n';
    }
    return 0;
}
