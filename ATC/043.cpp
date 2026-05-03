#if !__INCLUDE_LEVEL__
#include __FILE__
struct Pos{
    int x, y;
};

enum Dir{LEFT, RIGHT, UP, DOWN, NONE};

struct State{
    int x, y;
    Dir d;
    int cost;
};
int zerooneBFS(Pos start, Pos goal, vector<string>& field){
    int h = field.size(), w = field[0].size();
    vector<vector<int>> dist(h, vector<int>(w, INT_MAX));
    deque<State> dq;

    dq.push_back({start.x, start.y, NONE, 0});
    dist[start.x][start.y] = 0;

    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};

    while(!dq.empty()){
        auto cur = dq.front(); dq.pop_front();
        if(cur.x == goal.x && cur.y == goal.y) return cur.cost;

        for(int k=0;k<4;k++){
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];
            if(nx<0||nx>=h||ny<0||ny>=w) continue;
            if(field[nx][ny] == '#') continue;

            int add = (cur.d==NONE || cur.d==k) ? 0 : 1;
            if(dist[nx][ny] > cur.cost + add){
                dist[nx][ny] = cur.cost + add;
                State next = {nx, ny, (Dir)k, cur.cost + add};
                if(add==0) dq.push_front(next);
                else dq.push_back(next);
            }
        }
    }
    return -1;
}

void solve(){
int h, w;
cin >> h >> w;
Pos start, end;
cin >> start.x >> start.y >> end.x >> end.y;
start.x--; start.y--; end.x--; end.y--;
vector<string> field(h);
roop(h) cin >> field[i];
cout << zerooneBFS(start, end, field) << endl;
}

#undef int
int main(){
  solve();
}
/*
             ________________________________________________
            /                                                \
           |    _________________________________________     |
           |   |                                         |    |
           |   |  C:\> ls -R                             |    |
           |   |     admin/                              |    |
           |   |       ├ welcome/                        |    |
           |   |       ├ to/                             |    |
           |   |       ├ my/                             |    |
           |   |       │  └ coding_space                 |    |
           |   |       └ feel free when copin'           |    |
           |   |                                         |    |
           |   |  C:\> _                                 |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |_________________________________________|    |
           |                                                  |
            \_________________________________________________/
                   \___________________________________/
                ___________________________________________
             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_
          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_
       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_
    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_
 _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_
:-------------------------------------------------------------------------:
`---._.-------------------------------------------------------------._.---'
*/
#else
//include系統
#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
#include <boost/algorithm/cxx11/all_of.hpp>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost::algorithm;
#define pyint boost::multiprecision::cpp_int


#if __has_include(<atcoder/all>)
//#include <atcoder/all> 重いから普段使いしないように
#include <atcoder/modint>
#include <atcoder/dsu> 
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
#define minv(v) *min_element(all(v))            // 最小値取得
#define maxv(v) *max_element(all(v))            // 最大値取得
#define pb push_back
#define eb emplace_back
#define rev(v) reverse(all(v))
/*Python風に書く
Py<deque<int>> dq;
Py<vector<int>> v;
Py<deque<tuple<int,int>>> dqt;
Py<vector<vector<int>>> vv;
*/
template <typename Container>
struct Py {
    Container c;

    Py() = default;
    Py(Container cont) : c(cont) {}

    // 後ろに追加
    template <typename... Args>
    void append(Args&&... args) {
        if constexpr (is_same_v<Container, deque<tuple<Args...>>> || is_same_v<Container, vector<tuple<Args...>>>) {
            c.push_back(make_tuple(forward<Args>(args)...));
        } else if constexpr (is_same_v<Container, deque<typename Container::value_type>> || is_same_v<Container, vector<typename Container::value_type>>) {
            if constexpr (sizeof...(args) == 1)
                c.push_back(forward<Args>(args)...);
            else
                c.push_back(vector{forward<Args>(args)...}); // vector<int>などの生成
        }
    }

    // 前に追加
    template <typename... Args>
    void appendleft(Args&&... args) {
        if constexpr (is_same_v<Container, deque<tuple<Args...>>>) {
            c.push_front(make_tuple(forward<Args>(args)...));
        } else if constexpr (is_same_v<Container, deque<typename Container::value_type>>) {
            if constexpr (sizeof...(args) == 1)
                c.push_front(forward<Args>(args)...);
            else
                c.insert(c.begin(), vector{forward<Args>(args)...});
        } else if constexpr (is_same_v<Container, vector<typename Container::value_type>>) {
            if constexpr (sizeof...(args) == 1)
                c.insert(c.begin(), forward<Args>(args)...);
            else
                c.insert(c.begin(), vector{forward<Args>(args)...});
        }
    }

    // 後ろから取り出す
    auto pop() {
        if constexpr (is_same_v<Container, deque<typename Container::value_type>> || is_same_v<Container, vector<typename Container::value_type>>) {
            auto val = c.back();
            c.pop_back();
            return val;
        }
    }

    // 前から取り出す
    auto popleft() {
        if constexpr (is_same_v<Container, deque<typename Container::value_type>>) {
            auto val = c.front();
            c.pop_front();
            return val;
        } else if constexpr (is_same_v<Container, vector<typename Container::value_type>>) {
            auto val = c.front();
            c.erase(c.begin());
            return val;
        }
    }

    size_t len() const { return c.size(); }
};


//pair系統
#define fi first
#define se second
#define mp make_pair

