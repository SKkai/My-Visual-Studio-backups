//#define NOW
#ifdef NOW
#include<stdio.h>

#define SUM  (a+b)
#define DIF  (a-b)//��������Ķ���Ҫ�������ţ���Ȼ�ᵼ�¼���ʱ���ȼ�����
#define SWAP(a,b)  t=a, a=b, b=t//�����Ķ��������⣬�ĳ���������ȷʵ�ֽ���
int main(void)
{
    int a, b, t;//aδ���壬�����ﲹ��
    printf("Input two integers a, b:");
    scanf("%d,%d", &a, &b);
    printf("\nSUM=%d\n the difference between square of a and square of b is:%d", SUM, SUM*DIF);
    SWAP(a, b);
    printf("\nNow a=%d,b=%d\n", a, b);
    return 0;
}


#endif
