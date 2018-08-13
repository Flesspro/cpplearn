#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Incognizable {
	Incognizable (){
		data1 = 0;
		data2 = 0;
	}
	Incognizable (int a) {
		data1 = a;
		data2 = 0;
	}
	Incognizable (int a, int b) {
		data1 = a;
		data2 = b;
	}
	int data1, data2;
};


//int main() {
//  Incognizable a;
//  Incognizable b = {};
//  Incognizable c = {0};
//  Incognizable d = {0, 1};
//  return 0;
//}
