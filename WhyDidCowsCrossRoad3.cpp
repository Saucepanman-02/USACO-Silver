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


vector<vi> g;
vector<vector<bool>> vis;
map<pair<pii, pii>, int> mp;
int n, k, r;
int cnt;

int dX[] = {0, 0, -1, 1};
int dY[] = {1, -1, 0, 0};

void ff(int x, int y) {
    if (vis[x][y]) {
        return;
    }
    vis[x][y] = true;
    cnt += g[x][y];
    for (int i = 0; i < 4; i++) {
        int cx = x+dX[i], cy = y+dY[i];
        if (cx < 0 || cx >= n || cy < 0 || cy >= n) {
            continue;
        }
        if (mp.find({{x, y}, {cx, cy}}) == mp.end()) {
            ff(cx, cy);
        }
    }
}

int main() {
    speedup
    usopen("countcross")
    cin >> n >> k >> r;
    g.assign(n, vi(n, 0));
    vis.resize(n, vector<bool>(n, false));
    for (int i = 0; i < r; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        mp[{{x1, y1}, {x2, y2}}] = true;
        mp[{{x2, y2}, {x1, y1}}] = true;
    }
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y; x--, y--;
        g[x][y] += 1;
    }
    vll a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                cnt = 0;
                ff(i, j);
                a.push_back(cnt);
            }
        }
    }
    ll s1 = 0, s2 = 0;
    for (ll c: a) {
        s1 += c; s2 += c*c;
    }
    cout << (s1*s1-s2)/2 << '\n';
    return 0;
}
