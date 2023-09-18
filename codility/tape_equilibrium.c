// TapeEquilibrium
// https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

#include <stdio.h>
#include <stdlib.h>

// A 배열의 길이: 2 ~ 100,000 (N)
// A 원소의 범위: -1,000 ~ 1,000
// 특정 위치 P 로부터 이전의 모든 합 및 이후의 모든 합을 알아야 함
// 순회 전에 모든 배열의 합을 미리 구해서 첫 번째 지점에서 움직일 때마다 좌측과 우측을 계산하면 될듯
// 예상 시간 복잡도: 2O(N)

int solution(int A[], int N) {
    if (N == 2) return abs(A[0] - A[1]); // 배열의 길이가 2일때의 예외처리
    
    int sum = 0;
    int min = 1001; // 원소의 최대값이 1000 이므로 1001 로 초기화
    
    for (int i=0; i<N; i++) {
        sum = sum + A[i];
    }
    
    int left = 0; // P 위치로부터 좌측
    int right = sum; // P 위치로부터 우측
    
    for (int i=0; i<N-1; i++) {
        left = left + A[i];
        right = right - A[i];
        int diff = abs(left - right);
        
        if (diff < min) min = diff;
    }
    
    return min;
}

int main(void) {
    int A[] = {3, 1, 2, 4, 3};
    int N = sizeof(A) / sizeof(int);
    int result = solution(A, N);
    printf("result: %d\n", result);
}
