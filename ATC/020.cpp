#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll A, B, C;ll E = 1;int main(){cin >> A >> B >> C;for (int i = 1; i <= B; i++)E*=C;cout << (A < E? "Yes":"No")<< endl;
}