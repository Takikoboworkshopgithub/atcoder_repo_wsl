#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ull unsigned long long
// 多倍長テンプレ
/* ---------------------- ここから ---------------------- */
# include <boost/multiprecision/cpp_dec_float.hpp>
# include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */
Bint a,b,ans;
int main(){
  cin >> a >> b;
  ans = a*b/gcd(a,b);
  cout << (ans >pow(10,18)? "Large" : to_string(ans)) << endl;
}