// 피보나치 수
// https://school.programmers.co.kr/learn/courses/30/lessons/12945

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int memo[100000] = {1, 1};

int fibo(int n) {
    if (n < 2) return n;
    
    if (memo[n] != 0) {
        return memo[n];
    } else {
        memo[n] = (fibo(n - 1) + fibo(n - 2)) % 1234567;
        return memo[n];
    }
}

int solution(int n) {
    return fibo(n);
}

int main(void) {
    int result = solution(5);
    printf("result: %d\n", result);
    return 0;
}
