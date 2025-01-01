#include "ImaginaryPoint.h"

// Constructor
ImaginaryPoint::ImaginaryPoint(int real, int imaginary)
{
    real_part = real;
    imaginary_part = imaginary;
}

// Destructor
ImaginaryPoint::~ImaginaryPoint()
{
    //no destructor needed.
}

// Calculate magnitude squared
int ImaginaryPoint::get_magnitude_squared() const
{
    return real_part*real_part + imaginary_part*imaginary_part;
}

// Getter for real part
int ImaginaryPoint::get_real_part() const
{
    return real_part;
}

// Getter for imaginary part
int ImaginaryPoint::get_imaginary_part() const
{
    return imaginary_part;
}

// Overload addition operator
ImaginaryPoint ImaginaryPoint::operator+(const ImaginaryPoint& other) const
{     
    ImaginaryPoint myResult(real_part + other.real_part, imaginary_part + other.imaginary_part);
    return myResult;
}

// Overload subtraction operator
ImaginaryPoint ImaginaryPoint::operator-(const ImaginaryPoint& other) const
{
    ImaginaryPoint myResult(real_part - other.real_part, imaginary_part - other.imaginary_part);
    return myResult;
}

// Overload multiplication operator
ImaginaryPoint ImaginaryPoint::operator*(const ImaginaryPoint& other) const
{
    // (a+bi)*(c+di) = (ac - bd) + (ad + bc)i
    int new_real = (real_part * other.real_part) - (imaginary_part * other.imaginary_part);
    int new_imaginary = (real_part * other.imaginary_part) + (imaginary_part * other.real_part);
    return ImaginaryPoint(new_real, new_imaginary);

}

// Overload less than operator
bool ImaginaryPoint::operator<(const ImaginaryPoint& other) const
{
    int first_magnitude_squared = get_magnitude_squared();
    int other_magnitude_squared = other.get_magnitude_squared();
    return first_magnitude_squared < other_magnitude_squared;
}

