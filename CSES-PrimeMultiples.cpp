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
 
 
int main(){
    speedup
    ll n; int k; cin >> n >> k;
    vll a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i < (1<<k); i++) {
        ll cur = n;
        for (int j = 0; j < k; j++) {
            if (i&(1<<j)) {
                cur /= a[j];
            }
        }
        ans += (__builtin_popcount(i)&1 ? 1: -1)* (cur);
    }
    cout << ans << endl;
    return 0;
}
