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

bool is_connected(ll bit) {
    vector<vector<ll>> a(4, vector<ll>(4, 0));
    REP(i, 16) {
        a[i / 4][i % 4] = (bit >> i) & 1;
    }

    ll dx[4] = {1, 0, -1, 0};
    ll dy[4] = {0, 1, 0, -1};

    vector<vector<ll>> b = a;
    REP(si, 4) {
        REP(sj, 4) {
            if (1 <= si && si <= 2 && 1 <= sj && sj <= 2) continue;
            if (b[si][sj] == 1) continue;
            b[si][sj] = 1;

            queue<pair<ll, ll>> que;
            que.emplace(si, sj);
            while (!que.empty()) {
                auto[i, j] = que.front();
                que.pop();
                REP(k, 4) {
                    ll ii = i + dx[k];
                    ll jj = j + dy[k];
                    if (ii < 0 || ii >= 4 || jj < 0 || jj >= 4) continue;
                    if (b[ii][jj] == 0) {
                        b[ii][jj] = 1;
                        que.emplace(ii, jj);
                    }
                }
            }
        }
    }

    REP(i, 4) REP(j, 4) if (b[i][j] == 0) return false;

    ll cnt = 0;

    REP(si, 4) {
        REP(sj, 4) {
            if (a[si][sj] == 0) continue;

            queue<pair<ll, ll>> que;
            que.emplace(si, sj);
            while (!que.empty()) {
                auto[i, j] = que.front();
                que.pop();
                REP(k, 4) {
                    ll ii = i + dx[k];
                    ll jj = j + dy[k];
                    if (ii < 0 || ii >= 4 || jj < 0 || jj >= 4) continue;
                    if (a[ii][jj] == 1) {
                        a[ii][jj] = 0;
                        que.emplace(ii, jj);
                    }
                }
            }
            cnt++;
        }
    }

    return cnt <= 1;
}

int main() {
    vector<vector<ll>> a(4, vector<ll>(4, 0));
    REP(i, 4) REP(j, 4) cin >> a[i][j];

    ll cnt = 0;

    REP(bit, 1ll << 16) {
        if (!is_connected(bit)) continue;

        bool flag = true;
        REP(i, 4) {
            REP(j, 4) {
                if (a[i][j] == 1 && ((bit >> (i * 4 + j)) & 1) == 0) flag = false;
            }
        }
        if (flag) cnt++;
    }

    cout << cnt << endl;
}