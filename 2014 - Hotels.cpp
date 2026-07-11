#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>

uint16_t dist[5000*5000+1];
vi g[5001];
int n;

#define D(u, d) dist[(u) * n + (d)]

void dfs(int u, int p) {
    for (int v : g[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        for (int i = 0; i < n - 1; ++i)
            D(u, i + 1) += D(v, i);
    }
    ++D(u, 0);
}

ll ans = 0;
ll s1, s2, s3, d, d2;

void dfs1(int u, int p) {
    for (int i = 1; i < n; ++i) {
        s1 = s2 = s3 = d = 0;

        for (int v : g[u]) {
            if (v == p)
                continue;

            d = D(v, i - 1); d2 = d*d;
            s1 += d;
            s2 += d2;
            s3 += d2 * d;
        }
        ans += (s1 * s1 * s1 - 3 * s1 * s2 + 2 * s3) / 6;
        if (p != -1) {
            d = (i == 1 ? 1 : D(p, i - 1) - D(u, i - 2));
            ans += d * (s1 * s1 - s2) / 2;
        }
    }

    if (p != -1) {
        for (int i = n - 2; i > 0; --i)
            D(u, i + 1) += D(p, i) - D(u, i - 1);

        ++D(u, 1);
    }

    for (int v : g[u]) {
        if (v == p)
            continue;
        dfs1(v, u);
    }
}

int main() {
    speedup;
    cin >> n;
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    dfs1(0, -1);
    cout << ans << '\n';
    return 0;
}
