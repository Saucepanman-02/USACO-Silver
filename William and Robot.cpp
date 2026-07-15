#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <climits>
#include <queue>
#include <numeric>
#include <functional>
#include <random>
#include <stack>
using namespace std;
 
#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define LSB(x) ((x) & -(x))
#define vi vector<int>
#define vll vector<ll>
#define vii vector<vector<int>>
#define pi pair<ll, ll>
 
 
int main(){
    speedup
    int n; cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    multiset<ll> ms;
    ms.insert(max(a[0], a[1]));
    for (int i = 2; i < n; i += 2){
        ll cur = *ms.begin();
        if (cur < min(a[i], a[i+1])){
            ms.erase(ms.begin());
            ms.insert(a[i]);
            ms.insert(a[i+1]);
        }else{
            ms.insert(max(a[i], a[i+1]));
        }
    }
    ll ans = 0;
    for (ll u: ms){
        ans += u;
    }
    cout << ans << endl;
    return 0;
}
