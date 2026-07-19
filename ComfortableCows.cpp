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

int MAXN = 4002;
vector<vi> g;
int n;
int dX[] = {0, 0, 1, -1};
int dY[] = {1, -1, 0, 0};
int lx, ly;
map<pii, int> mp;

int comf(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int cx = x+dX[i], cy = y+dY[i];
        if (g[cx][cy] > 0) {
            cnt++;
        }else {
            lx = cx, ly = cy;
        }
    }
    return cnt;
}

int cur = 0;
vector<vector<bool>> vis;


void ff(int x, int y) {
    if (vis[x][y]) {
        return;
    }
    vis[x][y] = true;
    if (comf(x, y) == 3) {
            cur++;
            //cout << lx << ' ' << ly << endl;
            vis[lx][ly] = false;
            g[lx][ly] = 2;
            ff(lx, ly);
    }
    for (int i = 0; i < 4; i++) {
        int cx = x+dX[i], cy = y+dY[i];
        if (g[cx][cy] && comf(cx, cy) == 3) {
                cur++;
                vis[lx][ly] = false;
                g[lx][ly] = 2;
                ff(lx, ly);
        }
    }
}

int main() {
    speedup
    g.resize(MAXN, vi(MAXN, 0));
    vis.resize(MAXN, vector<bool>(MAXN));
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cx, cy; cin >> cx >> cy;
        cx += 2000; cy += 2000;
        if (g[cx][cy] == 2) {
            g[cx][cy] = 1; cur--;
        }else {
            g[cx][cy] = 1;
            ff(cx, cy);
        }
        cout << cur << endl;
    }
    return 0;
}