//dict系統
#define items(m) for (auto &[k, v] : m)
#define keys(m) for (auto &k : m)
#define values(m) for (auto &[_, v] : m)

template <typename T>
struct enumerate_wrapper {
    T &container;
    struct iterator {
        size_t i;
        decltype(std::begin(container)) iter;
        bool operator!=(const iterator &other) const { return iter != other.iter; }
        void operator++() { ++i; ++iter; }
        auto operator*() const { return std::pair<size_t, decltype(*iter)>(i, *iter); }
    };
    iterator begin() { return {0, std::begin(container)}; }
    iterator end() { return {0, std::end(container)}; }
};

template <typename T>
auto enumerate(T &container) {
    return enumerate_wrapper<T>{container};
}

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
vector<T> accumlated(const vector<T> &v) {
    vector<T> s(v.size()+1);
    for (size_t i = 0; i < v.size(); i++) s[i+1] = s[i] + v[i];
    return s;
}

//文字系統
bool is_digit(char c) { return '0' <= c && c <= '9'; }
bool is_lower(char c) { return 'a' <= c && c <= 'z'; }
bool is_upper(char c) { return 'A' <= c && c <= 'Z'; }


#define gcd __gcd
#define lcm(x, y) x / gcd(x, y) * y

//入出力系統
#define YN(ans) if(ans)cout<<"Yes"<<endl;else cout<<"No"<<endl;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define debug(x) cerr << #x << " : " << (x) << endl
template<typename T>
void li(std::vector<T>& v) {
    for(auto& x : v) std::cin >> x;
}
template<typename T>
void lli(std::vector<std::vector<T>>& vv) {
    for(auto& v : vv) li(v);
}
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
#define AC、お願いしまぁぁぁぁぁぁぁぁす。【Ｅｎｔｅｒ】
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

/*
                       .,,uod8B8bou,,.
              ..,uod8BBBBBBBBBBBBBBBBRPFT?l!i:.
         ,=m8BBBBBBBBBBBBBBBRPFT?!||||||||||||||
         !...:!TVBBBRPFT||||||||||!!^^""'   ||||
         !.......:!?|||||!!^^""'            ||||
         !.........||||                     ||||
         !.........||||  ##                 ||||
         !.........||||                     ||||
         !.........||||                     ||||
         !.........||||                     ||||
         !.........||||                     ||||
         `.........||||                    ,||||
          .;.......||||               _.-!!|||||
   .,uodWBBBBb.....||||       _.-!!|||||||||!:'
!YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb....
!..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   `.
!....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     `.
!......YBBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^"`;:::       `.
!........YBBBBBBBBBBRPFT?!::::::::::^''...::::::;         iBBbo.
`..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo.
  `..........:::::::::::::::::::::::;iof688888888888b.     `YBBBP^'
    `........::::::::::::::::;iof688888888888888888888b.     `
      `......:::::::::;iof688888888888888888888888888888b.
        `....:::;iof688888888888888888888888888888888899fT!
          `..::!8888888888888888888888888888888899fT|!^"'
            `' !!988888888888888888888888899fT|!^"'
                `!!8888888888888888899fT|!^"'
                  `!988888888899fT|!^"'
                    `!9899fT|!^"'
                      `!^"' 





                            ____
        ____....----''''````    |.
,'''````            ____....----; '.
| __....----''''````         .-.`'. '.
|.-.                .....    | |   '. '.
`| |        ..:::::::::::::::| |   .-;. |
 | |`'-;-::::::::::::::::::::| |,,.| |-='
 | |   | ::::::::::::::::::::| |   | |
 | |   | :::::::::::::::;;;;;| |   | |
 | |   | :::::::::;;;2KY2KY2Y| |   | |
 | |   | :::::;;Y2KY2KY2KY2KY| |   | |
 | |   | :::;Y2Y2KY2KY2KY2KY2| |   | |
 | |   | :;Y2KY2KY2KY2KY2K+++| |   | |
 | |   | |;2KY2KY2KY2++++++++| |   | |
 | |   | | ;++++++++++++++++;| |   | |
 | |   | |  ;++++++++++++++;.| |   | |
 | |   | |   :++++++++++++:  | |   | |
 | |   | |    .:++++++++;.   | |   | |
 | |   | |       .:;+:..     | |   | |
 | |   | |         ;;        | |   | |
 | |   | |      .,:+;:,.     | |   | |
 | |   | |    .::::;+::::,   | |   | |
 | |   | |   ::::::;;::::::. | |   | |
 | |   | |  :::::::+;:::::::.| |   | |
 | |   | | ::::::::;;::::::::| |   | |
 | |   | |:::::::::+:::::::::| |   | |
 | |   | |:::::::::+:::::::::| |   | |
 | |   | ::::::::;+++;:::::::| |   | |
 | |   | :::::::;+++++;::::::| |   | |
 | |   | ::::::;+++++++;:::::| |   | |
 | |   |.:::::;+++++++++;::::| |   | |
 | | ,`':::::;+++++++++++;:::| |'"-| |-..
 | |'   ::::;+++++++++++++;::| |   '-' ,|
 | |    ::::;++++++++++++++;:| |     .' |
,;-'_   `-._===++++++++++_.-'| |   .'  .'
|    ````'''----....___-'    '-' .'  .'
'---....____           ````'''--;  ,'
            ````''''----....____|.'
*/