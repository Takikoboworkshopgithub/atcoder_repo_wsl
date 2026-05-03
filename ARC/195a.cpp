#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    vector<int> a_idx;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[0]) {
            a_idx.push_back(i);
        }
    }

    if (a_idx.size() < 2) {
        cout << "No" << endl;
        return 0;
    } else {
        int cnt = 0;
        int b_idx = 1;

        for (int i = a_idx[0] + 1; i < n; ++i) {
            if (a[i] == b[b_idx]) {
                b_idx++;
                if (b_idx == m) {
                    cnt++;
                    break;
                }
            }
        }

        b_idx = 1;
        for (int i = a_idx[1] + 1; i < n; ++i) {
            if (a[i] == b[b_idx]) {
                b_idx++;
                if (b_idx == m) {
                    cnt++;
                    break;
                }
            }
        }

        if (cnt == 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
