#include<stdio.h>

typedef struct TOADO{
    int x;
    int y;
} toa_do;

void Xuat_1 (toa_do diem)
{
    
     
    printf("\n toa do x = %d", diem.x);
    printf("\n toa do y = %d", diem.y);

}

void xuat_mang (toa_do *ds, int n)
{
    //int i;
    for ( int i = 0; i< n; i++)
    {
    
        Xuat_1(*(ds+i));
    }
    
}

typedef struct danh_sach 
{
    toa_do arr[10];
    int n;
} DS;

void xuat_ds (DS list)
{
    for (int i = 0; i< list.n; i++)
    {
            printf("\n toa do diem %d", i+1);
        Xuat_1(list.arr[i]);
    }
}

void nhap_1 (toa_do *diem)
{
    printf("\n nhap toa do diem x ");
    scanf("%d", &diem->x);
    printf("\n nhap toa do diem y ");
    scanf("%d", &diem->y);

}

void nhap_ds (DS danh_sach)
{
    for (int i = 0; i< danh_sach.n; i++)
    {
        printf("\n nhap diem thu %d", i+1);
        nhap_1(&danh_sach.arr[i]);
    }
}

int main()
{
//     DS diem ;
//     printf("\n nhap so luong diem: ");
//     scanf("%d", &diem.n);
   
//    nhap_ds(diem);
//     xuat_ds(diem);

toa_do diem;
nhap_1(&diem);
Xuat_1(diem);

}