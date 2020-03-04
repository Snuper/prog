#include <iostream>
#include <fstream>
#include <vector>

class Fraction {
	int num;
	int den;
public:
	Fraction(int n, int d = 1): num(n), den(d) {
	}
	Fraction(): num(0), den(1){
	}
	Fraction operator+ (Fraction right) {
		return Fraction(this->num * right.den + right.num * this->den, this->den * right.den);
	}
	void operator=(Fraction right) {
		this->num = right.num;
		this->den = right.den;
	}
	void operator=(int right) {
		this->num = right;
		this->den = 1;
	}
	Fraction operator*(Fraction right) {
		return Fraction(this->num * right.num, this->den * right.den);
	}
	Fraction operator/(Fraction right) {
		return Fraction(this->num * right.den, this->den * right.num);
	}
	Fraction operator-(Fraction right) {
		return Fraction(this->num * right.den - right.num * this->den, this->den * right.den);
	}
	bool operator==(Fraction right) {
		return this->num == right.num;
	}
	bool operator<(Fraction right) {
		return this->num * right.den < right.num * this->den; 
	}
	friend std::ostream &operator<<(std::ostream &out, Fraction right) {
		out << right.num << "/" << right.den;
		return out;
	}
};

template <class T>
class Matrix {
	T **matrix;
	T *X;
	int numb;
	std::ifstream fin;
	std::ofstream fout;
	int checkCorrectFile() {
		std::string str;
		std::vector<std::string> words;
		int n_col = 0;
		int n_line = 0;
		for(n_line = 0; getline(fin, str); n_line++) {
			if(str.size() == 0) return 0;
			words = getWords(str);
			if(n_col) {
				if(n_col != words.size()) {
					return 0;
				}
			} else {
				n_col = words.size();
			}
 		}
 		if(n_col - 1 != n_line) {
 			return 0;
 		}
 		return n_line;
	}
	std::vector<std::string> getWords(std::string str) {
		std::vector<std::string> words;
		std::string word;
		for(std::string::iterator i = str.begin(); i != str.end(); i++) {
			if(*i == ' ') {
				i++;
				words.push_back(word);
				word.clear();
			}
			word += *i;
		}
		words.push_back(word);
		return words;
	}
	T abs(T x) {
		if (x < T(0)) {
			return -x;
		}
		return x;
	}
public:
	Matrix() {
		numb = 0;
	}
	int inputNumb(int n) {
		if(numb >= 0) {
			numb = n;
			return 1;
		}
		std::cout << "Размерность матрицы не может быть отрицательной" << std::endl;
		return 0;
	}
	int readFile(const char *file_name) {
		fin.open(file_name);
		if (!fin.is_open()) {
			std::cout << "Файла " << file_name << " не существует" << std::endl;
			return 0;
		}
		if (numb == 0) {
			numb = checkCorrectFile();
			if(!numb) {
				std::cout << "Некорректные входные данные" << std::endl;
				return 0;
			}
		}
		fin.close();
		fin.open(file_name);
		X = new T[numb];
		matrix = new T*[numb];
		for(int i = 0; i < numb; i++) {
			matrix[i] = new T[numb + 1];
		}
		int cell;
		for(int i = 0; i < numb; i++) {
			for(int j = 0; j < numb + 1; j++) {
				fin >> cell;
				matrix[i][j] = cell;
			}
		}
		fin.close();
		return 1;
	}
	int writeResult(const char *file_name) {
		fout.open(file_name);
		if(!fout.is_open()) {
			std::cout << "Файла " << file_name << " не существует" << std::endl;
			return 0;
		}
		for(int i = 0; i < numb; i++) {
			fout << X[i] << std::endl;
		}
		fout.close();
		return 1;
	}
	void printMatrix() {
		for(int i = 0; i < numb; i++) {
			for(int j = 0; j < numb + 1; j++) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	void printResult() {
		for(int i = 0; i < numb; i++) {
			std::cout << "x" << i + 1 << " = " << X[i] << std::endl;
		}
	}
	void calculationGaussMethod() {	
		T *buff = NULL;
		T mult = 0;
		for(int i = 0; i < numb - 1; i++) {
			for(int j = i + 1; j < numb; j++) {
				if(matrix[i][i] == T(0)) {
					for(int k = j; k < numb; k++) {
						if(!(matrix[k][i] == T(0))) {
							buff = matrix[k];
							matrix[k] = matrix[i];
							matrix[i] = buff;
						}
					}
				}
				mult = matrix[j][i] / matrix[i][i];
				for(int k = 0; k < numb + 1; k++) {
					matrix[j][k] = matrix[j][k] - matrix[i][k] * mult;
				}
			}
		}
		for(int i = numb - 1; i >= 0; i--) {
			for(int j = i + 1; j < numb; j++) {
				matrix[i][numb] = matrix[i][numb] - matrix[i][j] * X[j];
			}
			X[i] = matrix[i][numb] / matrix[i][i];
		}
	}

	void calculationUpgradeGaussMethod() {	
		T *buff = NULL;
		T mult = 0;
		int k_1 = 0;
		for(int i = 0; i < numb - 1; i++) {
			mult = i;
			for(int k = i+1; k < numb; k++) {
				if(abs(matrix[i][i]) < abs(matrix[k][i])) {
					k_1 = k;
				}
			}
			if (k_1 != i) {
				buff = matrix[k_1];
				matrix[k_1] = matrix[i];
				matrix[i] = buff;
			}
			for(int j = i + 1; j < numb; j++) {
				mult = matrix[j][i] / matrix[i][i];
				for(int k = 0; k < numb + 1; k++) {
					matrix[j][k] = matrix[j][k] - matrix[i][k] * mult;
				}
			}
		}
		for(int i = numb - 1; i >= 0; i--) {
			for(int j = i + 1; j < numb; j++) {
				matrix[i][numb] = matrix[i][numb] - matrix[i][j] * X[j];
			}
			X[i] = matrix[i][numb] / matrix[i][i];
		}
	}
};

int main(int argc, char **argv) {
	Matrix<float> matrix;
	matrix.inputNumb(0);
	std::string file;
	// std::cout << "Введите имя файла: ";
	// std::cin >> file;
	matrix.readFile("test.txt");
	// matrix.calculationGaussMethod();
	matrix.calculationUpgradeGaussMethod();
	matrix.writeResult("test_result.txt");
	matrix.printResult();
}