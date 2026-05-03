#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)


template <typename T>
class v2 : public vector<vector<T>> {
public:
    v2(int i, int j): vector<vector<T>>(i, vector<T>(j)) {}
    v2(int i, int j, T x): vector<vector<T>>(i, vector<T>(j, x)) {}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    v2<int> paper(1003, 1003, 0);

    rep(i,n){
        int lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry;
        paper[lx][ly]++;
        paper[lx][ry]--;
        paper[rx][ly]--;
        paper[rx][ry]++;
    }

    for (int i = 0; i <= 1002; i++) {
        for (int j = 0; j < 1002; j++) {
            paper[i][j+1] += paper[i][j];
        }
    }
    for (int i = 0; i < 1002; i++) {
        for (int j = 0; j <= 1002; j++) {
            paper[i+1][j] += paper[i][j];
        }
    }

    vector<int> ans(n+1,0);
    for (int i = 0; i <= 1002; i++) {
        for (int j = 0; j <= 1002; j++) {
            if (paper[i][j] >= 1 && paper[i][j] <= n) {
                ans[paper[i][j]]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
}
