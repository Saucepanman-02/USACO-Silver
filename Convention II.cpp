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

struct E {
    int x, y, z;
};

bool cmp(E &a, E &b) {
    return (a.x < b.x);
}

int main() {
    usopen("convention2")
    int n; cin >> n;
    vector<E> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].z = i;
        b[i] = a[i];
    }
    sort(a.begin(), a.end(), cmp);
    int c = 0;
    priority_queue<pii> pq;
    int ans = 0;
    while (c < n) {
        pq.push({-a[c].z, a[c].x});
        int t = a[c].x; c++;
        while (!pq.empty()) {
            pii u = pq.top(); pq.pop();
            u.f *= -1;
            ans = max(ans, t-b[u.f].x);
            t += b[u.f].y;
            while (c < n && a[c].x <= t) {
                pq.push({-a[c].z, a[c].x});
                c++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
