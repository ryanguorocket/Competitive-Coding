#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> frac;

ll n;

vector<frac> filters;

frac reduceFrac(frac a) {
    ll cd = __gcd(a.first, a.second);
    a.first /= cd;
    a.second /= cd;
    return a;
}

frac addFrac(frac a, frac b) {
    ll cd = __gcd(a.second, b.second);
    a.first = (a.first * (b.second / cd)) + (b.first * (a.second / cd));
    a.second *= b.second / cd;
    return reduceFrac(a);
}

frac subFrac(frac a, frac b) {
    ll cd = __gcd(a.second, b.second);
    a.first = (a.first * (b.second / cd)) - (b.first * (a.second / cd));
    a.second *= b.second / cd;
    return reduceFrac(a);
}

frac mulFrac(frac a, ll v) {
    a.second *= v;
    return reduceFrac(a);
}

frac divFrac(frac a, ll v) {
    a.second *= v;
    return reduceFrac(a);
}

ll fracLeft(frac a) {
    ll ret = (a.first * n) / a.second;
    if((a.first * n) % a.second != 0) ret++;
    return ret;
}

ll fracRight(frac a) {
    return (a.first * n) / a.second;
}

void genFilters(int depth, frac l, frac r) {
    if(depth == 0) return;
    frac diff = divFrac(subFrac(r, l), 3ll);
    frac lsp = addFrac(l, diff);
    frac rsp = subFrac(r, diff);
    genFilters(depth - 1, l, lsp);
    filters.push_back(lsp);
    filters.push_back(rsp);
    genFilters(depth - 1, rsp, r);
}

vector<ll> outp;

bool inCantorSet(frac a) {
    ll num = a.first;
    ll den = a.second;
    for(int i = 0; i < 1000; i++) {
        num *= 3ll;
        if(num % den == 0) return true;
        if(num / den == 1ll) return false;
        num %= den;
    }
    return true;
}

void process(frac l, frac r) {
    ll lv = fracLeft(l);
    ll rv = fracRight(r);
    for(ll i = lv; i <= rv; i++) {
        frac cur = reduceFrac({i, n});
        if(inCantorSet(cur)) outp.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    filters.push_back({0ll, 1ll});
    genFilters(18, {0ll, 1ll}, {1ll, 1ll});
    filters.push_back({1ll, 1ll});
    for(int i = 0; i < filters.size(); i++) {
        process(filters[i], filters[i + 1]);
        i++;
    }
    for(ll i: outp) cout << i << "\n";
}
