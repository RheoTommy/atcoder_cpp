#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w, 0));
    for (ll i = 0; i < ll(h); i++)
        for (ll j = 0; j < ll(w); j++)
            cin >> a[i][j];

    auto area = [&](ll si, ll sj, ll ti, ll tj) {
        assert(si <= ti);
        assert(sj <= tj);

        ll sum = 0;
        for (ll i = si; i < ll(ti); i++)
            for (ll j = sj; j < ll(tj); j++)
                sum += a[i][j];
        return sum;
    };

    ll ans = 0;

    for (ll x = 1; x <= ll(h); x++) {
        for (ll y = 1; y <= ll(w); y++) {
            if (x == h && y == w) continue;
            bool flag = true;
            ll sum = area(0, 0, x, y);

            vector<ll> xs;
            xs.push_back(x);
            if (x != h) {
                ll j = y;
                ll si = x;
                for (ll i = x + 1; i <= ll(h); i++) {
                    ll calc = area(si, 0, i, j);
                    if (sum > calc) continue;
                    if (sum < calc) flag = false;
                    if (sum == calc) {
                        xs.push_back(i);
                        si = i;
                    }
                }
                if (si != h) flag = false;
            }

            vector<ll> ys;
            ys.push_back(y);
            if (y != w) {
                ll i = x;
                ll sj = y;
                for (ll j = y + 1; j <= ll(w); j++) {
                    ll calc = area(0, sj, i, j);
                    if (sum > calc) continue;
                    if (sum < calc) flag = false;
                    if (sum == calc) {
                        ys.push_back(j);
                        sj = j;
                    }
                }
                if (sj != w) flag = false;
            }

            if (!flag) continue;
            for (ll ki = 0; ki < ll(xs.size()) - 1; ki++) {
                for (ll kj = 0; kj < ll(ys.size()) - 1; kj++) {
                    ll si = xs[ki];
                    ll sj = ys[kj];
                    ll ti = xs[ki + 1];
                    ll tj = ys[kj + 1];
                    if (sum != area(si, sj, ti, tj)) flag = false;
                }
            }

            if (flag) {
//                cerr << "xs: ";
//                for (auto xi: xs) cerr << xi << " ";
//                cerr << endl;
//                cerr << "ys: ";
//                for (auto yi: ys) cerr << yi << " ";
//                cerr << endl;
//                cerr << sum << endl;

                ans++;
            }
        }
    }

    cout << ans << endl;
}