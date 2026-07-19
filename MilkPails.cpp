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

vector<vector<int>> vis;
int x, y, k, m;
int ans = INT_MAX;

void ff(int cx, int cy, int st) {
    if (vis[cx][cy] <= st) {
        return;
    }
    if (st > k) {
        return;
    }
    vis[cx][cy] = st;
    ans = min(ans, abs(cx+cy-m));
    ff(x, cy, st+1);
    ff(cx, y, st+1);
    ff(0, cy, st+1);
    ff(cx, 0, st+1);
    if (cx+cy <= x) {
        ff(cx+cy, 0, st+1);
    }else {
        ff(x, cx+cy-x, st+1);
    }
    if (cx+cy <= y) {
        ff(0, cx+cy, st+1);
    }else {
        ff(cx+cy-y, y, st+1);
    }
}


int main() {
    speedup
    usopen("pails")
    cin >> x >> y >> k >> m;
    vis.resize(x+1, vector<int>(y+1, 1e9));
    ff(0, 0, 0);
    cout << ans << endl;
    return 0;
}
