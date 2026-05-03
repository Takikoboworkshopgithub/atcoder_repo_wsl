#include<bits/stdc++.h>
using namespace std;
int n;
set<string> a;
int main(){
  cin >> n;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    int tmp = a.size();
    a.insert(s);
    if(tmp != a.size()){
      cout << i + 1 << endl;
    }
  }
}