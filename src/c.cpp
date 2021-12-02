#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; (i) < ll(n); (i)++)
#define REP2(i, s, n) for (ll i = (s); (i) < ll(n); (i)++)
#define R_REP(i, n) for (ll i = (n) - 1; (i) >= 0; (i)--)
#define R_REP2(i, s, n) for (ll i = (n) - 1; (i) >= (s); (i)--)

int main() {
    string x;
    cin >> x;
    map<char, ll> mp;
    REP(i, 26) mp[x[i]] = i + 1;
    ll n;
    cin >> n;
    vector<string> s(n);
    REP(i, n) cin >> s[i];

    sort(s.begin(), s.end(), [&](string i, string j) {
        ll mn = (ll) min(i.size(), j.size());
        REP(k, mn) {
            if (i[k] == j[k]) continue;
            return mp[i[k]] < mp[j[k]];
        }
        return i.size() < j.size();

    });

    for (auto si: s) {
        cout << si << endl;
    }
}