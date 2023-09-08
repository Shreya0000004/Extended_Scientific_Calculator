#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

class Calculator {
public:
    Calculator();  // Constructor

    double performOperation(double num1, double num2, char op);
    double squareRoot(double num);
    double square(double num);
    double power(double base, double exponent);
    double naturalLog(double num);
    double base10Log(double num);
    double sine(double angle, bool useDegrees);
    double cosine(double angle, bool useDegrees);
    double tangent(double angle, bool useDegrees);
    double arcsine(double value, bool useDegrees);
    double arccosine(double value, bool useDegrees);
    double arctangent(double value, bool useDegrees);
    double degreesToRadians(double degrees);
    double radiansToDegrees(double radians);
};

#endif

