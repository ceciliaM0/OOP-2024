#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag) {
    real_data = real;
    imag_data = imag;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp(*this);
    ++(*this);
    return temp;
}

Complex Complex::operator--(int) {
    Complex temp(*this);
    --(*this);
    return temp;
}

Complex& Complex::operator++() {
    ++real_data;
    return *this;
}

Complex& Complex::operator--() {
    --real_data;
    return *this;
}

Complex operator+(const Complex& l, const Complex& r) {
    return { l.real() + r.real(), l.imag() + r.imag() };
}

Complex operator+(const Complex& l, double r) {
    return { l.real() + r, l.imag() };
}

Complex operator+(double l, const Complex& r) {
    return { l + r.real(), r.imag() };
}

Complex operator-(const Complex& l, const Complex& r) {
    return { l.real() - r.real(), l.imag() - r.imag() };
}

Complex operator-(const Complex& l, double r) {
    return { l.real() - r, l.imag() };
}

Complex operator-(double l, const Complex& r) {
    return { l - r.real(), -r.imag() };
}

Complex operator*(const Complex& l, const Complex& r) {
    double real_part = l.real() * r.real() - l.imag() * r.imag();
    double imag_part = l.real() * r.imag() + l.imag() * r.real();
    return { real_part, imag_part };
}

Complex operator*(const Complex& l, double r) {
    return { l.real() * r, l.imag() * r };
}

Complex operator*(double l, const Complex& r) {
    return { l * r.real(), l * r.imag() };
}

Complex operator-(const Complex& obj) {
    return { -obj.real(), -obj.imag() };
}

bool operator==(const Complex& l, const Complex& r) {
    return l.real() == r.real() && l.imag() == r.imag();
}

bool operator!=(const Complex& l, const Complex& r) {
    return !(l == r);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    if (complex.is_real()) {
        out << complex.real();
    } else {
        out << complex.real() << " + " << complex.imag() << "i";
    }
    return out;
}