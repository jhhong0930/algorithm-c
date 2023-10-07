// Fish
// https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/

// 배열 길이 N (1 ~ 100,000)
// 각 원소 범위 (0 ~ 1,000,000,000)
// 각 원소는 중복이 존재하지 않음
// 방향 1을 만나면 stack 에 push
// 방향 0을 만나면
// - 만약 stack 이 비어있다면 그대로 진행
// - stack 이 비어있지 않다면 stack 안의 원소와 해당 값과 비교
//   - 비교하여 타겟 값이 작다면 death++
//   - 타겟 값이 크다면 stack 에서 pop 및 death++
// 시간 복잡도: O(N)

#include <stdio.h>
#include <stdbool.h>

int stack[100000];
int top = -1;

bool isEmpty() {
    return top < 0;
}

void push(int value) {
    stack[++top] = value;
}

int pop () {
    if (isEmpty()) {
        printf("Stack is Empty");
        return 0;
    } else {
        return stack[top--];
    }
}

int solution(int A[], int B[], int N) {

    int death = 0;

    for (int i=0; i<N; i++) {
        if (B[i] == 1) {
            push(A[i]);
        } else {
            if (!isEmpty()) {
                while (!isEmpty()) {
                    if (stack[top] > A[i]) {
                        death++;
                        break;
                    } else {
                        pop();
                        death++;
                    }
                }
            }
        }
    }

    return N - death;
}

int main(int argc, char const *argv[]) {
    int A[] = {4, 3, 2, 1, 5};
    int B[] = {0, 1, 0, 0, 0};
    int N = sizeof(A) / sizeof(int);
    int result = solution(A, B, N);
    printf("\nresult: %d\n", result);
    return 0;
}