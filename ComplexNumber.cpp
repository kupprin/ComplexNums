#include <iostream>
#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary) {}

double ComplexNumber::GetReal() const {
    return real;
}

double ComplexNumber::GetImaginary() const {
    return imaginary;
}

void ComplexNumber::SetReal(const double value) {
    real = value;
}

void ComplexNumber::SetImaginary(const double value) {
    imaginary = value;
}

ComplexNumber ComplexNumber::operator +(const ComplexNumber& other) {
    double new_real = real + other.real;
    double new_imaginary = imaginary + other.imaginary;
    return ComplexNumber(new_real, new_imaginary);
}

ComplexNumber ComplexNumber::operator -(const ComplexNumber& other) {
    double new_real = real - other.real;
    double new_imaginary = imaginary - other.imaginary;
    return ComplexNumber(new_real, new_imaginary);
}

ComplexNumber ComplexNumber::operator *(const ComplexNumber& other) {
    double new_real = real * other.real - imaginary * other.imaginary;
    double new_imaginary = real * other.imaginary + other.real * imaginary;
    return ComplexNumber(new_real, new_imaginary);
}

ComplexNumber ComplexNumber::operator /(const ComplexNumber& other) {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    double eps = 1e-5;
    if (std::fabs(denominator) < eps) {
        throw std::overflow_error("Divide by zero exception");
    }
    double new_real = (real * other.real + imaginary * other.imaginary) / denominator;
    double new_imaginary = (other.real * imaginary - real * other.imaginary) / denominator;
    return ComplexNumber(new_real, new_imaginary);
}

ComplexNumber& ComplexNumber::operator +=(const ComplexNumber& other) {
    real = (*this + other).real;
    imaginary = (*this + other).imaginary;
    return *this;
}

ComplexNumber& ComplexNumber::operator -=(const ComplexNumber& other) {
    real = (*this - other).real;
    imaginary = (*this - other).imaginary;
    return *this;
}

ComplexNumber& ComplexNumber::operator *=(const ComplexNumber& other) {
    real = (*this * other).real;
    imaginary = (*this * other).imaginary;
    return *this;
}

ComplexNumber& ComplexNumber::operator /=(const ComplexNumber& other) {
    real = (*this / other).real;
    imaginary = (*this / other).imaginary;
    return *this;
}

bool ComplexNumber::operator ==(const ComplexNumber& other) {
    return (real == other.real && imaginary == other.imaginary);
}

bool ComplexNumber::operator ==(const double& other) {
    double eps = 1e-5;
    return (real = other && std::fabs(imaginary) < eps);
}

double ComplexNumber::Abs() const {
    return std::sqrt(real * real + imaginary * imaginary);
}

ComplexNumber ComplexNumber::Pow(int degree) const {
    double r = std::pow(this->Abs(), degree);
    double phi = std::atan2(imaginary, real);
    double new_real = r * std::cos(degree * phi);
    double new_imaginary = r * std::sin(degree * phi);
    return ComplexNumber(new_real, new_imaginary);
}

std::ostream& operator << (std::ostream& out, const ComplexNumber& num)
{
    if (num.imaginary < 0) {
        out << num.real << num.imaginary << "i\n";
    }
    else {
        out << num.real << "+" << num.imaginary << "i\n";
    }
    return out;
}
