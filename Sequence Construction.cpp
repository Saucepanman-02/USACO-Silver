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
        int m, k; cin >> m >> k;
        vll a;
        ll sum = 0;
        for (int b = 0; b < 5; b++) {
            if (k&(1<<b)) {
                a.push_back((1<<(1<<b))-1);
                sum += (1<<(1<<b))-1;
            }
        }
        if (m-sum == 1) {
            if (a[0] == 1) {
                a[0]=2;
                int n = a.size();
                cout << n << '\n';
                for (ll r: a)
                    cout << r << ' ';
                cout << '\n';
            }else {
                cout << -1 << '\n';
            }
            continue;
        }
        if (m < sum) {
            cout << -1 << '\n';
            continue;
        }
        if (m-sum >= 2){
            ll c = m-sum;
            if (c%2 == 0) {
                a.push_back(c/2);
                a.push_back(c/2);
            }else {
                a.push_back(1);
                a.push_back(2);
                if (c > 3) {
                    a.push_back((c-3)/2);
                    a.push_back((c-3)/2);
                }
            }
        }
        int n = a.size();
        cout << n << '\n';
        for (ll r: a)
            cout << r << ' ';
        cout << '\n';
    }
    return 0;
}
