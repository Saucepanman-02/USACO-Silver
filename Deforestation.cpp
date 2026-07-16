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

struct E {
    int l, r, tr;
};

vi t;
int n, k;

int lbound(int x) {
    int l = 0, r = n-1, ans = n;
    while (r >= l) {
        int md = (r+l)/2;
        if (t[md] >= x) {
            r = md-1;
            ans = md;
        }else {
            l = md+1;
        }
    }
    return ans;
}

bool cmp(E &a, E &b) {
    if (a.l == b.l) {
        return a.tr > b.tr;
    }
    return a.l < b.l;
}

int main() {
    int tcs; cin >> tcs;
    while (tcs--) {
        cin >> n >> k;
        t.assign(n, 0);
        vector<E> a(n+k);
        for (int i = 0; i < n; i++) {
            cin >> t[i];
            a[k+i] = {t[i], 0, -1};
        }
        sort(t.begin(), t.end());
        for (int i = 0; i < k; i++) {
            cin >> a[i].l >> a[i].r;
            int th; cin >> th;
            th = lbound(a[i].r+1)-lbound(a[i].l)-th;
            a[i].tr = th;
        }
        sort(a.begin(), a.end(), cmp);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int ans = 0;
        for (E &e: a) {
            if (e.tr == -1) {
                int c = e.l;
                while (!pq.empty() && c > pq.top().s) {
                    pq.pop();
                }
                if (pq.empty() || pq.top().f > ans ) {
                    ans++;
                }
            }else {
                pq.push({ans+e.tr, e.r});
            }
        }
        cout << ans << endl;
    }
    return 0;
}
