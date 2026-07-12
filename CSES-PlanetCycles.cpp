#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;
 
#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
 
vector<int> a, dist;
vector<bool> vis;
int steps = 0;
queue<int> q;
 
void dfs(int u){
    q.push(u);
    if (vis[u]){
        steps += dist[u];
        return;
    }
    vis[u] = true;
    steps++;
    dfs(a[u]);
}
 
int main() {
    speedup
    int n; cin >> n;
    a.resize(n);
    dist.resize(n);
    vis.resize(n, false);
    for (int i = 0; i < n; i++){
        cin >> a[i]; a[i]--;
    }
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            steps = 0;
            dfs(i);
            int d = 1;
            while (!q.empty()){
                if (q.front() == q.back()){
                    d = 0;
                }
                dist[q.front()] = steps;
                steps -= d;
                q.pop();
            }
        }
    }
    for (int v: dist){
        cout << v << ' ';
    }
    cout << endl;
    return 0;
}
