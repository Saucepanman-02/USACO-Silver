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
    usopen("cardgame")
    int n; cin >> n;
    vi a(n/2), b(n/2);
    set<int> st;
    for (int i = 0; i < 2*n; i++) {
        st.insert(i+1);
    }
    for (int i = 0; i < n/2; i++) {
        cin >> a[i];
        st.erase(a[i]);
    }
    for (int i = 0; i < n/2; i++) {
        cin >> b[i];
        st.erase(b[i]);
    }
    int ans = 0;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());
    for (int i = 0; i < n/2; i++) {
        auto it = st.end(); it--;
        if (*it > a[i]) {
            ans++;
            st.erase(it);
        }
    }
    for (int i = 0; i < n/2; i++) {
        auto it = st.begin();
        if (*it < b[i]) {
            ans++;
            st.erase(it);
        }
    }
    cout << ans << endl;
    return 0;
}
