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
    int x, n; cin >> x >> n;
    priority_queue<int, vi, greater<int>> pq;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        pq.push(c);
    }
    while (pq.size() > 1) {
        int p = pq.top(); pq.pop(); int q = pq.top(); pq.pop();
        ans += (p+q);
        pq.push(p+q);
    }
    cout << ans << endl;
    return 0;
}
