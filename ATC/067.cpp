#include <bits/stdc++.h>
using namespace std;
string to_base9(long long x) {
    if (x == 0) return "0";
    string res;
    while (x > 0) {
        res += char('0' + x % 9);
        x /= 9;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main() {
    string n;
    int k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        long long dec = stoll(n, nullptr, 8);
        string base9 = to_base9(dec);
        for (char &c : base9) {
            if (c == '8') c = '5';
        }
        n = base9;
    }
    cout << n << endl;
}
