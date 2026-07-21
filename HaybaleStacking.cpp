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
#define pll pair<ll, ll>


int main() {
    speedup
    int n, k; cin >> n >> k;
    vi a(n);
    for (int i = 0; i < k; i++) {
        int l, r; cin >> l >> r; l--, r--;
        a[l]++;
        if (r != n-1) {
            a[r+1]--;
        }
    }
    for (int i = 1; i < n;i++) {
        a[i] += a[i-1];
    }
    sort(a.begin(), a.end());
    cout << a[(n-1)/2] << endl;
    return 0;
}
