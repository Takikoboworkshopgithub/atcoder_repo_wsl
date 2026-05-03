#if !__INCLUDE_LEVEL__
#include __FILE__
int solve(){
  int n;cin >> n;
  string s;cin >> s;
  vector<int> RLE;
  int IsO = -1;
  rep(i,n){
    if(s[i] == 'o'){
      if(IsO != 1){
        IsO = 1;
        RLE.push_back(1);
      }
      else{
        RLE.back()++;
      }
    }
    if(s[i] == 'x'){
      if(IsO != 0){
        IsO = 0;
        RLE.push_back(1);
      }
      else{
        RLE.back()++;
      }
    }
  }
    ll ans = 1ll*n*(n+1)/2;
    rep(i,RLE.size()){
      ans -= 1ll*(RLE[i]+1)*RLE[i]/2;
    }
    cout << ans << endl;
  return 0;
}
#undef int
int main(){
  solve();
}


#else

#include<bits/stdc++.h>
using namespace std;

#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
// ここからは __INCLUDE_LEVEL__ が 1 以上（再読み込み後）だけに通る

//C++の高速化
struct Init {
  Init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} init;
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//for文系統
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define roop(n) for(int i=0;i<(int)(n);i++)
#define rangerep(i,n,m) for(int i=n;i<(int)(m);i++)
#define rangeroop(n,m) for(int i=n;i<(int)(m);i++)
#define arrroop(arr) for(int i=0;i<(int)(arr).size();i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define foreach(it, container) for (auto it = (container).begin(); it != (container).end(); ++it)
//vector系統
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
template <typename T>//宣言は、vect<int> v(3, 4)か vect<int> v(3, 4, 0);
class vect : public vector<vector<T>> {
    public:
        vect(int i, int j): vector<vector<T>>(i, vector<T>(j)) {}
        vect(int i, int j, T x): vector<vector<T>>(i, vector<T>(j, x)) {}
};
#define all(v) v.begin(),v.end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF (1<<30)
#define iint int
#define ll long long
#define int long long
#define ull unsigned long long
#define sumall(v) accumulate(v.begin(),v.end(),0LL)
#define partial_sum_k(vec,k,l) accumulate(vec.begin()+(k),vec.begin()+(l),0LL)
//入出力系統
#define YN(ans) if(ans)cout<<"Yes"<<endl;else cout<<"No"<<endl;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define debug(x) cerr << #x << " : " << (x) << endl

//値系統
const double pi = acos(-1.0);
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";
const string digits = "0123456789";
#define MOD 1000000007
#define MOD1 998244353
int keta(ll x) {
    int res = 0;
    while (x > 0) {
        res++;
        x /= 10;
    }
    return res;
}
ll powll(ll x,ll n){
  ll ret = 1;
  while(n > 0){
    if(n & 1){
      ret *= x;
    }
    x *= x;
    n >>= 1;
  }
  return ret;

}
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
ll inv(ll a, ll mod) {
    return modpow(a, mod - 2, mod);
}
#endif