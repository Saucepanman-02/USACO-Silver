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

vector<string> a;
int dX[] = {0, 0, 1, -1};
int dY[] = {1, -1, 0, 0};
vector<vector<bool>> vis;
int n;
int area, per;

void ff(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return;
    }
    if (vis[x][y]) {
        return;
    }
    vis[x][y] = true;
    area++;
    for (int i = 0; i < 4; i++) {
        int cx = x+dX[i], cy = y+dY[i];
        if (cx < 0 || cx >= n || cy < 0 || cy >= n) {
            per++;
        }else {
            if (a[cx][cy] == '.') {
                per++;
            }else {
                ff(cx, cy);
            }
        }
    }
}

int main() {
    usopen("perimeter")
    cin >> n;
    a.resize(n);
    vis.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        string st; cin >> st;
        a[i] = st;
    }
    int marea = 0, sper = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && a[i][j] == '#') {
                area = 0, per = 0;
                ff(i, j);
                if (area > marea) {
                    marea = area;
                    sper = per;
                }else if (area == marea) {
                    sper = min(sper, per);
                }
            }
        }
    }
    cout << marea << ' ' << sper << endl;
    return 0;
}
