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
//#define max(a, b) (a >= b? a: b)
//#define min(a, b) (a <= b? a: b)

vector<db> pref;
vector<db> suf;
vector<db> a;
int n;

bool solve(db m) {
    int l = 0;
    bool flag = false;
    for (int r = 0; r < n; r++) {
        while (a[r]-a[l] > 2*m) {
            l++;
        }
        if ((pref[l+1] <= m-1 && suf[r+1] <= m-1)){
            flag = true;
            break;
        }
    }
    return flag;
}

int main() {
    usopen("angry")
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    pref.resize(n+1);
    suf.resize(n+1);
    int l = 1;
    for (int r = 2; r <= n; r++) {
        pref[r] = 1e9;
        while (l < r && a[r-1] - a[l-1] >= pref[l]+1) {
            pref[r] = min(pref[r], a[r-1]-a[l-1]);
            l++;
        }
        pref[r] = min(pref[r], pref[l]+1);
    }
    pref[1] = -1e9;
    suf[n] = -1e9;
    int r = n;
    for (l = n-1; l >= 1; l--) {
        suf[l] = 1e9;
        while (l < r && a[r-1]-a[l-1] >= suf[r]+1) {
            suf[l] = min(suf[l], a[r-1]-a[l-1]);
            r--;
        }
        suf[l] = min(suf[l], suf[r]+1);
    }
    db lo = 0, hi = 1e9+7, ans;
    while (hi-lo > 1e-2) {
        db m = (lo+hi)/2;
        if (solve(m)) {
            ans = m;
            hi = m;
        }else {
            lo = m;
        }
    }
    printf("%.1f\n", ans);
    return 0;
}
