#include <stdio.h>
#include <string.h>
#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char stackTop() {
    return stack[top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int isOp(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];


        if (!isOp(c) && c != '(' && c != ')') {
            postfix[k++] = c;
        }

        else if (c == '(') {
            push(c);
        }

        else if (c == ')') {
            while (top != -1 && stackTop() != '(') {
                postfix[k++] = pop();
            }
            pop();
        }

        else {
            while (top != -1 && precedence(stackTop()) >= precedence(c)) {
                if (stackTop() == '(') break;
                postfix[k++] = pop();
            }
            push(c);
        }
    }


    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

