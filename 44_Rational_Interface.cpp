#include <iostream>
#include <algorithm>
using namespace std;

int GCD (const int& a, const int& b) {
	if (a*b == 0) {
		return (a+b);
	} else if (a > b) {
		return GCD (a%b, b);
	} else
		return GCD (b%a, a);
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

    	if (num*den < 0) {
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

int main() {
	{
		const Rational r(-4, -5);
		cout << r.Numerator() << "/" << r.Denominator() << endl;

	}


    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
