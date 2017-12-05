#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
//#define NOW
#define MAXSIZE 200
#ifdef NOW
void Translate(const char str[], char exp[]);//ת��Ϊ�沨�����ʽ
double CompValue(const char *exp); //���沨�����ʽ��ֵ 
double CharToDouble(const char *str); //�������ַ���ת��Ϊ������ 
void GetStr(char *str); //��ȡ����ʽ 
void ShowAnswer(const char *str, double answer); //����� 

int main(void)
{
	char str[MAXSIZE], exp[MAXSIZE];
	double answer;

	GetStr(str);
	puts(str);
	Translate(str, exp);
	puts(exp);
	answer = CompValue(exp);
	ShowAnswer(str, answer); //����� 

	return 0;
}

void GetStr(char *str) //��ȡ����ʽ 
{
	//FILE *fp;
	int i = 0;

	/*if ((fp = fopen("E:\\���\\Դ�������\\c\\ѧϰ����\\��ѧ����������ʽ.txt", "rb")) == NULL)
	
		fprintf(stderr, "Error opening file.");
		exit(1);
	}

	rewind(fp);*/
	while ((str[i] = fgetc(stdin)) != '\n')
	{
		if (str[i] == ' ')//ȥ������Ŀո� 
		{
			i--;
		}
		i++;
	}

	str[i++] = '\0';
	//str[i] = '\0';

	//fclose(fp);
}

void ShowAnswer(const char *str, double answer) //����� 
{
	//FILE *fp;

	//if ((fp = fopen("��ѧ����������ʽ.txt", "a+b")) == NULL)
	//{
	//	fprintf(stderr, "Error opening file.");
	//	exit(1);
	//}

	//fprintf(fp, " = %f ", answer);
	fprintf(stdout, "%s = %f\n", str, answer);

	//fclose(fp);
}

void Translate(const char str[], char exp[]) //ת��Ϊ�沨�����ʽ
{
	char stack[MAXSIZE];
	int i = 0, k = 0, top = -1;

	while (str[i] != '\0')
	{
		if (str[i] == '(') //ֱ�ӽ�'('��ջ 
		{
			stack[++top] = str[i++];
		}
		else if (str[i] == ')')
		{
			while (top >= 0 && stack[top] != '(') //��'('֮ǰ�ķ��ų�ջ�����洢���沨�����ʽ 
			{
				exp[k++] = stack[top--];
			}

			if (top < 0) //'('���㣬���ж����')'
			{
				puts("'('��ƥ��\n");
				exp[k++] = '\0';
				return;
			}
			top--;//ȥ�� '('
			i++;
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while (top >= 0 && stack[top] != '(') //�����'('����'('֮ǰ�ķ��ų�ջ���������з��ų�ջ�����洢���沨�����ʽ 
			{
				exp[k++] = stack[top--];
			}
			stack[++top] = str[i++]; //���µ����������ջ 
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			while (top >= 0 && (stack[top] == '*' || stack[top] == '/')) //��'*'��'/'֮ǰ�ķ��ų�ջ�����洢���沨�����ʽ 
			{
				exp[k++] = stack[top--];
			}
			stack[++top] = str[i++]; //���µ����������ջ 
		}
		else
		{
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') //��������ֱ�Ӵ洢���沨�����ʽ
			{
				exp[k++] = str[i++];
			}
			exp[k++] = ' '; //����һ���������������ţ��Ա���ȷ��ȡ������ 
		}
	}

	while (top >= 0) //��ջ������������Ŵ洢���沨�����ʽ
	{
		if (stack[top] == '(') //�ж����'(' 
		{
			puts("'('��ƥ��\n");
			exp[k++] = '\0';
			return;
		}
		exp[k++] = stack[top--];
	}

	exp[k++] = '\0';
}

double CompValue(const char *exp) //���沨�����ʽ��ֵ 
{
	char tempStr[MAXSIZE];
	double stack[MAXSIZE];
	int i = 0, k = 0, top = -1;

	while (exp[i] != '\0')
	{
		if (exp[i] >= '0' && exp[i] <= '9')
		{
			k = 0;
			while (exp[i] != ' ')
			{
				tempStr[k++] = exp[i++];
			}
			tempStr[k] = '\0';
			stack[++top] = CharToDouble(tempStr);
			i++; //����'#' 
		}
		else
		{
			switch (exp[i++]) //����������ջ�����˳���������� 
			{
			case '+': stack[top - 1] += stack[top];
				break;
			case '-': stack[top - 1] -= stack[top];
				break;
			case '*': stack[top - 1] *= stack[top];
				break;
			case '/': if (stack[top] != 0)
			{
				stack[top - 1] /= stack[top];
			}
					  else
					  {
						  puts("�������\n");
						  return 0;
					  }
					  break;
			}
			top--; //�˳���������� 
		}
	}

	return stack[top];
}

double CharToDouble(const char *str) //�������ַ���ת��Ϊ������ 
{
	double sumInt = 0, sumDec = 0, e = 1;
	int i = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		sumInt = sumInt * 10 + str[i++] - '0';
	}

	if (str[i] == '.') //�����С��������С������
	{
		while (str[++i] != '\0')
		{
			sumDec = sumDec * 10 + str[i] - '0';
			e *= 10;
		}
	}

	return sumInt + sumDec / e;
}
#endif