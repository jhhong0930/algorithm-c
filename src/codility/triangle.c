// Triangle
// https://app.codility.com/programmers/lessons/6-sorting/triangle/

// 배열 길이 N (0 ~ 100,000)
// 각 원소 범위: 4Byte
// 세 변이 각각 나머지 두 합보다 작아야 함
// P + Q > R
// Q + R > P
// R + P > Q
// 시간 복잡도: O(N logN)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

bool isTriangular(int a, int b, int c) {
    long p = (long) a;
    long q = (long) b;
    long r = (long) c;
    return p + q > r && q + r > p && r + p > q;
}

int solution(int A[], int N) {
    if (N < 3) return 0;

    qsort(A, N, sizeof(int), compare);
    for (int i=0; i<N-2; i++) {
        if (isTriangular(A[i], A[i+1], A[i+2])) return 1;
    }

    return 0;
}

int main(int argc, char const *argv[]) {
    int A[] = {10, 2, 5, 1, 8, 20};
    int N = sizeof(A) / sizeof(int);
    int result = solution(A, N);
    printf("\nresult: %d\n", result);
    return 0;
}