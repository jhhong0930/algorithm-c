// 올바른 괄호
// https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=c

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100000

char stack[MAX_STACK_SIZE];
int top = -1;

bool isEmpty() {
    return top < 0;
}

void push(char value) {
    stack[++top] = value;
}

char pop() {
    if (isEmpty()) {
        printf("Stack is empty!");
        return 0;
    } else {
        return stack[top--];
    }
}

bool solution(const char* s) {
    for (int i=0; s[i] != '\0'; i++) {
        char current = s[i];
        if (current == '(') {
            push(current);
        } else {
            if (isEmpty()) return false;
            pop();
        }
    }
    return isEmpty();
}

// stack 이 비었는데 닫는 괄호가 나오는 경우 -> false
// for 문을 전부 돌았는데 stack 이 비어있지 않은경우 -> false
// for 문을 전부 돌았고 stack 도 비어있는 경우 -> true

int main(void) {
    bool result = solution("()()");
    printf("result: %d\n", result);
    return 0;
}
