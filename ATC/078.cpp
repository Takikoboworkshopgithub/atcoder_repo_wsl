#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
vector<int> graph[100000];
int main(){
  cin >> n >> m;
  while(m--){
    int a,b;
    cin >> a >> b;
    a--;b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for(int j=0;j<graph[i].size();j++){
      if(graph[i][j] < i){
        cnt++;
      }
    }
    ans += cnt==1;
  }
  cout << ans << endl;
}