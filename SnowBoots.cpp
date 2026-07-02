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

vi ft;
vector<pii> bt;
int n, b;
vector<vi> vis;
int ans = 10000;

void ff(int cx, int cb) {
    if (vis[cx][cb]) {
        return;
    }
    if (cx == n-1) {
        ans = min(ans, cb);
        return;
    }
    vis[cx][cb] = 1;
    int r = min(n-1, bt[cb].s+cx);
    for (int i = cx+1; i <= r; i++) {
        if (ft[i] <= bt[cb].f)
            ff(i, cb);
    }
    int l = max(0, -bt[cb].s+cx);
    for (int i = cx-1; i >= l; i--) {
        if (ft[i] <= bt[cb].f)
            ff(i, cb);
    }
    int idx = cb+1;
    while (idx < b) {
        if (bt[idx].f >= ft[cx]) {
            break;
        }
        idx++;
    }
    if (idx < b)
        ff(cx, idx);
}

int main(){
    usopen("snowboots")
    speedup
    cin >> n >> b;
    ft.resize(n);
    for (int i = 0; i < n; i++){
        cin >> ft[i];
    }
    bt.resize(b);
    vis.resize(n, vi(b, 0));
    for (int i = 0; i < b; i++) {
        cin >> bt[i].f >> bt[i].s;
    }
    ff(0, 0);
    cout << ans << endl;
    return 0;
}
