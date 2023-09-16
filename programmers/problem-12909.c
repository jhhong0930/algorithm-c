// 올바른 괄호
// https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=c

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 스택에 넣는다고 가정만 하고 top 의 위치로만 판단
bool solution(const char* s) {
    int top = -1;
    
    for (int i=0; s[i]!='\0'; i++) {
        if (s[i] == '(') {
            top++;
        } else {
            if (top < 0) return false;
            top--;
        }
    }
    
    return top < 0;
}

int main(void) {
    bool result = solution("()()");
    printf("result: %d\n", result);
    return 0;
}
