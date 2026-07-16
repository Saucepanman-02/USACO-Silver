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
    usopen("helpcross")
    int c, n; cin >> c >> n;
    vi ch(c);
    for (int i = 0; i < c; i++) {
        cin >> ch[i];
    }
    sort(ch.begin(), ch.end());
    priority_queue<pii> pq;
    vector<pii> cow(n);
    for (int i = 0; i < n; i++) {
        cin >> cow[i].f >> cow[i].s;
    }
    sort(cow.begin(), cow.end());
    int cw = 0;
    int ck = 0; int ans = 0;
    while (ck < c) {
        while (cw < n && ch[ck] >= cow[cw].f) {
            pq.push({-cow[cw].s, cow[cw].f});
            cw++;
        }
        while (!pq.empty() && ch[ck] > -pq.top().f) {
            pq.pop();
        }
        if (!pq.empty()) {
            ans++; pq.pop();
        }
        ck++;
    }
    cout << ans << endl;
    return 0;
}
