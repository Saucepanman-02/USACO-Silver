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


vector<string> g;
int n, k;
vector<vector<bool>> vis;
int dX[] = {0, 0, -1, 1};
int dY[] = {1, -1, 0, 0};
int cnt = 0;

void ff1(int x, int y) {
    if (vis[x][y]) {
        return;
    }
    vis[x][y] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int cx = x+dX[i], cy = y+dY[i];
        if (cx < 0 || cx >= n || cy < 0 || cy >= 10) {
            continue;
        }
        if (g[cx][cy] == g[x][y]) {
            ff1(cx, cy);
        }
    }
}

void ff2(int x, int y, char c) {
    g[x][y] = '0';
    for (int i = 0; i < 4; i++) {
        int cx = x+dX[i], cy = y+dY[i];
        if (cx < 0 || cx >= n || cy < 0 || cy >= 10) {
            continue;
        }
        if (g[cx][cy] == c) {
            ff2(cx, cy, c);
        }
    }
}

int main() {
    speedup
    usopen("mooyomooyo")
    cin >> n >> k;
    g.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    bool flag = true;
    while (flag) {
        vis.assign(n, vector<bool>(10, false));
        int cc = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (!vis[i][j] && g[i][j] > '0') { cnt = 0;
                    ff1(i, j);
                    if (cnt >= k) {
                        ff2(i, j, g[i][j]); cc++;
                    }
                }
            }
        }
        if (cc) {
            for (int j = 0; j < 10; j++) {
                vector<char> cur;
                for (int i = n-1; i >= 0; i--) {
                    if (g[i][j] != '0')
                        cur.push_back(g[i][j]);
                    g[i][j] = '0';
                }
                int sz = cur.size();
                for (int i = n-1; i >= n-sz; i--) {
                    g[i][j] = cur[n-1-i];
                }
            }
        }else {
            flag = false;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << g[i] << '\n';
    }
    return 0;
}
