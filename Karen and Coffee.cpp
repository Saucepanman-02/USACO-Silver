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

const int MAXN = 2*1e5+10;
int a[MAXN];

int main() {
    speedup
    int n, k, q; cin >> n >> k >> q;
    for (int i = 0; i < MAXN; i++) {
        a[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        a[l]++; a[r+1]--;
    }
    for (int i = 1; i < MAXN; i++) {
        a[i] += a[i-1];
    }
    for (int i = 1; i < MAXN; i++) {
        if (a[i] >= k) {
            a[i] = 1;
        }else {
            a[i] = 0;
        }
        a[i] += a[i-1];
    }
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        cout << a[r] - a[l-1] << '\n';
    }
    return 0;
}
