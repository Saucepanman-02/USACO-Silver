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
    int n; cin >> n;
    vector<pll> l(n);
    vll a;
    for (int i = 0; i < n; i++) {
        ll lo, ri; cin >> lo >> ri;
        l[i] = {lo, ri+1};
        a.push_back(lo);
        a.push_back(ri+1);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    map<ll, int> mp; int sz = a.size();
    for (int i = 0; i < sz; i++) {
        mp[a[i]] = i;
    }
    vll pref(sz+1);
    for (int i = 0; i < n; i++) {
        pref[mp[l[i].f]+1] += 1;
        pref[mp[l[i].s]+1] -= 1;
    }
    for (int i = 1; i <= sz; i++) {
        pref[i] += pref[i-1];
    }
    vll ans(n+1);
    int cur = 0;
    for (int i = 1; i < sz; i++) {
        cur = pref[i];
        ans[cur] += (a[i]-a[i-1]);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
