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
#define pll pair<ll, ll>


map<pair<pii, pii>, bool> mp1;
map<pii, int> mp2;
int n;


int main() {
    speedup
    usopen("gates")
    cin >> n;
    string st; cin >> st;
    int x = 0, y = 0;
    mp2[{0, 0}] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int px = x, py = y;
        if (st[i] == 'N') {
            x += 1;
        }else if (st[i] == 'S') {
            x -= 1;
        }else if (st[i] == 'E') {
            y += 1;
        }else {
            y -= 1;
        }
        if (mp1.find({{px, py}, {x, y}}) == mp1.end() && mp2.find({x, y}) != mp2.end()) {
            ans++;
        }
        mp1[{{px, py}, {x, y}}] = 1;
        mp1[{{x, y}, {px, py}}] = 1;
        mp2[{x, y}] = 1;

    }
    cout << ans << endl;
    return 0;
}
