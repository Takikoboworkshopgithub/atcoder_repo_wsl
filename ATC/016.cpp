#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, a, b, c, ans = 1e9;

int main() {
    cin >> n >> a >> b >> c;
    for (int i = 0; i <= 9999; ++i) {
        for (int j = 0; i + j <= 9999; ++j) {
            ll rest = n - a * i - b * j;
            if (rest < 0) continue;
            if (rest % c != 0) continue;
            ll k = rest / c;
            if (i + j + k <= 9999) {
                ans = min(ans, i + j + k);
            }
        }
    }
    cout << ans << endl;
}