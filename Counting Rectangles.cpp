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
#define f first
#define s second
#define pdi pair<db, int>
#define ceil(n, r) (ll)((n+r-1)/r)
#define floor(n, r) (ll)(n/r)
#define pil pair<int, ll>


const int MOD = 1e9+9;



int main() {
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<vll> g(1001, vll(1001));
        for (int i = 0; i < n; i++) {
            int h, w; cin >> h >> w;
            g[h][w] += h*w;
        }
        for (int i = 0; i <= 1000; i++) {
            for (int j = 0; j <= 1000; j++) {
                if (i) {
                    g[i][j] += g[i-1][j];
                }
                if (j) {
                    g[i][j] += g[i][j-1];
                }
                if (i && j) {
                    g[i][j] -= g[i-1][j-1];
                }
            }
        }
        
        for (int i = 0; i < q; i++) {
            int h1, w1; int h2, w2; cin >> h1 >>w1 >> h2 >> w2; h2--, w2--;
            cout << g[h2][w2]-g[h1][w2]-g[h2][w1]+g[h1][w1] << '\n';
        }
    }
    return 0;

}
