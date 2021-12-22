#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = int;

struct UnionFind {
    vector<ll> par;

    explicit UnionFind(ll n) : par(n, -1) {}

    ll root(ll x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    bool unite(ll x, ll y) {
        ll rx = root(x);
        ll ry = root(y);
        if (rx == ry) return false;
        if (par[rx] > par[ry]) {
            swap(rx, ry);
        }
        par[rx] += par[ry];
        par[ry] = rx;
        return true;
    }

    bool same(ll x, ll y) {
        return root(x) == root(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<pair<ll, ll>> uv;
    for (ll i = 0; i < ll(m); i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        uv.emplace_back(u, v);
    }
    vector<ll> s(n);
    for (ll i = 0; i < ll(n); i++) cin >> s[i], s[i]--;

    map<pair<ll, ll>, set<pair<ll, ll>>> edge;
    for (ll i = 0; i < ll(m); i++) {
        auto[u, v] = uv[i];
        edge[{s[u], s[v]}].insert({u, v});
        edge[{s[v], s[u]}].insert({v, u});
    }

    vector<vector<ll>> vertex(k);
    vector<ll> tree_size(k);
    vector<ll> num(n);
    for (ll i = 0; i < ll(n); i++) {
        vertex[s[i]].push_back(i);
    }
    for (ll ki = 0; ki < ll(k); ki++) {
        map<ll, ll> index;
        ll len = (ll) vertex[ki].size();
        ll size = len;
        for (ll i = 0; i < ll(len); i++) {
            index[vertex[ki][i]] = i;
        }
        UnionFind uf(len);
        for (auto[u, v]: edge[{ki, ki}]) {
            if (uf.unite(index[u], index[v])) size--;
        }
        vector<ll> par_num(len, -1);
        ll cnt = 0;
        for (ll i = 0; i < ll(len); i++) {
            if (uf.root(i) == i) par_num[i] = cnt, cnt++;
        }

        for (ll i = 0; i < ll(len); i++) {
            num[vertex[ki][i]] = par_num[uf.root(i)];
        }

        tree_size[ki] = size;
    }


    ll q;
    cin >> q;
    vector<pair<ll, ll>> query;
    for (ll i = 0; i < ll(q); i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        query.emplace_back(a, b);
    }

    vector<pair<ll, ll>> que = query;
    map<pair<ll, ll>, ll> ans;
    sort(que.begin(), que.end(),
         [&](pair<ll, ll> a, pair<ll, ll> b) {
             return pair{s[a.first], s[a.second]} < pair{s[b.first], s[b.second]};
         });

    UnionFind uf(0);
    ll sa = -1;
    ll sb = -1;
    for (auto[a, b]: que) {
        if (s[a] == s[b]) {
            ans[{a, b}] = num[a] == num[b];
            continue;
        }

        if (sa == s[a] && sb == s[b]) {
            ans[{a, b}] = uf.same(num[a], tree_size[sa] + num[b]);
        } else {
            sa = s[a];
            sb = s[b];

            ll a_size = tree_size[s[a]];
            ll b_size = tree_size[s[b]];
            uf = UnionFind(a_size + b_size);

            for (auto[u, v]: edge[{s[a], s[b]}]) {
                uf.unite(num[u], a_size + num[v]);
            }
            ans[{a, b}] = uf.same(num[a], a_size + num[b]);
        }
    }

    for (auto[a, b]: query) {
        cout << ans[{a, b}] << endl;
    }
}