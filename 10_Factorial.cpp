#include <iostream>
#include <vector>
using namespace std;

int Factorial (int A) {
	if (A <= 0) {
		return(1);
	}
	int res = 1;
	for (int i = 1; i <= A; ++i) {
		res *= i;
	}
	return (res);
}

int main() {
	int A;
	cin >> A;
	cout << Factorial(A);

	return 0;
}
