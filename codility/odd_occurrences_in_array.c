// OddOccurencesInArray
// https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int solution(int A[], int N) {
    if (N == 1) return A[0];
    
    qsort(A, N, sizeof(int), compare);
    int answer = 0;
    
    // 정렬하여 첫 번째와 두 번재의 숫자가 일치하는지 확인
    for (int i=0; i<N; i=i+2) {
        if (A[i] != A[i+1]) {
            answer = A[i];
            break;
        }
    }
    
    return answer;
}

int main(void) {
    int A[] = {9, 3, 9, 3, 9, 7, 9};
    int N = sizeof(A) / sizeof(int);
    int result = solution(A, N);
    printf("result: %d\n", result);
}
