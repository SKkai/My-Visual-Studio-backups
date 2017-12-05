#ifndef _MAIN_H
#define _MAIN_H
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <bmp.h>
#define MAX_LINE 1024
#define MAX_PATH 1024
#define TEST_NUMBER 50//ʵ��ʹ�û�Ϊtotal_testing_nums
typedef struct Evening_Struct {
    short place[33][33];//�ļ�����
    short guesslabel;//�ƶϵı�ǩ
    short truelabel;//ʵ�ʵı�ǩ
    int num;//���
}evening_struct;
int read_file_list(char *path);//��ȡ�ļ��б�
void read_training_data(char* trainingpath);
void read_a_single_file(char *f_path, evening_struct *file_struct);
double cal_distance(evening_struct file_structA, evening_struct file_structB);
void enlabel_a_single_file(evening_struct *testing, int k);
void enlabel_testing_files(int k);
double cal_rate(void);
void bmp_translation(char* bmp, char* txt);
#endif
