// MaxProductOfThree
// https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/

// 배열 길이 N (3 ~ 100,000)
// 각 원소 범위 (-1,000 ~ 1,000)
// 정렬하여 음수가 2개이상 존재한다면 제일 작은 두 음수와 제일큰 양수를 곱하여 세 양수의 곱과 비교
// 시간 복잡도: O(N logN)

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int solution(int A[], int N) {
    if (N == 3) return A[0] * A[1] * A[2];

    qsort(A, N, sizeof(int), compare);
    int answer = A[N - 1] * A[N - 2] * A[N - 3];

    if (A[0] < 0 && A[1] < 0) {
        int p2 = A[0] * A[1] * A[N - 1];
        answer = answer > p2 ? answer : p2;
    }

    return answer;
}

int main(int argc, char const *argv[]) {
    int A[] = {9, -3, 5, 4, -8, 7, 6};
    int N = sizeof(A) / sizeof(int);
    int result = solution(A, N);
    printf("\nresult: %d\n", result);
    return 0;
}