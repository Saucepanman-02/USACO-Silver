#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(file) do{freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);}while(0);
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>

int n, m, k;
struct SWH {
    int l, r;
};
vector<SWH> a;
vector<char> dir;

int main() {
    usopen("cruise")
    cin >> n >> m >> k;
    a.resize(n);
    dir.resize(m);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r; l--, r--;
        a[i] = {l, r};
    }
    for (int i = 0; i < m; i++) {
        cin >> dir[i];
    }
    vi p(n);
    for (int i = 0; i < n; i++) {
        int u = i;
        for (int j = 0; j < m; j++) {
            if (dir[j] == 'L') {
                u = a[u].l;
            }else {
                u = a[u].r;
            }
        }
        p[i] = u;
    }
    int u = 0;
    for (int i = 0; i < k; i++) {
        u = p[u];
    }
    cout << u+1 << endl;
    return 0;
}
