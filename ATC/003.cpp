#if !__INCLUDE_LEVEL__
#include __FILE__
void solve(){
  int n;cin >> n;
  graph g(n);
  rep(i,n-1){
    int a,b;cin >> a >> b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  auto dfs = [&](int start) -> vector<int>{
    int n = g.size();
    vector<int> dist(n,-1);
    dist[start] = 0;
    deque<int> q;
    q.push_back(start);
    while(!q.empty()){
      int now = q.front();q.pop_front();
      for(auto to:g[now]){
        if(dist[to] == -1){
          dist[to] = dist[now] + 1;
          q.push_back(to);
        }
      }      
    }
    return dist;
  };
  vector<int> dist0 = dfs(0);
  int max_dist =0;
  int max_dist_idx = -1;
  rep(i,n){
    if(dist0[i] > max_dist){
      max_dist = dist0[i];
      max_dist_idx = i;
    }
  }
  dist0 = dfs(max_dist_idx);
  max_dist = -1;
  rep(i,n)chmax(max_dist,dist0[i]);
  cout << max_dist+1 << endl;
}

#undef int
int main(){
  solve();
}
#else
//include系統
#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
#include <boost/algorithm/cxx11/all_of.hpp>
using namespace std;
using namespace boost::algorithm;
#define pyint boost::multiprecision::cpp_int


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
    //小数点の場合の出力を指定する
    cout << fixed << setprecision(15);
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
template <typename T>//宣言は、v2<int> v(3, 4)か v2<int> v(3, 4, 0);
class v2 : public vector<vector<T>> {
    public:
        v2(int i, int j): vector<vector<T>>(i, vector<T>(j)) {}
        v2(int i, int j, T x): vector<vector<T>>(i, vector<T>(j, x)) {}
};
using graph = vector<vector<int>>;
#define all(v) v.begin(),v.end()
#define rall(v) (v).rbegin(), (v).rend()
#define sum(v) accumulate(v.begin(),v.end(),0LL)
#define partial_sum_k(vec,k,l) accumulate(vec.begin()+(k),vec.begin()+(l),0LL)

//pair系統
#define fi first
#define se second
#define mp make_pair

//関数系統
template<class T> bool chmax(T &a, const T &b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> bool chmin(T &a, const T &b) {
    if (a > b) { a = b; return true; }
    return false;
}
//座標圧縮
template<class T>
vector<int> compress(vector<T> &v) {
    vector<T> vals = v;
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    vector<int> res(v.size());
    for (int i = 0; i < (int)v.size(); i++) {
        res[i] = lower_bound(all(vals), v[i]) - vals.begin();
    }
    return res;
}
//累積和
template<class T>
vector<T> cumsum(const vector<T> &v) {
    vector<T> s(v.size()+1);
    for (size_t i = 0; i < v.size(); i++) s[i+1] = s[i] + v[i];
    return s;
}

//文字系統
bool is_digit(char c) { return '0' <= c && c <= '9'; }
bool is_lower(char c) { return 'a' <= c && c <= 'z'; }
bool is_upper(char c) { return 'A' <= c && c <= 'Z'; }
template<class T>


#define gcd __gcd
#define lcm(x, y) x / gcd(x, y) * y

//入出力系統
#define YN(ans) if(ans)cout<<"Yes"<<endl;else cout<<"No"<<endl;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define debug(x) cerr << #x << " : " << (x) << endl

//boost系統
/*
all_of(v.begin(), v.end(), [](int x){return x % 2 == 0;})
any_of(v.begin(), v.end(), [](int x){return x % 2 == 0;})
copy_if(v.begin(), v.end(), v.begin(), [](int x){return x % 2 == 0;})
copy_n(v.begin(), 3, v.begin())
*/
//値系統
#define INF (1<<30)
#define int long long
#define uint unsigned long long
#define ll long long
#define intint __int128
#define ld long double
const double pi = acos(-1.0);
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";
const string digits = "0123456789";
#define MOD1 1000000007
#define MOD9 998244353
using mint1 = atcoder::modint1000000007;
using mint9 = atcoder::modint998244353;
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