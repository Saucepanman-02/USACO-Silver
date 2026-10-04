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
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string st; cin >> st;
        vi l(k, 1), r(k);
        vi chk(n, 0);
        for (int i = 0; i < k; i++) {
            chk[i] = 1;
        }
        for (int i = 0; i < n-k; i++) {
            if (st[i] == st[i+1]) {
                if (chk[i]) {
                    chk[i+k] = 1;
                    l[i%k]++;
                }else {
                    chk[i+k] = 0;
                    r[i%k]++;
                }
            }else {
                if (chk[i]) {
                    chk[i+k] = 0;
                    r[i%k]++;
                }else {
                    chk[i+k] = 1;
                    l[i%k]++;
                }
            }
        }
        vi c(k);
        ll cur = 0;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if (l[i] > r[i]) {
                c[i] = 1; cnt++;
            }else {
                c[i] = 0;
            }
            cur += max(l[i], r[i]);
        }
        if (cnt%2 == st[0]-'0') {

        }else {
            ll fans = 0;
            for (int i = 0; i < k; i++) {
                if (l[i] > r[i]) {
                    fans = max(fans, cur-l[i]+r[i]);
                }else {
                    fans = max(fans, cur-r[i]+l[i]);
                }
            }
            cur = fans;
        }
        ll mx = cur;
        cur = 0;
        cnt = 0;
        for (int i = 0; i < k; i++) {
            if (l[i] < r[i]) {
                c[i] = 1; cnt++;
            }else {
                c[i] = 0;
            }
            cur += min(l[i], r[i]);
        }
        if (cnt%2 != st[0]-'0') {
            ll fans = 1e7;
            for (int i = 0; i < k; i++) {
                if (l[i] < r[i]) {
                    fans = min(fans, cur-l[i]+r[i]);
                }else {
                    fans = min(fans, cur-r[i]+l[i]);
                }
            }
            cur = fans;
        }
        cout << cur << ' ' << mx << '\n';
    }
    return 0;
}
