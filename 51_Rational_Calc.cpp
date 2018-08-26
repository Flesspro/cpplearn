#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stdexcept>
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

    	if (denominator == 0) {
    		throw invalid_argument("Invalid argument");
    	}

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

	if (den == 0) {
		throw domain_error("Division by zero");
	}

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
	Rational a, b, res;
	char opn;
	try {
		cin >> a >> opn >> b;
		//cout << "opn =" << opn <<".";
		switch (opn) {
			case '+': res = a + b; break;
			case '-': res = a - b; break;
			case '*': res = a * b; break;
			case '/': res = a / b; break;
		}
		cout << res;


	} catch (invalid_argument& e) {
		cout << e.what();
	} catch (domain_error& e) {
		cout << e.what();
	}




    return 0;
}
