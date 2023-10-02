// PermCheck
// https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/

// 배열 길이 N (1 ~ 100,000)
// 각 원소 범위 (1 ~ 1,000,000,000)
// 배열길이 N 만큼 정렬하여 첫 번째 원소부터 확인
// 정렬을 해도 첫 원소가 1부터 시작을 하지 않으면 false
// 예상 시간복잡도: O(N) 또는 0(N logN)

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int solution(int A[], int N) {
    if (N == 1 && A[0] != 1) return 0; 
    qsort(A, N, sizeof(int), compare);
    
    int answer = 1;
    int count = 1;
    for (int i=0; i<N; i++) {
        if (count != A[i]) {
            answer = 0;
            break;
        }
        count++;
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    int A[] = {9, 3, 5, 4, 8, 7, 6};
    int N = sizeof(A) / sizeof(int);
    int result = solution(A, N);
    printf("result: %d\n", result);
    return 0;
}
