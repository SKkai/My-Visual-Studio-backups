//#define NOW
#ifdef NOW
#ifndef _MAIN_C
#define _MAIN_C
#include <main.h>
evening_struct training[5000];//ѵ�������ṹ��
evening_struct testing[5000];//���������ṹ��
int total_training_nums = 0;//ѵ����������
int total_testing_nums = 0;//������������

//�����������ڽ��жԲ������ݵı�ǩ�ƶ��Լ�������ȷ��
//����bmpͼ���ʶ�������˵����ĺ���������main.h���ҵ�����������ֱ�ӵ���
//ͼ��ʶ��ֻ������������ʶ��Ҫ�������32*32��λͼ�����Բ�û����ȫ���Ҫ��
int main(void) {
    int k = 5;//kֵ������ȡ̫��5֮���kֵ��������������ȷ�ʣ������Ἣ�ߵ���������ʱ��
    char *path;
    int num_of_file;
    double right_rate;
    path = (char*)malloc(sizeof(char)*MAX_PATH);
    int i = 0;
    printf("Please input the training path:\n");
    while ((path[i] = fgetc(stdin)) != '\n')i++;//��ȡѵ������·��
    path[i] = '\0';
    num_of_file = read_file_list(path);//����1ר��
    read_training_data(path);//��ȡѵ������
    printf("Please input the testing path:\n");
    i = 0;
    while ((path[i] = fgetc(stdin)) != '\n')i++;//��ȡ��������·��
    path[i] = '\0';
    read_testing_data(path);//��ȡ��������
    enlabel_testing_files(k);//�����ƶ�
    right_rate = cal_rate();//������ȷ��
    printf("k = %d, %d�������µ���ȷ�ʣ�%lf\n", k, total_testing_nums, right_rate);
    free(path);
    return 0;
}


#endif
#endif
