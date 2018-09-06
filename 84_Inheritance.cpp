#include <iostream>

using namespace std;

class Animal {
public:
    Animal(const string& t = "animal")
		: Name(t) {
    }

    const string Name;
};

class Dog : public Animal {
public:
    Dog(const string& name) : Animal(name) {
    }

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

//int main () {
//	Dog d("Rex");
//	cout << d.Name;
//}
