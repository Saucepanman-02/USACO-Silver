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

const int MOD = 1e9+7;

bool solve(vll &a, int n, ll md) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = n-1, ans = -1;
        while (r >= l) {
            int m = (r+l)/2;
            if (a[m] <= md-a[i]) {
                l = m+1;
                ans = m;
            }else {
                r = m-1;
            }
        }
        if (ans <= i) {
            break;
        }
        cnt += (ans-i);
    }
    return (cnt >= n-1);
}
ll F(vll &a, int n) {
    if (n == 1) {
        return a[0];
    }
    ll l = 0, r = 3000*1e9+10, ans = 3000*1e9;
    while (r >= l) {
        ll m = (r+l)/2;
        if (solve(a,n,  m)) {
            ans = m;
            r = m-1;
        }else {
            l = m+1;
        }
    }
    if (n > 1) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; i++) {
            l = 0, r = n-1; int cans = -1;
            while (r >= l) {
                int m = (r+l)/2;
                if (a[m] < ans-a[i]) {
                    l = m+1;
                    cans = m;
                }else {
                    r = m-1;
                }
            }
            if (cans <= i) {
                break;
            }
            for (int j = i+1; j <= cans; j++) {
                pq.push(a[j]+a[i]);
            }
        }
        for (int i = 0; i < n-1; i++) {
            if (pq.empty()) {
                a[i] = ans;
            }else {
                a[i] = pq.top();
                pq.pop();
            }
        }
    }
    ll q = a[0]/MOD;
    for (int i = 0; i < n-1; i++) {
        a[i] -= q*MOD;
    }
    return F(a, n-1);
}

int main() {
    int n; cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << F(a, n)%MOD << '\n';
    return 0;
}
