#include <bits/stdc++.h>

using namespace std;
const int MAX = 3000;
int n, k, arr[MAX][MAX], bit[MAX + 1][MAX + 1];
long long outp;
void update(int x, int y, int v) {
    for(x++; x <= n; x += x & -x) {
        int t = y;
        for(t++; t <= n; t += t & -t) bit[x][t] = max(bit[x][t], v);
    }
}
int query(int x, int y) {
    int ret = 0;
    for(x++; x > 0; x -= x & -x) {
        int t = y;
        for(t++; t > 0; t -= t & -t) ret = max(ret, bit[x][t]);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) cin >> arr[i][j];
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < n - i; j++) update(i + j, n - j - 1, arr[i + j][j]);
        if(n - i < k) continue;
        for(int j = 0; j < n - i - k + 1; j++) outp += query(i + k + j - 1, n - j - 1);
    }
    cout << outp << "\n";
}
