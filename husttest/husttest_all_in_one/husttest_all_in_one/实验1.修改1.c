//#define NOW
#ifdef NOW
#include<stdio.h>

#define PI 3.14159//ȥ�����ķֺ�
void main(void)//�Ӹ��ո�void��main������
{
    int f, newint;//�����newintδ���壬�����ﲹ��
    short p, k;
    double c, r, s;
    
    /* for task 1 */
    printf("Input  Fahrenheit : ");//��ΪӢ������
    scanf("%d", &f);//1.��ΪӢ������2.scanf�����贫��Ҫд��ı����ĵ�ַ��Ӧ��f���ϵ�ַ�����
    c = 1.0*5 / 9 * (f - 32);//���ø������������������
    printf(" \n %d(F) = %.2f(C)\n\n ", f, c);//��ΪӢ������

    /* for task 2 */
    printf("input the radius r:");
    scanf("%lf", &r);//��%lf��ȡdouble���͵�����
    s = PI * r * r;
    printf("\nThe acreage is %.2f\n\n", s);//���s��ֵ�������ַ

    /* for task 3 */
    printf("input hex int k, p :");
    scanf("%hx %hx", &k, &p);//��������ζ���ʮ��������
    newint = (p & 0xff00) | (k & 0xff00) >> 8;//1.newint�����油�˶���2.k�ĸ��ֽ������ƶ�������
    printf("new int = %x\n\n", newint);//�������������16�������
    return 0;
}


#endif
