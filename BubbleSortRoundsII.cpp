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
    int n, k; cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (k >= n) {
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout<< endl;
        return 0;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++) {
        pq.push(a[i]);
    }
    vi ans(n);
    for (int i = 0; i < n; i++) {
        if (i+k < n) {
            pq.push(a[i+k]);
        }
        int tp = pq.top();
        ans[i] = tp; pq.pop();
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    return 0;
}
