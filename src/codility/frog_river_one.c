// FrogRiverOne
// https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

// X: 건너야 하는 거리 (1 ~ 100,000)
// N: 배열 A의 길이 (1 ~ 100,000)
// 각 원소의 범위 (1 ~ X)
// 각 원소 1부터 X까지 모든 위치에 나뭇잎이 떨어지는 최단시간을 구해야한다.
// 나뭇잎이 놓이는 개수(중복을 제거한)를 거리 X 값과 비교하여 판단
// 예상 시간복잡도: O(N)

#include <stdio.h>

int solution(int X, int A[], int N) {
    int leaves[100001] = {0};
    int count = 0;

    for (int i=0; i<N; i++) {
        if (leaves[A[i]] == 0) {
            leaves[A[i]] = 1;
            count++;
        }

        if (count == X) return i;
    }

    return -1;
}

int main() {
    int X = 5;
    int A[] = {1, 3, 1, 4, 2, 3, 5, 4};
    int N = sizeof(A) / sizeof(int);
    int result = solution(X, A, N);
    printf("result: %d\n", result);
    return 0;
}
