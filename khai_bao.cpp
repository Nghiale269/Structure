// khai bao thong tin 1 nhan vien

#include<stdio.h>
#include<stdlib.h>

struct nhan_vien 
{
    char ho_ten[30];
    int tuoi;
    char chuc_vu[30];
    float luong;

};
void nhap_in4 (struct nhan_vien nv[], int so_luong)
{
     printf("\n ===================================================================");
     for (int i = 0; i< so_luong; i++)
        {
            printf("\nNhap thong tin nhan vien thu %d", i+1);
            fflush(stdin);
            printf("\nHo va ten: ");
            gets(nv[i].ho_ten);
            printf("Tuoi: ");
            scanf("%d", &nv[i].tuoi);
            fflush(stdin);
            printf("Chuc vu: ");
            gets(nv[i].chuc_vu);
            printf("Luong: ");
            scanf("%f", &nv[i].luong);
        }
     printf("\n ===================================================================");
}
void xuat_in4 (struct nhan_vien nv[], int so_luong)
{
    printf("\n ===================================================================");
     for (int i = 0; i< so_luong; i++)
        {
            printf("\nThong tin nhan vien thu %d", i+1);
            printf("\n\nHo ten:  %s", nv[i].ho_ten);
            printf("\nTuoi:  %d", nv[i].tuoi);
            printf("\nChuc vu:  %s", nv[i].chuc_vu);
            printf("\nLuong:  %.2f", nv[i].luong);
            printf("\n\n");
        }
     printf("\n ===================================================================");
}

void sapxep (struct nhan_vien s[], int n)
{
    for (int i = 0; i< n - 1; i++)
    {
        for (int j = i+1; j < n ; j++)
        {
            if (s[i].luong > s[j].luong)
            {
               struct nhan_vien tam = s[i];
               s[i] = s[j];
               s[j] = tam;
            }
        }
    }
}
// tim nhan vien co luong cao nhat
int tim_max (nhan_vien nv[], int n)
{
    float max = nv[0].luong;
    int idx = 0;

    for (int i = 1; i<n; i++)
    {
        nv[i].luong > max;
        max = nv[i].luong;
        idx = i;
    }
    printf("\nnhan vien co luong cao nhat la: ");
    printf("\nHo ten: %s", nv[idx].ho_ten);
    printf("\nluong: %.2f", nv[idx].luong);

}
int main()
{
    // struct nhan_vien nv;
     int so_luong;
    
    printf("\n nhap so luong nhan vien: ");
    scanf("%d", &so_luong);
    struct nhan_vien nv[so_luong];
    nhap_in4(nv, so_luong);      
    sapxep(nv, so_luong);
    xuat_in4(nv, so_luong);
    tim_max(nv, so_luong);
            
        

 }


    
