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
    string st; cin >> st;
    int n = st.size();
    vector<vi> pref(26, vi(n+1));
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = (st[j-1]-'a' == i)+pref[i][j-1];
        }
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (pref[i][r]-pref[i][l-1] > 0) {
                cnt++;
            }
        }
        if (cnt >= 3){
            cout << "Yes" << '\n';
        }else if (cnt == 2 && st[l-1] != st[r-1]) {
            cout << "Yes" << '\n';
        }else if (l == r) {
            cout << "Yes" << '\n';
        }else {
            cout << "No" << '\n';
        }
    }
    return 0;
}
