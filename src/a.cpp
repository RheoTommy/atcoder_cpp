#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll q;
    cin >> q;
    vector<string> st;
    for (ll i = 0; i < ll(q); i++) {
        string si;
        cin >> si;
        if (si == "READ") {
            cout << st.back() << endl;
            st.pop_back();
        } else {
            st.push_back(si);
        }
    }
}