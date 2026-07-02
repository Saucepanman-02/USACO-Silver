#include <bits/stdc++.h>

using namespace std;
#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(filename) do{freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);}while(0);
#define f first
#define s second
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>

const int MOD = 2019;

int main(){
    speedup
    string st; cin >> st;
    int n = st.size();
    reverse(st.begin(), st.end());
    vi pref(n+1);
    int pow = 1;
    for (int i = 1; i <= n; i++) {
        pref[i] = (pref[i-1]+(st[i-1]-'0')*pow)%MOD;
        pow = (10*pow)%MOD;
    }
    vll cnt(MOD);
    for (int i = 0; i <= n; i++) {
        cnt[pref[i]]++;
    }
    ll ans = 0;
    for (int i = 0; i < MOD; i++) {
        ans += (cnt[i]*(cnt[i]-1))/2;
    }
    cout << ans << endl;
    return 0;
}
