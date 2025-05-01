#include <stdio.h>
#include <ctype.h>  // For isalpha() and isdigit()
#include <string.h> // For strlen()

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push elements onto the stack
void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

// Function to pop elements from the stack
char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to return the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch, x;

    push('(');               // Push '(' to handle expressions properly
    strcat(infix, ")");      // Append ')' to mark the end

    ch = infix[i];
    while (ch != '\0') {
        if (ch == '(') {
            push(ch);
        } else if (isalpha(ch) || isdigit(ch)) {  // Operand
            postfix[j++] = ch;
        } else if (ch == ')') {
            x = pop();
            while (x != '(') {  // Pop until '(' is encountered
                postfix[j++] = x;
                x = pop();
            }
        } else {  // Operator
            while (precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
        ch = infix[++i];
    }
    postfix[j] = '\0';  // Null-terminate the postfix string
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression (e.g., A+B*C): ");
    gets(infix);  // Turbo C++ supports gets()

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
