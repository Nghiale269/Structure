// khai báo cấu trúc một phân số

#include<stdio.h>
typedef struct phan_so
{
    int tu_so; 
    int mau_so;

} phanso_t;

void nhap_ps (phanso_t ps[], int n)
{
    int i;
    for (i = 0; i< n; i++)
    {
        printf("\nPhan so thu %d ", i+1);
        do 
        {
            printf("\nNhap tu so ");
            scanf("%d", &ps[i].tu_so);
            if (ps[i].tu_so <= 0)
            {
                printf("\n nhap lai!!");
            }
        }
        while (ps[i].tu_so <= 0);

        do 
        {
            printf("\nNhap mau so ");
            scanf("%d", &ps[i].mau_so);
            if (ps[i].tu_so <= 0)
            {
                printf("\n nhap lai!!");
            }
        }
        while (ps[i].tu_so <= 0);
      
      
    }
}
void xuat_ps (phanso_t ps[], int n)
{
    int i;
    for (i = 0;i< n; i++)
    {
        if (ps[i].mau_so > 1)
        printf("\nPhan so thu %d = %d/%d", i+1, ps[i].tu_so, ps[i].mau_so);
        else
        printf("\nPhan so thu %d = %d", i+1, ps[i].tu_so);
    }
}
//void xuat_1_ps (void )
//  rút gon phan so
int UCLN (int a, int b)
{
    while (a != b)
    {
        if (a > b)
        a = a - b;
        else 
        b = b - a;
    }
    return a;
}

void rut_gon (phanso_t ps[], int n)
{
    int i;
    for (i = 0; i< n; i++)
    {
        int ucln = UCLN(ps[i].tu_so, ps[i].mau_so);
        ps[i].tu_so /= ucln;
        ps[i].mau_so /= ucln;
        
    }
}
// tìm phan so lon nhat
void max_ps (phanso_t ps[], int n)
{
     float  max = (float)ps[0].tu_so / ps[0].mau_so ;
     int idx = 0;
    for (int i = 1; i< n; i++)
    {
        float  phanso = (float)ps[i].tu_so / ps[i].mau_so ;
        if (max < phanso)
        {
            max = phanso;
            idx = i;
        }
    }
   printf("\n\n====================================");
   if (ps[idx].mau_so != 1)
   printf("\n\nphan so lon nhat la : %d/%d", ps[idx].tu_so, ps[idx].mau_so);
   else 
    printf("\n\nphan so lon nhat la : %d", ps[idx].tu_so);
      printf("\n\n====================================");
    
} 

int tong_phanso (phanso_t ps[], int n)
{
    phanso_t tong[1] ;
    tong[0].tu_so = 0;
    tong[0].mau_so =1;
    for (int i = 0; i< n ; i++)
    {
        tong[0].tu_so = tong[0].tu_so * ps[i].mau_so + tong[0].mau_so * ps[i].tu_so;
        tong[0].mau_so = tong[0].mau_so * ps[i].mau_so;
    }
    rut_gon(tong, 1);
    printf("\n\n=================");
    printf("\n tong cac phan so la");
    printf(" %d/%d", tong[0].tu_so, tong[0].mau_so);
      printf("\n\n=================");
}

int main()
{
    int n;
  
    printf("\n Nhap so luong phan so ");
      scanf("%d", &n);
    phanso_t ps[n];
  
    nhap_ps(ps, n);
    rut_gon(ps, n);
    xuat_ps(ps, n);

    //max_ps(ps, n);
    tong_phanso (ps, n);

    


}