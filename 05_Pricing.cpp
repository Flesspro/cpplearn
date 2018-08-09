#include <iostream>
using namespace std;

int main() {
	double N, A, B, X, Y, disct ;
	cin >> N >> A >> B >> X >> Y;
	disct = 0;

	if (N > B) {
		disct = Y;
	} else
		if (N > A) {
			disct = X;
		}

	cout << N * (100-disct)/100;

	return 0;
}
