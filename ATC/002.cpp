#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
void dfs(string s, int depth){
  if(depth == 0){
    int pre = 0;
    rep(i,s.size()){
      if(s[i] == '('){
        pre++;
      }
      else{
        pre--;
      }
      if(pre < 0){
        return;
      }
    }
    if(pre == 0){
      cout << s << endl;
    }
  }
  else{
    dfs(s + "(", depth - 1);
    dfs(s + ")", depth - 1);
  }
}
int main(){
  int n;
  cin >> n;
  dfs("", n);
  return 0;
}