#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
int n,m;
int q;
int main(){
  cin >> n;
  vector<int> a(n);
  rep(i,n)cin >> a[i];
  sort(all(a));
  cin >> q;
  while(q--){
    int b;
    cin >> b;
    int j = lower_bound(all(a),b) - a.begin();
    int ans = 1<< 30;
    if(j < n)ans = min(ans,abs(a[j]-b));
    if(j > 0)ans = min(ans,abs(a[j-1]-b));
    cout << ans << endl;
  }
}