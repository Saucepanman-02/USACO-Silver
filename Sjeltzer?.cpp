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


ll p[10][10][10][10][10][10] = {};


ll rang(int a[6], int b[6]) {
    ll ans = 0;
    for (int mask = 0; mask < (1<<6); mask++) {
        bool flag = true;
        for (int i = 0; i < 6; i++) {
            if (mask&(1<<i))
                flag = flag&&(a[i]);
        }
        if (flag) {
            int c[6];
            for (int i = 0; i < 6; i++) {
                c[i] = (mask&(1<<i)? a[i]-1: b[i]);
            }
            ans += (__builtin_popcount(mask)%2? -1: 1)*p[c[0]][c[1]][c[2]][c[3]][c[4]][c[5]];
        }
    }
    return ans;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int st, v; cin >> st >> v;
        int a = st%10; st-= a; st/= 10;
        int b = st%10; st -= b; st/= 10;
        int c = st%10; st -= c; st/= 10;
        int d = st%10; st-= d; st/= 10;
        int e = st%10; st -= e; st /= 10;
        int f = st%10; st -= f; st /= 10;
        p[a][b][c][d][e][f] += v;
    }
    for (int st = 0; st < 1e6; st++) {
        int a[6];
        int duf = st;
        a[0] = st%10; st-= a[0]; st/= 10;
        a[1] = st%10; st -= a[1]; st/= 10;
        a[2] = st%10; st -= a[2]; st/= 10;
        a[3] = st%10; st-= a[3]; st/= 10;
        a[4] = st%10; st -= a[4]; st /= 10;
        a[5] = st%10; st -= a[5]; st /= 10; st = duf;
        ll cur = 0;
        for (int mask = 0; mask < (1<<6); mask++) {
            bool flag = true;
            for (int i = 0; i < 6; i++) {
                if (mask&(1<<i))
                    flag = flag && (a[i]);
            }
            if (flag) {
                int b[6];
                for (int i = 0; i < 6; i++) {
                    b[i] = a[i] - (mask&(1<<i)? 1: 0);
                }
                cur += (__builtin_popcount(mask)%2 || (mask == 0)? 1: -1)*p[b[0]][b[1]][b[2]][b[3]][b[4]][b[5]];
            }
        }
        p[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]] = cur;
    }
    //cout << p[0][0][0][0][0][0] << endl;
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int st; cin >> st;
        int a[6];
        a[0] = st%10; st-= a[0]; st/= 10;a[1] = st%10; st -= a[1]; st/= 10;a[2] = st%10; st -= a[2]; st/= 10;a[3] = st%10; st-= a[3]; st/= 10;a[4] = st%10; st -= a[4]; st /= 10;a[5] = st%10; st -= a[5]; st /= 10;
        int b[6]; cin >> st;
        b[0] = st%10; st-= b[0]; st/= 10;b[1] = st%10; st -= b[1]; st/= 10;b[2] = st%10; st -= b[2]; st/= 10;b[3] = st%10; st-= b[3]; st/= 10;b[4] = st%10; st -= b[4]; st /= 10;b[5] = st%10; st -= b[5]; st /= 10;
        bool flag = true;
        for (int j = 0; j < 6; j++) {
            flag = flag && (a[j] <= b[j]);
        }

        cout << (flag? rang(a, b): 0) << endl;
    }
    return 0;

}
