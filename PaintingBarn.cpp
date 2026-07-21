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

const int MAXN = 1005;

int a[MAXN][MAXN];

int main() {
    usopen("paintbarn")
    speedup
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            a[i][j] = 0;
        }
    }
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int lx, ly, mx, my; cin >> lx >> ly >> mx >> my; lx++, ly++, mx++, my++;
        a[lx][ly]++, a[lx][my]--, a[mx][ly]--, a[mx][my]++;
    }
    int ans = 0;
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < MAXN; j++) {
            a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            ans += (a[i][j] == k);
        }
    }
    cout << ans << endl;
    return 0;
}
