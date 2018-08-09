#include <iostream>
#include <string>
using namespace std;

int main() {
	string x, y, z;
	cin >> x >> y >> z;
	if (x <= y && x <= z) {
		cout << x ;
	} else if (y <= x && y <= z) {
		cout << y;
	} else cout << z;
	return 0;
}
