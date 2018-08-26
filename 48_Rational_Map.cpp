#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int GCD (const int& a, const int& b) {
	int a1 = a;
	int b1 = b;

	while (a1 > 0 & b1 > 0) {
		if (a1 > b1) {
			a1 = a1 % b1;
		} else {
			b1 = b1 % a1;
		}
	}
	return (a1 + b1);
}

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
    	num = 0;
    	den = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
    	int gcd = GCD (abs(numerator), abs(denominator));
    	num = numerator / gcd;
    	den = denominator / gcd;

    	if ((num < 0 && den > 0) || (num > 0 && den < 0)) {
    		num = -abs(num);
    		den = abs(den);
    	} else {
    		num = abs(num);
    	    den = abs(den);
    	}

    }

    int Numerator() const {
        // Реализуйте этот метод
    	return num;
    }

    int Denominator() const {
        // Реализуйте этот метод
    	return den;
    }

private:
    // Добавьте поля
    int num;
    int den;
};

// Реализуйте для класса Rational операторы ==, + и -

bool operator== (const Rational& a, const Rational& b) {
	return (a.Numerator() == b.Numerator() && a.Denominator() == b.Denominator());
}

Rational operator+ (const Rational& a, const Rational& b) {
	int num = a.Numerator()*b.Denominator() + b.Numerator()*a.Denominator();
	int den = a.Denominator() * b.Denominator();
	Rational res(num, den);
	return res;
}

Rational operator- (const Rational& a, const Rational& b) {
	int num = a.Numerator()*b.Denominator() - b.Numerator()*a.Denominator();
	int den = a.Denominator() * b.Denominator();
	Rational res(num, den);
	return res;
}

// Реализуйте для класса Rational операторы * и /

Rational operator* (const Rational& a, const Rational& b) {
	int num = a.Numerator()*b.Numerator();
	int den = a.Denominator()*b.Denominator();
	Rational res(num, den);
	return res;
}

Rational operator/ (const Rational& a, const Rational& b) {
	int num = a.Numerator()*b.Denominator();
	int den = a.Denominator()*b.Numerator();
	Rational res(num, den);
	return res;
}

// Реализуйте для класса Rational операторы << и >>

istream& operator>>(istream& stream, Rational& r) {
	int a, b;
	stream >> a;
	stream.ignore(1);
	stream >> b;
	if (stream)
		r = Rational(a,b);
	return stream;
}

ostream& operator<<(ostream& stream, const Rational& r) {
	stream << r.Numerator() << "/" << r.Denominator();
	return stream;
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

// Нужен только один дополнительный оператор - строгое сравнение ("меньше")

bool operator< (const Rational& a, const Rational& b) {
	double a1 = float(a.Numerator()) / float(a.Denominator());
	double b1 = float(b.Numerator()) / float(b.Denominator());
	//cout << a.Numerator() << " " << a.Denominator() << " " << a.Numerator() / a.Denominator() << endl;
	return (a1 < b1);
}


int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        //cout << rs.size() << endl;

        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
