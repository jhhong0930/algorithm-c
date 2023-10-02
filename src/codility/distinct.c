// Distinct
// https://app.codility.com/programmers/lessons/6-sorting/distinct/

// 배열 길이 N (1 ~ 100,000)
// 원소 범위 (-1,000,000 ~ 1,000,000)
// 크기가 2,000,001 인 배열을 할당하여 각 인덱스에 맞게 삽입
// 음수의 경우 2,000,001 을 더하여 1,000,001 ~ 2,000,000 까지 저장
// 시간 복잡도: O(N) 또는 O(N logN)

#include <stdio.h>

int solution(int A[], int N) {
    int check[2000001] = {0};
    int count = 0;

    for (int i=0; i<N; i++) {
        if (A[i] < 0) {
            check[2000001 + A[i]] = 1;
        } else {
            check[A[i]] = 1;
        }
    }

    for (int i=0; i<2000001; i++) {
        if (check[i] != 0) count++;
    }

    return count;
}

int main(int argc, char const *argv[]) {
    int A[] = {2, 1, 1, 2, 3, 1};
    int N = sizeof(A) / sizeof(int);
    int result = solution(A, N);
    printf("result: %d\n", result);
    return 0;
}
