#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
ll n,k;
ll min_act = 0;
int main(){
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    ll b;
    cin >> b;
    min_act += abs(a[i] - b);
  }
  bool ans = true;
  if (min_act > k){
    ans = false;
  }
  if ((k - min_act) % 2 != 0){
    ans = false;
  }
  cout << (ans ? "Yes" : "No") << endl;
}