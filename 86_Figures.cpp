#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

const double pi = 3.14;

class Figure {
public:
	virtual string Name () const = 0;
	virtual double Perimeter () const = 0;
	virtual double Area () const = 0;
};

class Triangle : public Figure {
public:
	Triangle (const int& a, const int& b, const int& c) {
		name = "TRIANGLE";
		perimeter = a+b+c;
		double p = double(a+b+c)/2 ;
		area = sqrt(p*(p-a)*(p-b)*(p-c));
	}

	virtual string Name() const override
	{
		return name;
	}

	virtual double Perimeter() const override
	{
		return perimeter;
	}

	virtual double Area() const override
	{
		return area;
	}

private:
	string name;
	double perimeter;
	double area;
};

class Rect : public Figure {
public:
	Rect (const int& a, const int& b) {
		name = "RECT";
		perimeter = 2*a+2*b;
		area = a * b;
	}

	virtual string Name() const override
	{
		return name;
	}

	virtual double Perimeter() const override
	{
		return perimeter;
	}

	virtual double Area() const override
	{
		return area;
	}

private:
	string name;
	double perimeter;
	double area;
};

class Circle : public Figure {
public:
	Circle (const int& r) {
		name = "CIRCLE";
		perimeter = double(r) * 2 * pi;
		area = double(r) * double(r) * pi;
	}

	virtual string Name() const override
	{
		return name;
	}

	virtual double Perimeter() const override
	{
		return perimeter;
	}

	virtual double Area() const override
	{
		return area;
	}

private:
	string name;
	double perimeter;
	double area;
};

shared_ptr<Figure> CreateFigure (istringstream& s)
{
	string name;
	s >> name;
	if (name == "TRIANGLE") {
		int a, b, c;
		s >> a >> b >> c;
		return make_shared<Triangle>(a, b, c);

	} else if (name == "RECT") {
		int a, b;
		s >> a >> b;
		return make_shared<Rect>(a, b);

	} else {  // TRIANGLE
 		int r;
		s >> r;
		return make_shared<Circle>(r);
	}
}


int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
