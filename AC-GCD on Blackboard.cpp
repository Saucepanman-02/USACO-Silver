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

int gcd(int m, int n) {
    if (n == 0) {
        return m;
    }
    return gcd(n, m%n);
}

int main(){
    speedup
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi pref(n+1), suf(n+1);
    for (int i = 1; i <= n; i++) {
        pref[i] = gcd(pref[i-1], a[i-1]);
    }
    for (int i = n-1; i >= 0; i--) {
        suf[i] = gcd(suf[i+1], a[i]);
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, gcd(pref[i], suf[i+1]));
    }
    cout << mx << endl;
    return 0;
}
