#include<bits/stdc++.h>
using namespace std;
#define ll long long
deque<int> q;
int a;
int main(){
  cin >> a;
  while(a--){
    int t,x;
    cin >> t >> x;
    if(t==1){
      q.push_front(x);
    }
    else if(t==2){
      q.push_back(x);
    }
    else{
      cout << q[x-1] << endl;
    }
  }
}