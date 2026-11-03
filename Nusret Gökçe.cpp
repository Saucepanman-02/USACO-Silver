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
    int n, m; cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; i++) {
        if (a[i]-m > a[i+1]) {
            a[i+1] = a[i]-m;
        }
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < n-1; i++) {
        if (a[i]-m > a[i+1]) {
            a[i+1] = a[i]-m;
        }
    }
    reverse(a.begin(), a.end());
    for (int U: a) {
        cout << U << ' ';
    }
    cout << endl;
    return 0;

}
