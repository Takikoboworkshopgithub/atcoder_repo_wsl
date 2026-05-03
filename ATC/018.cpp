#include <iostream>
#include <cmath>
using namespace std;

int Q;
long double T, L, X, Y, E, PI = acos(-1.0);

long double query(long double I) {
	long double a = I / T * 2 * PI;
	long double cy = -(L / 2) * sin(a);
	long double cz = (L / 2) * (1 - cos(a));
	long double d = sqrt(X * X + (Y - cy) * (Y - cy));
	return atan2(cz, d) * 180 / PI;
}

int main() {
	cin >> T >> L >> X >> Y >> Q;
	while (Q--) {
		cin >> E;
		printf("%.12Lf\n", query(E));
	}
}