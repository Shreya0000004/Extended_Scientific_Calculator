#include "calculator.h"
#include <iostream>
#include <cmath>

Calculator::Calculator() {}

double Calculator::performOperation(double num1, double num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                std::cout << "Error: Division by zero!" << std::endl;
                return NAN; // Not-a-Number to represent an error
            }
        case '%':
            return (num1 * num2) / 100;
        default:
            std::cout << "Error: Invalid operator!" << std::endl;
            return NAN;
    }
}

double Calculator::squareRoot(double num) {
    if (num >= 0) {
        return sqrt(num);
    } else {
        std::cout << "Error: Square root of a negative number is undefined!" << std::endl;
        return NAN;
    }
}

double Calculator::square(double num) {
    return num * num;
}

double Calculator::power(double base, double exponent) {
    return pow(base, exponent);
}

double Calculator::naturalLog(double num) {
    if (num > 0) {
        return log(num);
    } else {
        std::cout << "Error: Natural logarithm of a non-positive number is undefined!" << std::endl;
        return NAN;
    }
}

double Calculator::base10Log(double num) {
    if (num > 0) {
        return log10(num);
    } else {
        std::cout << "Error: Logarithm of a non-positive number is undefined!" << std::endl;
        return NAN;
    }
}

double Calculator::sine(double angle, bool useDegrees) {
    if (useDegrees) {
        angle = degreesToRadians(angle);
    }
    return sin(angle);
}

double Calculator::cosine(double angle, bool useDegrees) {
    if (useDegrees) {
        angle = degreesToRadians(angle);
    }
    return cos(angle);
}

double Calculator::tangent(double angle, bool useDegrees) {
    if (useDegrees) {
        angle = degreesToRadians(angle);
    }
    return tan(angle);
}

double Calculator::arcsine(double value, bool useDegrees) {
    double result = asin(value);
    if (useDegrees) {
        result = radiansToDegrees(result);
    }
    return result;
}

double Calculator::arccosine(double value, bool useDegrees) {
    double result = acos(value);
    if (useDegrees) {
        result = radiansToDegrees(result);
    }
    return result;
}

double Calculator::arctangent(double value, bool useDegrees) {
    double result = atan(value);
    if (useDegrees) {
        result = radiansToDegrees(result);
    }
    return result;
}

double Calculator::degreesToRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}

double Calculator::radiansToDegrees(double radians) {
    return radians * (180.0 / M_PI);
}

