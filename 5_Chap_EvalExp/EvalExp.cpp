
#include <iostream>
//#include <stack>
#include "StackException.h"
#include "ArrayStack.h"
#include <string>
#include <cctype>
#include <map>

using namespace std;

// Function to check operator precedence
int precedence(char op) {
    if (op == '=' || op == '<' || op == '>') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

// Perform the operation on two values
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '=': return (a == b) ? 1 : 0;
        case '<': return (a <= b) ? 1 : 0;
        case '>': return (a >= b) ? 1 : 0;
    }
    return 0;
}

// Repeat operations based on precedence
void repeatOps(ArrayStack<int>& valStk, ArrayStack<char>& opStk, char currentOp) {
    while (!opStk.empty() && precedence(opStk.top()) >= precedence(currentOp)) {
        char op = opStk.top();
        opStk.pop();

        int b = valStk.top(); valStk.pop();
        int a = valStk.top(); valStk.pop();

        valStk.push(applyOperation(a, b, op));
    }
}

// Evaluate expression
int evalExp(const string& expression) {
    ArrayStack<int> valStk;
    ArrayStack<char> opStk;
    string number = "";

    for (char z : expression) {
        if (isdigit(z)) {
            number += z; // Accumulate digits for multi-digit numbers
        } else {
            if (!number.empty()) {
                valStk.push(stoi(number));
                number = "";
                valStk.print();
                opStk.print();
            }
            if (z == ' ') continue; // Ignore spaces
            if (z == '+' || z == '-' || z == '*' || z == '/' || z == '=' || z == '<' || z == '>') {
                repeatOps(valStk, opStk, z);
                opStk.push(z);
                valStk.print();
                opStk.print();
            }
        }
    }
    if (!number.empty()) {
        valStk.push(stoi(number));
        valStk.print();
        opStk.print();
    }

    repeatOps(valStk, opStk, '$'); // Handle remaining operations
    return valStk.top();
}

int main() {
    string expression;
    cout << "Enter an arithmetic expression: ";
    getline(cin, expression);

    try {
        int result = evalExp(expression);
        cout << "Result: " << result << endl;
    } catch (...) {
        cout << "Error in evaluation!" << endl;
    }

    return EXIT_SUCCESS;
}


