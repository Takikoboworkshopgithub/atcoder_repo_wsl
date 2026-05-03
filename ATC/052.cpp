#if !__INCLUDE_LEVEL__
#include __FILE__
int main(){
  int n;
  cin >> n;
  ll ans = 1;
  rep(i,n){
    vector<int> a(6);
    rep(j,6){
      cin >> a[j];
    }
    ans *= sumall(a);
    ans %= (int)1e9+7;
  }
  cout << ans << endl;
}
#else

#include<bits/stdc++.h>
using namespace std;

#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

// ここからは __INCLUDE_LEVEL__ が 1 以上（再読み込み後）だけに通る

struct Init {
  Init() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }
} init;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define roop(n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF (1<<30)
#define ll long long
#define ull unsigned long long
#define sumall(v) accumulate(v.begin(),v.end(),0LL)
#define partial_sum_k(vec,k) accumulate(vec.begin(),vec.begin()+(k),0LL)
#define io(ans) if(ans)cout<<"Yes"<<endl;else cout<<"No"<<endl;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

const double pi = acos(-1.0);
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";
const string digits = "0123456789";

#endif