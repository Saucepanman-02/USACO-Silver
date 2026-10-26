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
    int n, q; cin >> n >> q;
    vector<pii> upd(n); vi val(n); vector<pii> qur(q);
    vi a;
    for (int i = 0; i < n; i++){
        cin >> upd[i].f >> upd[i].s; cin >> val[i];
        a.push_back(upd[i].f);
        a.push_back(upd[i].s);
    }
    for (int i = 0; i < q; i++) {
        cin >> qur[i].f >> qur[i].s;
        a.push_back(qur[i].f);
        a.push_back(qur[i].s);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    map<int, int> mp; int sz = a.size();
    for (int i = 0; i < sz; i++) {
        mp[a[i]] = i;
    }
    vll pref1(sz+1);
    for (int i = 0; i < n; i++) {
        int l = mp[upd[i].f]+1;
        int r = mp[upd[i].s]+1;
        pref1[l] += val[i];
        pref1[r] -= val[i];
    }
    for (int i = 1; i <= sz; i++) {
        pref1[i] += pref1[i-1];
    }
    vll pref(sz+1);
    for (int i = 1; i <= sz; i++) {
        pref[i] = pref1[i]*(a[i]-a[i-1])+pref[i-1];
    }
    for (int i = 0; i < q; i++) {
        int l = mp[qur[i].f];
        int r = mp[qur[i].s];
        cout << pref[r]-pref[l] << '\n';
    }
    return 0;
}
