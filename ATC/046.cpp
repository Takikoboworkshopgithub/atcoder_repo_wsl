#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define roop(n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
vector<ll> a(46,0);
vector<ll> b(46,0);
vector<ll> c(46,0);
int n;
int main(){
  //std::ios_base::sync_with_stdio(false);
  //std::cin.tie(NULL);
  cin >> n;
  int tmp;
  roop(n){
    cin >> tmp;aaa
    a[tmp%46]++;
  }
  roop(n){
    cin >> tmp;
    b[tmp%46]++;
  }
  roop(n){
    cin >> tmp;
    c[tmp%46]++;
  }
  ll ans = 0;
  rep(i,46)rep(j,46)rep(k,46){
    if((i+j+k)%46 == 0)ans+=a[i]*b[j]*c[k];
  }
  cout << ans << endl;
}