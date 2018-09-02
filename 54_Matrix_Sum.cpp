#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix

class Matrix {
public:
	Matrix() {
		nrows = 0;
		ncols = 0;
    }

	Matrix (const int& n, const int& m) {
		Reset (n, m);
	}

	void Reset (const int& n, const int& m) {
		if (n < 0 || m < 0) {
			throw out_of_range("");
		}
		nrows = n;
		ncols = m;
		data.assign(n, vector<int>(m));
	}

	int& At (const int& i, const int& j) {
		if (i < 0 || j < 0 || i > nrows-1 || j > ncols-1) {
			throw out_of_range("");
		}
		return data.at(i).at(j);
	}

	int At (const int& i, const int& j) const {
		if (i < 0 || j < 0 || i > nrows-1 || j > ncols-1) {
			throw out_of_range("");
		}
		return data.at(i).at(j);
	}

	int GetNumRows () const {
		return nrows;
	}

	int GetNumColumns () const {
		return ncols;
	}


private:
    int nrows;
    int ncols;
    vector<vector<int>> data;
};

// * оператор ввода для класса Matrix из потока istream

istream& operator>> (istream& stream, Matrix& Mat) {
	int n, m;
	stream >> n >> m;
	Mat.Reset (n,m);

	for (int i = 0; i < Mat.GetNumRows(); i++) {
		for (int j = 0; j < Mat.GetNumColumns(); j++) {
			stream >> Mat.At(i,j);

		}
	}

	return stream;
}


// * оператор вывода класса Matrix в поток ostream
ostream& operator<< (ostream& stream, const Matrix& Mat) {
	stream << Mat.GetNumRows() << " " << Mat.GetNumColumns() << endl;

	for (int i = 0; i < Mat.GetNumRows(); ++i) {
		for (int j = 0; j < Mat.GetNumColumns(); ++j) {
			stream << Mat.At(i, j) << " ";
		}
		stream << endl;
	}

	return stream;
}


// * оператор проверки на равенство двух объектов класса Matrix
bool operator== (const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns()) {
		return false;
	}

	for (int i = 0; i < lhs.GetNumRows(); ++i) {
		for (int j = 0; j <lhs.GetNumColumns(); ++j) {
			if (lhs.At(i,j) != rhs.At(i,j)) {
				return false;
			}
		}
	}

	return true;
}

// * оператор сложения двух объектов класса Matrix
Matrix operator+ (const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns() ) {
		throw invalid_argument("");
	}

	//cout << lhs.GetNumRows() << " " << lhs.GetNumColumns();

	Matrix res(lhs.GetNumRows(), lhs.GetNumColumns());

	for (int i = 0; i < lhs.GetNumRows(); ++i) {
		//cout << "i = " << i << endl;
		for (int j = 0; j <lhs.GetNumColumns(); ++j) {
			//cout << "j = " << j << "; ";
			res.At(i,j) = lhs.At(i,j) + rhs.At(i,j);
		}
	}

	return res;
}


int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;

  cout << one + two << endl;
  return 0;
}
