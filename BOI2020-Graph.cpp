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
    int u, v; db w;
};
vector<vector<pair<int, db>>> g;
vi c;
vector<db> wt;
vi l;
vector<E> vol;
bool flag = false;

void dfs(int u) {
    l.push_back(u);
    for (auto &[v, w]: g[u]) {
        if (c[v] == -1) {
            c[v] = 1-c[u];
            wt[v] = w-wt[u];
            dfs(v);
        }else if (c[v] == c[u]) {
            vol.push_back({u, v, w});
        }else{
            if (wt[v]+wt[u] != w) {
                flag = true;
            }
        }
    }
}
vector<db> fi;

void dfs1(int u) {
    for (auto &[v, w]: g[u]) {
        if (c[v] == 0) {
            c[v] = 1;
            dfs1(v);
            if (fi[u]+fi[v] != w) {
                flag = true;
                return;
            }
        }
    }
}

int main() {
    speedup
    int n, m; cin >> n >> m;
    g.resize(n);
    c.resize(n, -1);
    wt.resize(n);
    vector<pair<int, db>> sloop;
    for (int i = 0; i < m; i++) {
        int u, v; db w; cin >> u >> v >> w; u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        if (u == v) {
            sloop.push_back({u, (db)(w)/2});
        }
    }/*
    for (auto &[u, val]: sloop) {
        if (c[u] == -1) {
            wt[u] = val;
            dfs1(u);
            if (flag) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }*/
    vector<db> rval(n);
    for (int i = 0; i < n; i++) {
        if (c[i] == -1) {
            l.clear();
            vol.clear();
            c[i] = 0;
            dfs(i);
            db rv = 0;
            if (flag) {
                cout << "NO" << endl;
                return 0;
            }
            if (!vol.empty()) {
                set<db> r;
                for (auto &[u, v, w]: vol) {
                    if (c[u] == 0) {
                        db cur = (db)(w-wt[u]-wt[v])/2;
                        r.insert(cur);
                    }else {
                        db cur = (db)(wt[u]+wt[v]-w)/2;
                        r.insert(cur);
                    }
                }
                if (r.size() > 1) {
                    cout << "NO" << endl;
                    return 0;
                }
                rv = *r.begin();
            }else {
                vi cons;
                for (int v: l) {
                    if (c[v] == 0) {
                        cons.push_back(-wt[v]);
                    }else {
                        cons.push_back(+wt[v]);
                    }
                }
                sort(cons.begin(), cons.end());
                int sz = cons.size();
                rv = cons[(sz-1)/2];
            }
            for (int v: l) {
                if (c[v] == 0) {
                    rval[v] = rv;
                }else {
                    rval[v] = -rv;
                }
            }
        }
    }
    fi.resize(n);
    for (int i = 0; i < n; i++) {
        fi[i] = wt[i]+rval[i];
    }
    c.resize(n);
    for (int i = 0; i < n; i++) {
        if (c[i] == 0) {
            c[i] = 1;
            dfs1(i);
        }
    }
    if (flag) {
        cout << "NO" << endl;
    }else {
        cout << "YES" << endl;
        for (db u: fi) {
            cout << u << ' ';
        }
        cout << endl;
    }
    return 0;
}
