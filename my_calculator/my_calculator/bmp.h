#ifndef _BMP_H
#define _BMP_H
//����ļ�����Windows.h�ﶨ����ģ���������̳�������һ�飬�������ٴΰ���Windows.h
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
#define SIZE 40

#pragma pack(push)
#pragma pack(1)

typedef struct tagBITMAPFILEHEADER {
    WORD bfType;
    DWORD bfSize;    
    WORD bfReserved1;
    WORD bfReserved2;  
    DWORD bfOffBits; 
                         
}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
    DWORD   biSize;   //   ���ṹ��ռ���ֽ��� 
    DWORD   biWidth;   //   λͼ�Ŀ�ȣ�������Ϊ��λ 
    DWORD   biHeight;   //   λͼ�ĸ߶ȣ�������Ϊ��λ 
    WORD    biPlanes;   //   Ŀ���豸�ļ��𣬱���Ϊ1 
    WORD    biBitCount;//   ÿ�����������λ����������1(˫ɫ), 4(16ɫ)��8(256ɫ)��24(���ɫ)֮һ 
    DWORD   biCompression;   //   λͼѹ�����ͣ�������   0(��ѹ��), 1(BI_RLE8ѹ������)��2(BI_RLE4ѹ������)֮һ 
    DWORD   biSizeImage;   //   λͼ�Ĵ�С�����ֽ�Ϊ��λ 
    DWORD   biXPelsPerMeter;   //   λͼˮƽ�ֱ��ʣ�ÿ�������� 
    DWORD   biYPelsPerMeter;   //   λͼ��ֱ�ֱ��ʣ�ÿ�������� 
    DWORD   biClrUsed;//   λͼʵ��ʹ�õ���ɫ���е���ɫ�� 
    DWORD   biClrImportant;//   λͼ��ʾ��������Ҫ����ɫ�� 
}BITMAPINFOHEADER;


#pragma pack(pop)

#endif
