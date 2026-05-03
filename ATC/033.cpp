#include<bits/stdc++.h>
using namespace std;int h,w;int main(){cin>>h>>w;if(h==1 || w==1){cout<<h*w<<endl;return 0;}h++;w++;cout<<(h/2)*(w/2)<< endl;}