#include <stdio.h>
#include <string.h>
#define MAXSIZE 50

//��ִ��-e����letter�ļ����ܣ������lol����ִ��-o�����ܲ������222
int main(void)
{
	FILE *file1, *file2;
	int i;
	int paslen;
	char a;
	char b[MAXSIZE];
	char c[] = "-e";
	char d[] = "-o";
	char key[50];
	scanf("%s",b);
	getchar();
	if (strcmp(b, c) == 0)
	{
		gets(key);
		paslen = strlen(key);//��ȡ���볤��
		file1 = fopen("letter.txt", "rb");
		file2 = fopen("lol.txt", "wb+");
		a = fgetc(file1);
		i = 0;
		while (a != EOF)
		{
			a = a ^ (key[i++]); //����������м���
			fputc(a, file2);
			a = fgetc(file1);
			if (i >= paslen) {
				i = 0;
			}
		}
		fclose(file1);
		fclose(file2);
	}
	if (strcmp(b, d) == 0)
	{
		gets(key);
		paslen = strlen(key);//��ȡ���볤��
		file1 = fopen("lol.txt", "rb");
		file2 = fopen("222.txt", "wb+");
		a = fgetc(file1);
		i = 0;
		while (a != EOF)
		{
			a = a ^ (key[i++]); //����������н��ܣ���������222
			fputc(a, file2);
			a = fgetc(file1);
		}
		fclose(file1);
		fclose(file2);
	}
	return 0;
}