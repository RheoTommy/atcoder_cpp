#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; (i) < ll(n); (i)++)
#define REP2(i, s, n) for (ll i = (s); (i) < ll(n); (i)++)
#define R_REP(i, n) for (ll i = (n) - 1; (i) >= 0; (i)--)
#define R_REP2(i, s, n) for (ll i = (n) - 1; (i) >= (s); (i)--)


int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    vector<string> s;
    s.push_back("");
    s.push_back(s1);
    s.push_back(s2);
    s.push_back(s3);
    string t;
    cin >> t;
    REP(i, t.size()) {
        cout << s[t[i] - '0'];
    }
    cout << endl;
}