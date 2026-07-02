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


int main(){
    speedup
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vll b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vll lp(n), rp(n);
        for (int i = 0; i < n; i++) {
            lp[i] = b[i]+(i+1);
            if (i) {
                lp[i] = max(lp[i], lp[i-1]);
            }
        }
        rp[n-1] = b[n-1] - (n);
        for (int i = n-2; i >= 0; i--) {
            rp[i] = b[i] - (i+1);
            rp[i] = max(rp[i], rp[i+1]);
        }
        ll ans = 0;
        for (int i = 1; i <= n-2; i++) {
            ans = max(ans, lp[i-1]+b[i]+rp[i+1]);
        }
        cout << ans << '\n';
    }
    return 0;
}
