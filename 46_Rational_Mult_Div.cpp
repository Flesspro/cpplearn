#include <iostream>
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

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
