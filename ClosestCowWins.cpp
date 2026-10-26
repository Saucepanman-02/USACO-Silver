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


int main() {
    speedup
    int k, m, n; cin >> k >> m >> n;
    vector<pii> lt(k);
    for (int i = 0; i < k; i++) {
        cin >> lt[i].f >> lt[i].s;
    }
    sort(lt.begin(), lt.end());
    vi nj(m);
    for (int i = 0; i < m; i++) {
        cin >> nj[i];
    }
    sort(nj.begin(), nj.end());
    vi lst;
    //Left-end
    ll sum = 0;
    for (int l = 0; l < k; l++) {
        if (lt[l].f < nj[0]) {
            sum += lt[l].s;
        }
    }
    lst.push_back(sum);
    //Right-end
    sum = 0;
    for (int r = k-1; r >= 0; r--) {
        if (lt[r].f > nj[m-1]) {
            sum += lt[r].s;
        }
    }
    lst.push_back(sum);
    //Rest-summing
    for (int i = 0; i < m-1; i++) {
        int l = 0, r = k-1, cl;
        while (r >= l) {
            int md = (r+l)/2;
            if (lt[md].f >= nj[i]) {
                r = md-1;
                cl = md;
            }else {
                l = md+1;
            }
        }
        l = 0, r = k-1; int cr;
        while (r >= l) {
            int md = (r+l)/2;
            if (lt[md].f <= nj[i+1]) {
                l = md+1;
                cr = md;
            }else {
                r = md-1;
            }
        }
        vector<pii> lr;
        ll csum = 0;
        for (int j = cl; j <= cr; j++) {
            int d = min(abs(lt[j].f-nj[i]), abs(lt[j].f-nj[i+1]));
            csum += lt[j].s;
            lr.push_back({lt[j].f-d+1, lt[j].s});
            lr.push_back({lt[j].f+d, -lt[j].s});
        }
        sort(lr.begin(), lr.end());
        ll cur = 0, best = 0;
        for (auto &[c, w]: lr) {
            cur += w;
            best = max(best, cur);
        }
        lst.push_back(best);
        lst.push_back(csum-best);
    }
    sort(lst.begin(), lst.end());
    reverse(lst.begin(), lst.end());
    ll ans = 0; int sz = lst.size();
    for (int i = 0; i < min(n, sz); i++) {
        ans += lst[i];
    }
    cout << ans << endl;
    return 0;
}
