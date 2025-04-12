/*
2장 실습 2
Ackermann 함수
A(0,n)=n+1;
A(m,0)=A(m-1,1)
A(m,n)=A(m-1,A(m,n-1)) m,n>=1
Ackermann 함수를 구하는 순환적인 프로그램을 작성하시오.
*/

#include <stdio.h>

int Ackermann(int m, int n) {
    if (m == 0) return n + 1;
    else if (n == 0) return Ackermann(m-1, 1);
    else {
        return Ackermann(m-1,Ackermann(m, n-1));
    }
}

int main() {
    int m = 1;
    int n = 2;
    printf("%d\n", Ackermann(m, n));

    return 0;
}