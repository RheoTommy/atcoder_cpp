#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; (i) < ll(n); (i)++)
#define REP2(i, s, n) for (ll i = (s); (i) < ll(n); (i)++)
#define R_REP(i, n) for (ll i = (n) - 1; (i) >= 0; (i)--)
#define R_REP2(i, s, n) for (ll i = (n) - 1; (i) >= (s); (i)--)

template<class T>
bool chmin(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

int main() {
    ll n, x, y;
    cin >> n >> x >> y;

    const ll inf = 1001001001001001001ll;
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(x + 1, vector<ll>(y + 1, inf)));
    vector<ll> a(n);
    vector<ll> b(n);
    REP(i, n) cin >> a[i] >> b[i];

    dp[0][0][0] = 0;
    REP(i, n) {
        REP(j, x + 1) {
            REP(k, y + 1) {
                chmin(dp[i + 1][min(x, j + a[i])][min(y, k + b[i])], dp[i][j][k] + 1);
                chmin(dp[i + 1][j][k], dp[i][j][k]);
            }
        }
    }

    ll ans = dp[n][x][y];
    cout << (ans == inf ? -1 : ans) << endl;
}