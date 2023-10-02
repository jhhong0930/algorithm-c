// PassingCars
// https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/

// 짝이 1,000,000,000 개가 넘어가면 return -1
// 위에서부터 동쪽으로 가는 차를 하나씩 추가하며 해당 수만큼 서쪽으로 가는 차를 만나는 경우를 카운트
// 시간복잡도: O(N)

#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N) {
    int toEast = 0;
    int count = 0;

    for (int i=0; i<N; i++) {
        if (A[i] == 0) {
            toEast++;
        } else {
            count += toEast;
        }

        if (count > 1000000000) return -1;
    }

    return count;
}

int main(int argc, char const *argv[]) {
    int A[] = {0, 1, 0, 1, 1};
    int N = sizeof(A) / sizeof(int);
    int result = solution(A, N);
    printf("result: %d\n", result);
    return 0;
}