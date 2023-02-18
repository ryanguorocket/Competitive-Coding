#include <bits/stdc++.h>

using namespace std;
int main() {
    long n, temp;
    cin >> n;
    cin >> temp;
    string twos, pattern;
    twos = std::bitset<64> (temp).to_string();
    cin >> pattern;
    for(int i = 0; i < twos.length(); i++) {
        if(twos.at(i) == '1') {
            long long shift = ((long long) 1 << (twos.length() - i - 1)) % n;
            string left = pattern.substr((int) shift, (int) n) + pattern.substr(0, (int) shift);
            string right = pattern.substr((int)(n - shift), (int) n) + pattern.substr(0, (int)(n - shift));
            pattern = "";
            for(int u = 0; u < n; u++) {
                if (left.at(u) == right.at(u)) pattern += '0';
                else pattern += '1';
            }
        }
    }
    cout << pattern;
}
