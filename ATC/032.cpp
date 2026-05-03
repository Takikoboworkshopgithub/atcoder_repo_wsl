#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define roop(n) for(int i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
int n,m;
int INF = 1<<30;
int main(){
  cin >> n;
  vector<vector<int>> a(n,vector<int>(n));
  rep(i,n)rep(j,n)cin >> a[i][j];
  cin >> m;
  vector<vector<int>> dislike(n,vector<int>(n,0));
  roop(m){
    int x,y;
    cin >> x >> y;
    x--;y--;
    dislike[x][y] = 1;
    dislike[y][x] = 1;
  }
  vector<int> v(n);
  rep(i,n)v[i] = i;
  int ans = INF;
  do{
    bool ok = true;
    int sum = 0;
    for(int i=0;i<n-1;i++){
      if(dislike[v[i]][v[i+1]] == 1){
        ok = false;
        break;
      }
      sum += a[v[i]][i];
    }
    if(ok){
      sum += a[v[n-1]][n-1];
      ans = min(ans,sum);
    }

  }while(next_permutation(v.begin(),v.end()));
  if(ans == INF)ans = -1;
  cout << ans << endl;
}