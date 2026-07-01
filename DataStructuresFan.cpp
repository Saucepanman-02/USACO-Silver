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
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string st; cin >> st;
        vi pref(n+1);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i-1]^a[i-1];
        }
        int x0 = 0, x1 = 0, duf = 0;
        for (int i = 0; i < n; i++) {
            if (st[i] == '0') {
                x0 ^= a[i];
            }else {
                x1 ^= a[i];
            }
        }
        int q; cin >> q;
        for (int i = 0; i < q; i++) {
            int c; cin >> c;
            if (c == 1) {
                int l, r; cin >> l >> r;
                duf ^= (pref[r]^pref[l-1]);
            }else {
                int x; cin >> x;
                if (x == 0) {
                    cout << (x0^duf) << ' ';
                }else {
                    cout << (x1^duf) << ' ';
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
