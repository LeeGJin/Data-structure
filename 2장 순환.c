//2장 순환

#include <stdio.h>

int factorial(int n) {
    if (n <= 1) return 1;
    else return n*factorial(n-1);

    /*재귀 안쓰는 버전
    int result = 1;
    if (n <= 1) return 1;
    else {
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
    }
    return result;
    */
}

double power(double x, int n) {
    if (n == 0) return 1;
    else if ((n % 2) == 0) return power(x*x, n/2);
    else return x*power(x*x, (n-1)/2);
}

int fib(int n) {
    //이 챕터가 순환이라 재귀함수를 사용했지만 재귀함수를 이용하여 피보나치 수수을 구하는 방법은 n이 커질수록
    //연산량이 기하급수적으로 증가하고 불필요한 연산, 즉 이미 했던 연산을 다시 해야하는 부분이 생긴다. (이산수학 부분)
    if (n <= 2) return 1;
    return fib(n-1) + fib(n-2);

    /*재귀함수 안쓰는 버전
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int p = 0;
    int pp = 1;
    int result = 0;
    for (int i = 2; i <= n; i++) {
        result = p + pp;
        p = pp;
        pp = result;
    }
    return result;
    */
}

void hanoi(int n, char A, char B, char C) {
    if (n == 1) printf("원판1을 %c에서 %c로 옮긴다.\n", A, C);
    else {
        hanoi(n-1, A, C, B);
        printf("원판%d를 %c에서 %c로 옮긴다.\n", n, A, C);
        hanoi(n-1, B, A, C);
    }
    return;
}

int main() {
    int n = 4;
    double dn = 4.0;

    printf("%d! = %d\n", n, factorial(n));
    printf("%.2f^%d = %.2f\n", dn, n, power(dn, n));
    printf("fib(%d) = %d\n", n, fib(n));
    hanoi(n, 'A', 'B', 'C');

    return 0;
}