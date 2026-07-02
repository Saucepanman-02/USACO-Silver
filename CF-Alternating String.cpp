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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string st; cin >> st;
        if (n&1) {
            int ans = 1e9;
            vector<vi> prefo(26, vi(n+1)), prefe(26, vi(n+1));
            for (int i = 0; i < 26; i++) {
                for (int j = 2; j <= n; j += 2){
                    prefe[i][j] = prefe[i][j-2]+(st[j-1]-'a' == i);
                }
                prefo[i][1] = (st[0]-'a' == i);
                for (int j = 3; j <= n; j += 2) {
                    prefo[i][j] = prefo[i][j-2]+(st[j-1]-'a' == i);
                }
                for (int j = 1; j <= n; j++) {
                    if (j&1) {
                        vi es(26), os(26);
                        for (int k = 0; k < 26; k++) {
                            es[k] = prefe[k][j-1]+prefo[k][n]-prefo[k][j];
                            os[k] = (j >= 2 ? prefo[k][j-2]: 0)+prefe[k][n-1]-prefe[k][j-1];
                        }
                        int mxe = 0, mxo = 0;
                        for (int k = 0; k < 26; k++) {
                            mxe = max(mxe, es[k]);
                            mxo = max(mxo, os[k]);
                        }
                        ans = min(ans, (n-1)/2-mxe+(n-1)/2-mxo+1);
                    }else {
                        vi es(26), os(26);
                        for (int k = 0; k < 26; k++) {
                            es[k] = (j >= 2? prefe[k][j-2]: 0)+prefo[k][n]-prefo[k][j-1];
                            os[k] = prefo[k][j-1]+prefe[k][n-1]-prefe[k][j];
                        }
                        int mxe = 0, mxo = 0;
                        for (int k = 0; k < 26; k++) {
                            mxe = max(mxe, es[k]);
                            mxo = max(mxo, os[k]);
                        }
                        ans = min(ans, (n-1)/2-mxe+(n-1)/2-mxo+1);
                    }
                }
            }
            cout << ans << '\n';
        }else {
            vi oc(26), ec(26);
            for (int i = 0; i < n; i++) {
                if (i&1) {
                    oc[st[i]-'a']++;
                }else {
                    ec[st[i]-'a']++;
                }
            }
            int mxo = 0, mxe = 0;
            for (int i = 0; i < 26; i++) {
                mxo = max(mxo, oc[i]);
                mxe = max(mxe, ec[i]);
            }
            cout << (n-mxo-mxe) << '\n';
        }
    }

    return 0;
}
