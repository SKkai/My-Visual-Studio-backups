//#define NOW
#ifdef NOW
#ifndef _BMP_C
#define _BMP_C
#include <main.h>

//���ڻ�ֻ��֧��32*32��λͼ����
void bmp_translation(char* bmp, char* txt) {
    char newfile[33][33];
    FILE *fp;
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    unsigned char *imagine;
    imagine = (unsigned char*)calloc(100* 100, sizeof(unsigned char));
    DWORD width, height;
    short c;
    fp = fopen(bmp, "rb");
    fseek(fp, 0, 0);
    fread(&fileHeader, sizeof(fileHeader), 1, fp);
    fread(&infoHeader, sizeof(infoHeader), 1, fp);
    width = infoHeader.biWidth;
    height = infoHeader.biHeight;
    fread(imagine, sizeof(unsigned char), width*height, fp);
    for (int i = 0; i < height; i++)
    {
        int j = 0;
        for (j = 0; j < width; j++)
        {
            if (imagine[i*width + j] > 200)//��ɫ//��ɫ�ķ�ΧҪ��С�㣬��Ȼȫ����
                newfile[i][j] = '1';
            else newfile[i][j] = '0';//��ɫ
        }
        newfile[i][j] = '\n';
    }
    free(imagine);
    imagine = NULL;
    fclose(fp);
    fp = fopen(txt, "w+");
    for (int i = 0; i <32; i++) {
        for (int j = 0; j <33; j++) {
            fputc(newfile[i][j], fp);
        }
    }
    fputc('\n', fp);
    fclose(fp);
}

#endif
#endif
