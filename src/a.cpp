#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; (i) < ll(n); (i)++)
#define REP2(i, s, n) for (ll i = (s); (i) < ll(n); (i)++)
#define R_REP(i, n) for (ll i = (n) - 1; (i) >= 0; (i)--)
#define R_REP2(i, s, n) for (ll i = (n) - 1; (i) >= (s); (i)--)


int main() {
    ll x;
    cin >> x;
    if (x < 40) cout << 40 - x << endl;
    else if (x < 70) cout << 70 - x << endl;
    else if (x < 90) cout << 90 - x << endl;
    else cout << "expert" << endl;
    cout << (1 << 8) << endl;
}