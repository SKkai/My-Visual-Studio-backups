//#define NOW
#ifdef NOW
#include<stdio.h>

int main(void) {
    unsigned short x, m, n;
    scanf("%hx %hu %hu", &x, &m, &n);
    x >>= m;
    x <<= (16 - n);
    if (m <= 15 && m >= 0 && n >= 1 && ((m + n) <= 16)) {
        //*****test:*****
        //����36936(��10010000 01001000) 1 3��Ӧ�õ�0x8000����10000000 00000000��
        printf("%#x\n", x);
        //��������
        //***************
    }
    else {
        printf("Error!");
    }
    return 0;
}


#endif
