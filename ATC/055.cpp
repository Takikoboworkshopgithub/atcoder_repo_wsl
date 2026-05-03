#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n;
    ll p, q;
    cin >> n >> p >> q;
    vector<ll> a(n);
    for (int i=0;i<n;i++)cin>>a[i];
    ll ans=0;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++)for(int l=k+1;l<n;l++)for(int m=l+1;m<n;m++){
      ll prod = 1;
      prod=a[i]%p*a[j]%p*a[k]%p*a[l]%p*a[m]%p;
      if(prod==q)ans++;
    }
    cout << ans << endl;
    return 0;
}