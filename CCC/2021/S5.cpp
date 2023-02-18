#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;

ll gcd(ll a, ll b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

ll fac = 1;

const int MAX = 150000;
const int mod = 1e9 + 7;

int n, m, inp[MAX][3];

ll arr[MAX];

int cnt[17];

vector<int> add[MAX], sub[MAX];

ll seg[1 << 19];

void init(int a, int b, int c) {
    if(a == b) {
        seg[c] = arr[a];
        return;
    }
    init(a, (a + b) / 2, 2 * c + 1);
    init((a + b) / 2 + 1, b, 2 * c + 2);
    seg[c] = gcd(seg[2 * c + 1], seg[2 * c + 2]);
}

ll query(int a, int b, int c, int be, int en) {
    if(a > en || b < be) return fac;
    if(a >= be && b <= en) return seg[c];
    ll l = query(a, (a + b) / 2, 2 * c + 1, be, en);
    ll r = query((a + b) / 2 + 1, b, 2 * c + 2, be, en);
    return gcd(l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i < 17; i++) fac *= i;
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        inp[i][0] = x;
        inp[i][1] = y;
        inp[i][2] = z;
        add[x].push_back(z);
        sub[y].push_back(z);
    }
    for(int i = 0; i < n; i++) {
        for(int j: add[i]) cnt[j]++;
        arr[i] = 1;
        for(int j = 1; j < 17; j++) {
            if(cnt[j] == 0) continue;
            ll t = gcd(arr[i], j); //lcm
            arr[i] *= j;
            arr[i] /= t;
        }
        for(int j: sub[i]) cnt[j]--;
    }
    init(0, n - 1, 0);
    for(int i = 0; i < m; i++) {
        if(query(0, n - 1, 0, inp[i][0], inp[i][1]) != inp[i][2]) {
            cout << "Impossible\n";
            return 0;
        }
    }
    for(int i = 0; i < n - 1; i++) cout << arr[i] << " ";
    cout << arr[n - 1] << "\n";
}
