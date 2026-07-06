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
    string st; cin >> st;
    int n = st.size();
    vector<vi> dp(n, vi(n, 0)), pal(n, vi(n, 0));
    for (int i = n-1; i >= 0; i--) {
        dp[i][i] = pal[i][i] = 1;
        for (int j = i+1; j < n; j++) {
            pal[i][j] = (st[i] == st[j])&&(i+1 <= j-1 ? pal[i+1][j-1]: 1);
            dp[i][j] = pal[i][j]+dp[i+1][j]+dp[i][j-1]-(i+1 <= j-1? dp[i+1][j-1]: 0);
        }
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--, r--;
        cout << dp[l][r] << '\n';
    }
    return 0;
}
