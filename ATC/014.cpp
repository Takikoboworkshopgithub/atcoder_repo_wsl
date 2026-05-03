#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
int n;
int main(){
  cin >> n;
  vector<int> a(n),b(n);
  rep(i,n)cin >> a[i];
  rep(i,n)cin >> b[i];
  sort(all(a));
  sort(all(b));
  ll ans = 0;
  for(int i=0;i<n;i++){
    ans += abs(a[i] - b[i]);
  }
  cout << ans << endl;
}