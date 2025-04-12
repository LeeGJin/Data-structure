/*
2장 실습 1
1 + 1/2 + 1/3 + ... + 1/n 을 계산하는 순환 함수 작성
*/

#include <stdio.h>

double harmonic_sum(int n) {
    if (n == 1) return 1.0;
    else {
        return 1.0/n + harmonic_sum(n-1);
    }
}

int main() {
    int n = 3;

    printf("%.2f\n", harmonic_sum(n));

    return 0;
}