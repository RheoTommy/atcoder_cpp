#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1001001001001001001ll;
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

int main() {
    ll h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w, '.'));
    for (ll i = 0; i < ll(h); i++) {
        for (ll j = 0; j < ll(w); j++) {
            cin >> s[i][j];
        }
    }
    vector<vector<ll>> dp(h, vector<ll>(w, inf));
    dp[0][0] = 0;
    queue<pair<ll, ll>> que;
    que.emplace(0, 0);
    while (!que.empty()) {
        auto[i, j] = que.front();
        que.pop();
        for (ll k = 0; k < ll(4); k++) {
            ll ii = i + dx[k];
            ll jj = j + dy[k];
            if (ii < 0 || ii >= h || jj < 0 || jj >= w || s[i][j] == s[ii][jj]) continue;

            if (dp[ii][jj] > dp[i][j] + 1) {
                dp[ii][jj] = dp[i][j] + 1;
                que.emplace(ii, jj);
            }
        }
    }

    if (dp[h - 1][w - 1] == inf) dp[h - 1][w - 1] = -1;
    cout << dp[h - 1][w - 1] << endl;
}