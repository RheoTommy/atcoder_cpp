#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T>
bool chmax(T &x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < ll(n); i++) cin >> a[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (ll i = 0; i < ll(n); i++) {
        for (ll j = 0; j < ll(n); j++) {
            if (dp[i][j] == 0) chmax(dp[i + 1][i], dp[i][j] + a[i]);
            chmax(dp[i + 1][j], dp[i][j]);
            chmax(dp[min(n, max(i + 1, j + k))][i], dp[i][j] + a[i]);
        }
    }

    ll ans = 0;
    for (ll j = 0; j < ll(n); j++) {
        chmax(ans, dp[n][j]);
    }
    cout << ans << endl;
}