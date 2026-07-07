#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 
vector<vector<int>> graph;
vector<int> max_length;
vector<int> to_leaf;
 
int dfs(int cur, int par){ //Returns the value of to_leaf(cur)
    priority_queue<int> pq;
    for (int v: graph[cur]){
        if (v != par) {
            pq.push(dfs(v, cur));
        }
    }
    if (pq.size() >= 2){
        int mx1 = pq.top(); pq.pop();
        int mx2 = pq.top();
        max_length[cur] = mx1+mx2+1;
        return (mx1+1);
    }else if (pq.size() == 1){
        int mx1 = pq.top();
        max_length[cur] = mx1+1;
        return (mx1+1);
    }else{
        return 1;
    }
}
 
int main(){
    speedup
    int n;
    cin >> n;
    graph.resize(n);
    max_length.resize(n, -1);
    to_leaf.resize(n, -1);
    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0, 0);
    int ans = 0;
    for (int a: max_length){
        ans = max(a, ans);
    }
    if (ans > 0) {
        cout << (ans - 1) << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}
