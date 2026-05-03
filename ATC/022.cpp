#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll a,b,c;
  cin >> a >> b >> c;
  ll g = gcd(a, b);
  g = gcd(g, c);
  ll ans = a/g + b/g + c/g;
  cout << ans - 3 << endl;
}