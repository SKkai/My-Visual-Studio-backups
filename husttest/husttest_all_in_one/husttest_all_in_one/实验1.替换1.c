//#define NOW
#ifdef NOW

#include<stdio.h>

int main(void){
    int a, b;
    printf("Input two integers : ");
    scanf("%d %d", &a, &b);
    //���ǵ�Ӧ�ð�a��b��ֵ����Ϣ�ϳɺ�洢��ͬһ������a��b���У�Ȼ����b��ֵ���в��õ�a��ֵ��������a��ֵ���в��õ�b��ֵ����Ƴ������£�
    //������ĳ�����Լ������Ϊ0�������������ʽֱ��ʵ��
    a ^= b;//a��ֵΪa��b�Ĳ���λ��(a^b)
    b ^= a;//b��ֵΪa^b^b=b^b^a=0^a=a
    a ^= b;//a��ֵΪa^b^a=a^a^b=0^b=b
    /*ʵ��������ֵ�Ӽ�Ҳ����ʵ��
    a += b;//a��ֵΪa+b
    b = a-b;//b��ֵΪa+b-b=a
    a -= b;//a��ֵΪa+b-a=b
    */
    printf("\na = %d, b = %d", a, b);
    return 0;
}


#endif
