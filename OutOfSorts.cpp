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
    usopen("sort")
    int n; cin >> n;
    vi a(n);
    vi r;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r.push_back(a[i]);
    }
    sort(r.begin(), r.end());
    map<int, int> mp; int sz = r.size();
    for (int i = sz-1; i >= 0; i--) {
        mp[r[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int duf = mp[a[i]]; mp[a[i]]++;
        a[i] = duf;
        ans = max(i-a[i], ans);
    }
    cout << ans+1 << endl;
    return 0;
}
