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

vector<vector<bool>> vis, light;
vector<vector<vector<pii>>> at;
int n;
int dX[] = {0, 0, 1, -1};
int dY[] = {1, -1, 0, 0};
int cnt = 0;

void ff(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return;
    }
    if (vis[x][y]) {
        return;
    }
    vis[x][y] = true;
    for (pii g: at[x][y]) {
        light[g.f][g.s] = true;
        for (int i = 0; i < 4; i++) {
            int cx = g.f+dX[i], cy = g.s+dY[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= n) {
                continue;
            }
            if (vis[cx][cy] && !vis[g.f][g.s]) {
                ff(g.f, g.s);
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        int cx = x+dX[i], cy = y+dY[i];
        if (cx < 0 || cx >= n || cy < 0 || cy >= n) {
            continue;
        }
        if (light[cx][cy] && !vis[cx][cy]) {
            ff(cx, cy);
        }
    }
}

int main(){
    usopen("lightson")
    speedup
    int m; cin >> n >> m;
    at.resize(n, vector<vector<pii>>(n, vector<pii>()));
    for (int i = 0; i < m; i++) {
        int a, b, x, y; cin >> a >> b >> x >> y;
        a--, b--, x--, y--;
        at[a][b].push_back({x, y});
    }
    vis.resize(n, vector<bool>(n, false));
    light.resize(n, vector<bool>(n, false));
    ff(0, 0);
    light[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt += light[i][j];
        }
    }
    cout << cnt << endl;
    return 0;
}
