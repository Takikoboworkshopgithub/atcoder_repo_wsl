#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define roop(n) for(int i=0;i<(int)n;i++)
#define all(v) v.begin(),v.end()
#define INF 1<<30
#define ll long long
#define sum(v) accumulate(v.begin(),v.end(),0LL)
#define sum(vec,k) accumulate(vec.begin(),vec.begin()+k,0LL)
ll n,k,a,b;
vector<ll> vec;
int main(){
  cin>>n>>k;
  rep(i,n){
    cin >> a;cin >> b;vec.push_back(b);vec.push_back(a-b);
  }
  sort(all(vec));reverse(all(vec));cout<<sum(vec,k)<<endl;
}