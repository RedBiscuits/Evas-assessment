#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
}

int evaluate(string expression) {
    int i;

    stack <int> operands;

    stack <char> operations;

    for (i = 0; i < expression.length(); i++) {

        if (expression[i] == ' ')
            continue;

        else if (expression[i] == '(') {
            operations.push(expression[i]);
        }

        else if (isdigit(expression[i])) {
            int val = 0;

            while (i < expression.length() &&
                isdigit(expression[i]))
            {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }

            operands.push(val);
            i--;
        }
        else if (expression[i] == ')')
        {
            while (!operations.empty() && operations.top() != '(')
            {
                int val2 = operands.top();
                operands.pop();

                int val1 = operands.top();
                operands.pop();

                char op = operations.top();
                operations.pop();

                operands.push(applyOp(val1, val2, op));
            }

            if (!operations.empty())
                operations.pop();
        }

        else
        {
            while (!operations.empty() && precedence(operations.top())
                >= precedence(expression[i])) {
                int val2 = operands.top();
                operands.pop();

                int val1 = operands.top();
                operands.pop();

                char op = operations.top();
                operations.pop();

                operands.push(applyOp(val1, val2, op));
            }

            operations.push(expression[i]);
        }
    }

    while (!operations.empty()) {
        int val2 = operands.top();
        operands.pop();

        int val1 = operands.top();
        operands.pop();

        char op = operations.top();
        operations.pop();

        operands.push(applyOp(val1, val2, op));
    }

    // Top of 'values' contains result, return it.
    return operands.top();
}

int main() {
    string s;
    getline(cin, s);
    cout << evaluate(s);
    return 0;
}