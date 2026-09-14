#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Max 10000

struct Stack {
    char arr[Max];
    int top;
};

void init(struct Stack* s) {
    s->top = -1;
}

void push(struct Stack* s, char ch) {
    if (s->top == Max - 1) return;   // overflow protection
    s->arr[++(s->top)] = ch;
}

void pop(struct Stack* s) {
    if (s->top == -1) return;        // underflow protection
    s->top--;
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

bool isValid(char* s) {
    struct Stack ss;
    init(&ss);

    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];

        // opening bracket
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&ss, ch);
        }
        // closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {

            if (ss.top == -1) return false;

            char topChar = ss.arr[ss.top];
            pop(&ss);

            if (!isMatchingPair(topChar, ch)) return false;
        }
    }

    return (ss.top == -1);
}
