#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

class Calculator {
public:
    // Constructor, if needed
    Calculator() {}

    // Function to perform basic arithmetic operations
    double performOperation(double num1, double num2, char op) {
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
                    cout << "Error: Division by zero!" << endl;
                    return NAN; // Not-a-Number to represent an error
                }
            case '%':
                return (num1 * num2) / 100;
            default:
                cout << "Error: Invalid operator!" << endl;
                return NAN;
        }
    }

    // Function to calculate square root
    double squareRoot(double num) {
        if (num >= 0) {
            return sqrt(num);
        } else {
            cout << "Error: Square root of a negative number is undefined!" << endl;
            return NAN;
        }
    }

    // Function to calculate square
    double square(double num) {
        return num * num;
    }

    // Function to calculate power (x^y)
    double power(double base, double exponent) {
        return pow(base, exponent);
    }

    // Function to calculate natural logarithm (ln)
    double naturalLog(double num) {
        if (num > 0) {
            return log(num);
        } else {
            cout << "Error: Natural logarithm of a non-positive number is undefined!" << endl;
            return NAN;
        }
    }

    // Function to calculate base 10 logarithm (log)
    double base10Log(double num) {
        if (num > 0) {
            return log10(num);
        } else {
            cout << "Error: Logarithm of a non-positive number is undefined!" << endl;
            return NAN;
        }
    }

    // Function to calculate sine (sin)
    double sine(double angle, bool useDegrees) {
        if (useDegrees) {
            angle = degreesToRadians(angle);
        }
        return sin(angle);
    }

    // Function to calculate cosine (cos)
    double cosine(double angle, bool useDegrees) {
        if (useDegrees) {
            angle = degreesToRadians(angle);
        }
        return cos(angle);
    }

    // Function to calculate tangent (tan)
    double tangent(double angle, bool useDegrees) {
        if (useDegrees) {
            angle = degreesToRadians(angle);
        }
        return tan(angle);
    }

    // Function to calculate arcsine (arcsin)
    double arcsine(double value, bool useDegrees) {
        double result = asin(value);
        if (useDegrees) {
            result = radiansToDegrees(result);
        }
        return result;
    }

    // Function to calculate arccosine (arccos)
    double arccosine(double value, bool useDegrees) {
        double result = acos(value);
        if (useDegrees) {
            result = radiansToDegrees(result);
        }
        return result;
    }

    // Function to calculate arctangent (arctan)
    double arctangent(double value, bool useDegrees) {
        double result = atan(value);
        if (useDegrees) {
            result = radiansToDegrees(result);
        }
        return result;
    }

    // Function to convert degrees to radians
    double degreesToRadians(double degrees) {
        return degrees * (M_PI / 180.0);
    }

    // Function to convert radians to degrees
    double radiansToDegrees(double radians) {
        return radians * (180.0 / M_PI);
    }
};

int main() {
    double num1, num2, result;
    string op; // Use string for operator
    bool continueCalculation = true;
    vector<string> history;

    bool useDegrees = true; // Use degrees for trigonometric functions by default

    while (continueCalculation) {
        cout << "Enter first number: ";
        cin >> num1;

        // Initialize num2 with 0 for the first iteration
        num2 = 0;

        while (true) {
            cout << "Enter operator (+, -, *, /, %, s, q, ^, l, g, sin, cos, tan, asin, acos, atan, d, r): ";
            cin >> op;

            if (op == "s") {
                result = Calculator().squareRoot(num1);
            } else if (op == "q") {
                result = Calculator().square(num1);
            } else if (op == "^") {
                // Only ask for num2 when calculating with '^' operator
                cout << "Enter second number: ";
                cin >> num2;
                result = Calculator().power(num1, num2);
            } else if (op == "l") {
                result = Calculator().naturalLog(num1);
            } else if (op == "g") {
                result = Calculator().base10Log(num1);
            } else if (op == "sin" || op == "cos" || op == "tan" || op == "asin" || op == "acos" || op == "atan") {
                cout << "Enter angle value: ";
                cin >> num1;
                result = Calculator().sine(num1, useDegrees);
                if (op == "cos") {
                    result = Calculator().cosine(num1, useDegrees);
                } else if (op == "tan") {
                    result = Calculator().tangent(num1, useDegrees);
                } else if (op == "asin") {
                    result = Calculator().arcsine(num1, useDegrees);
                } else if (op == "acos") {
                    result = Calculator().arccosine(num1, useDegrees);
                } else if (op == "atan") {
                    result = Calculator().arctangent(num1, useDegrees);
                }
            } else if (op == "d") {
                useDegrees = true;
                cout << "Switched to degree mode." << endl;
                continue;
            } else if (op == "r") {
                useDegrees = false;
                cout << "Switched to radian mode." << endl;
                continue;
            } else if (op == "+" || op == "-" || op == "*" || op == "/" || op == "%") {
                cout << "Enter second number: ";
                cin >> num2;
                result = Calculator().performOperation(num1, num2, op[0]);
            } else {
                cout << "Error: Invalid operator!" << endl;
                continue;
            }

            if (!isnan(result)) {
                cout << "Result: " << result << endl;
                history.push_back(to_string(num1) + " " + op + " " + to_string(num2) + " = " + to_string(result));
            }

            // Ask if the user wants to continue with the previous result as the first number
            char choice;
            cout << "Do you want to continue with the previous result as the first number? (y/n): ";
            cin >> choice;
            if (choice != 'y' && choice != 'Y') {
                break;
            }

            // Set num1 to the result for the next iteration
            num1 = result;
        }

        // Ask if the user wants to continue the overall calculation
        char choice;
        cout << "Do you want to continue calculations? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            continueCalculation = false;
        }
    }

    // Display calculation history
    cout << "Calculation History:" << endl;
    for (const string& entry : history) {
        cout << entry << endl;
    }

    return 0;
}

