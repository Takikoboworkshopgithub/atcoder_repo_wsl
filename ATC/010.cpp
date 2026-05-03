#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(2, 0));
  for(int i=0;i<n;i++){
    int c,p;
    cin >> c >> p;
    a[i][c-1]=p;
  }
  for(int i=0;i<n-1;i++){
    a[i+1][0] += a[i][0];
    a[i+1][1] += a[i][1];
  }
  int q;
  cin >> q;
  while(q--){
    int l,r;
    cin >> l >> r;
    l-=2;
    l=max(l, 0);
    r-=1;
    cout << a[r][0] - a[l][0] << " " << a[r][1] - a[l][1] << endl;
  }
  cout << "\n\n\n";
  for(int i=0;i<n;i++){
    //cout << a[i][0] << " " << a[i][1] << endl;
  }
  return 0;
}