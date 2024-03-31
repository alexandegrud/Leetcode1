#include <iostream>
using namespace std;


class Complex {
public:
	double re, im; 

	Complex() = default; 

	Complex(double r) {
		re = r;
		im = 0;
	}

	Complex(double r, double i) {
		re = r;
		im = i;
	}

	~Complex() {};
   
	Complex operator +(const Complex& other) {
		Complex temp;
		temp.re = re + other.re;
		temp.im = im + other.im;
		return temp;
	}

	Complex operator -(const Complex& other) {
		Complex temp;
		temp.re = re - other.re;
		temp.im = im - other.im;
		return temp;
	}

	Complex operator *(const Complex& other) {
		Complex temp;
		temp.re = re * other.re;
		temp.im = im * other.im;
		return temp;
	}

	Complex operator /(const Complex& other) {
		Complex temp; 

		double r = other.re * other.re + other.im * other.im;
		temp.re = (re * other.re + im * other.im) / r;
		temp.im = (im * other.re - re * other.im) / r; 
		return temp; 
	}

	bool operator ==(const Complex& other) {
		if (re != other.re || im != other.im) {
			return false; 
		}
		else {
			return true;
		}
	}

	bool operator !=(const Complex& other) {
		if (re != other.re || im != other.im) {
			return true;
		}
		else {
			return false; 
		}
	}

	void print() {
		cout << "(" << re << ") + (" << im << ")I" << endl;
	}
};

void Sum() {
	cout << "Sum:" << endl;
	Complex a(2, 1);
	Complex b(3, 2);

	Complex c = a + b;
	c.print();
}

void SumOnlyinteger() {
	cout << "Only Integer part:" << endl;
	Complex a(2);
	Complex b(3, 2);

	Complex c = a + b;
	c.print();
}

void Minus() {
	cout << "Minus:" << endl;
	Complex a(5, 7);
	Complex b(4, 2);

	Complex c = a - b;
	c.print();
}

void Multiply() {
	cout << "Multiply:" << endl;
	Complex a(4, 2);
	Complex b(2, 3);

	Complex c = a * b;
	c.print();
}

void Division() {
	cout << "Division:" << endl;
	Complex a(6, 8);
	Complex b(2, 3); 

	Complex c = a / b; 
	c.print();
}

void Equal() {
	cout << "Equal:" << endl;
	Complex a(6, 8);
	Complex b(6, 8);

	bool result =  a == b;
	cout << result << endl;
}

void EqualDifferentNumbers() {
	cout << "Different Numbers:" << endl;
	Complex a(6, 7);
	Complex b(6, 8);

	bool result = a == b;
	cout << result << endl;
}

void NotEqual() {
	cout << "NotEqual:" << endl;
	Complex a(6, 7);
	Complex b(6, 8);

	bool result = a != b;
	cout << result << endl;
}


int main() {
	Sum();
	SumOnlyinteger();
	Minus();
	Multiply();
	Division();
	Equal(); 
	EqualDifferentNumbers();
	NotEqual(); 
}