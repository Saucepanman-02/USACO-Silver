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

vector<vi> a, b;
int dX[] = {0, 0, 1, -1};
int dY[] = {1, -1, 0, 0};
vector<vector<bool>> vis;
int m, n;
int d;
int cur;

void ff(int x, int y) {
    if (vis[x][y]) {
        return;
    }
    cur += b[x][y];
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int cx = x+dX[i], cy = y+dY[i];
        if (cx < 0 || cx >= m || cy < 0 || cy >= n) {
            continue;
        }
        if (abs(a[cx][cy]-a[x][y]) <= d) {
            ff(cx, cy);
        }
    }
}

int main() {
    speedup
    usopen("ccski")
    cin >> m >> n;
    a.resize(m, vi(n));
    b.resize(m, vi(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    int cx, cy;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
            cnt += b[i][j];
            if (b[i][j]) {
                cx = i, cy = j;
            }
        }
    }
    int l = 0, r = 1e9, ans = 1e9;
    while (r >= l) {
        int md = (r+l)/2;
        d = md; cur = 0;
        vis.assign(m, vector<bool>(n, false));
        ff(cx, cy);
        if (cur == cnt) {
            ans = md; r = md-1;
        }else {
            l = md+1;
        }
    }
    cout << ans << endl;
    return 0;
}
