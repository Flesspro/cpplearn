#include <iostream>
using namespace std;

// Euclid's algorithm

int main() {
	int A, B;
	cin >> A >> B;
	while (A > 0 & B > 0) {
		if (A > B) {
			A = A % B;
		} else {
			B = B % A;
		}
	}
	if (B == 0) {
		cout << A;
	} else {
		cout << B;
	}

	return 0;
}
