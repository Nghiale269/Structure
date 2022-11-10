#include<stdio.h>
#include<string.h>
typedef struct sinhvien
{
    char name[10];
    char *mssv;
    int diemtb;
} t_sv;

int main()
{
    t_sv sinh_vien;
    printf("\nnhap ten sinh vien ");
   // gets(sinh_vien.name);
    strcpy(sinh_vien.name ,"LE van ab");
    sinh_vien.mssv = "31245";
    sinh_vien.diemtb = 9;

    printf("\n%s", sinh_vien.name);


}