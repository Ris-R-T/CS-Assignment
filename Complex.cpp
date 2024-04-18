#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator, (imag * other.real - real * other.imag) / denominator);
    }

    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    
    bool operator>(const Complex& other) const {
        return sqrt(real * real + imag * imag) > sqrt(other.real * other.real + other.imag * other.imag);
    }

    bool operator<(const Complex& other) const {
        return other > *this;
    }

    bool operator>=(const Complex& other) const {
        return !(*this < other);
    }

    bool operator<=(const Complex& other) const {
        return !(*this > other);
    }


    friend ostream& operator<<(ostream& out, const Complex& num);
};

ostream& operator<<(ostream& out, const Complex& num) {
    if (num.imag >= 0) {
        out << num.real << " + " << num.imag << "i";
    } else {
        out << num.real << " - " << -num.imag << "i";
    }
    return out;
}



int main() {
    Complex a(3, 4), b(2, 1);

    cout << "Addition: " << a + b << endl;

    cout << "Subtraction: " << a - b << endl;

    cout << "Multiplication: " << a * b << endl;

    cout << "Division: " << a / b << endl;

    cout << boolalpha;

    Complex d(3, 0);
    cout << "Testing for equality: a == d: "<< (a == d) << endl;
    if(a == d) {
        cout << "a is equal to d" << endl;
    } else {
        cout << "a is not equal to d" << endl;
    }

    Complex e(3, 4);
    cout << "Testing for inequality: a != e: " << (a != e) << endl;
    if(a != e) {
        cout << "a is not equal to e" << endl;
    } else {
        cout << "a is equal to e" << endl;
    }

    Complex f(3, 4);
    cout << "Testing greater than: a > f: " << (a > f) << endl;
    cout << "Testing greater than or equal to: a >= f: " << (a >= f) << endl;
    cout << "Testing less than: a < f: " << (a < f) << endl;
    cout << "Testing less than or equal to: a <= f: " << (a <= f) << endl;

    return 0;
}
