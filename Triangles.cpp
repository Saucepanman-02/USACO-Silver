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

struct E{
    int x, y, idx;
};

bool cmp1(E &a, E &b) {
    return a.x < b.x;
}

bool cmp2(E &a, E &b) {
    return a.y < b.y;
}

const int MOD = 1e9+7;

int main() {
    usopen("triangles")
    speedup
    int n; cin >> n;
    vector<E> a(n);
    vi xcord, ycord;
    map<pii, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].idx = i;
        mp[{a[i].x,a[i].y}] = i;
        xcord.push_back(a[i].x);
        ycord.push_back(a[i].y);
    }
    sort(xcord.begin(), xcord.end());
    xcord.erase(unique(xcord.begin(), xcord.end()), xcord.end());
    sort(ycord.begin(), ycord.end());
    ycord.erase(unique(ycord.begin(), ycord.end()), ycord.end());
    map<int, int> xmp, ymp;
    int sz1 = xcord.size(), sz2 = ycord.size();
    for (int i = 0; i < sz1; i++) {
        xmp[xcord[i]] = i;
    }
    for (int i = 0; i < sz2; i++) {
        ymp[ycord[i]] = i;
    }
    vector<vll> xsep(sz1), ysep(sz2);
    vll xsum(n), ysum(n);
    for (int i = 0; i < n; i++) {
        xsep[xmp[a[i].x]].push_back(a[i].y);
        ysep[ymp[a[i].y]].push_back(a[i].x);
    }
    for (int i = 0; i < sz1; i++) {
        sort(xsep[i].begin(), xsep[i].end());
    }
    for (int i = 0; i < sz2; i++) {
        sort(ysep[i].begin(), ysep[i].end());
    }
    vll pref;
    for (int i = 0; i < sz1; i++) {
        int sz = xsep[i].size();
        pref.resize(sz+1);
        for (int j = 1; j <= sz; j++) {
            pref[j] = xsep[i][j-1]+pref[j-1];
        }
        int idx;
        for (int j = 1; j <= sz; j++) {
            idx = mp[{xcord[i], xsep[i][j-1]}];
            xsum[idx] += ((j-1)*xsep[i][j-1]-pref[j-1]);
            xsum[idx] %= MOD;
            xsum[idx] += (pref[sz]-pref[j]-(sz-j)*xsep[i][j-1]);
            xsum[idx] %= MOD;
        }
    }
    for (int i = 0; i < sz2; i++) {
        int sz = ysep[i].size();
        pref.resize(sz+1);
        for (int j = 1; j <= sz; j++) {
            pref[j] = ysep[i][j-1]+pref[j-1];
        }
        int idx;
        for (int j = 1; j <= sz; j++) {
            idx = mp[{ysep[i][j-1], ycord[i]}];
            ysum[idx] += ((j-1)*ysep[i][j-1]-pref[j-1]);
            ysum[idx] %= MOD;
            ysum[idx] += (pref[sz]-pref[j]-(sz-j)*ysep[i][j-1]);
            ysum[idx] %= MOD;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans+xsum[i]*ysum[i]%MOD)%MOD;
    }
    cout << ans << endl;
    return 0;
}
