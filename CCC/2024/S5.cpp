#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

void solve() {
    cin >> n;
    array<vector<ll>, 2> arr;
    arr[0].resize(n);
    arr[1].resize(n);
    for(int i = 0; i < n; i++) cin >> arr[0][i];
    for(int i = 0; i < n; i++) cin >> arr[1][i];
    __int128 tot = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            arr[i][j] *= 2 * n;
            tot += arr[i][j];
        }
    }
    tot /= 2 * n;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            arr[i][j] -= tot;
        }
    }
    vector<ll> psa0(n), psa1(n);
    psa0[0] = arr[0][0];
    psa1[0] = arr[1][0];
    for(int i = 1; i < n; i++) {
        psa0[i] = psa0[i - 1] + arr[0][i];
        psa1[i] = psa1[i - 1] + arr[1][i];
    }
    vector<int> prv0(n, -1), prv1(n, -1);
    { // For prv0
        unordered_map<ll, int> st;
        for(int i = 0; i < n; i++) {
            ll psa_v = psa0[i];
            if(st.count(psa_v)) prv0[i] = st[psa_v];
            st[psa_v] = i;
        }
    }
    { // For prv1
        unordered_map<ll, int> st;
        for(int i = 0; i < n; i++) {
            ll psa_v = psa1[i];
            if(st.count(psa_v)) prv1[i] = st[psa_v];
            st[psa_v] = i;
        }
    }
    vector<int> dp0(n), dp1(n);
    unordered_map<ll, int> mp0, mp1;
    mp0[0] = 0;
    mp1[0] = 0;
    for(int i = 0; i < n; i++) {
        __int128 totp = psa0[i] + psa1[i];
        int delta = 1;
        if(totp == 0) delta = 2;
        if(i != 0) {
            dp0[i] = max(dp0[i - 1], dp1[i - 1]);
            dp1[i] = dp0[i];
        }
        if(totp == 0) {
            dp0[i]++;
            dp1[i]++;
        }
        { // 0
            ll pv0 = psa0[i];
            if(mp0.count(-pv0)) {
                dp1[i] = max(dp1[i], mp0[-pv0] + delta);
            }
            if(prv0[i] != -1) {
                dp1[i] = max(dp1[i], dp1[prv0[i]] + 1);
            }
        }
        { // 1
            ll pv1 = psa1[i];
            if(mp1.count(-pv1)) {
                dp0[i] = max(dp0[i], mp1[-pv1] + delta);
            }
            if(prv1[i] != -1) {
                dp0[i] = max(dp0[i], dp0[prv1[i]] + 1);
            }
        }
        mp0[psa1[i]] = max(mp0[psa1[i]], dp0[i]);
        mp1[psa0[i]] = max(mp1[psa0[i]], dp1[i]);
    }
    cout << max(dp0[n - 1], dp1[n - 1]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
