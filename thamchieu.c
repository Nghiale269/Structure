#include<stdio.h>
#include <stdlib.h>

void nhap (int *arr, int n)
{
    for (int i = 0; i< n; i++)
    {
        printf("\n a[%d] = ", i);
        scanf("%d", arr+i);
    }
}

void xuat (int *arr, int n)
{
    for (int i = 0; i< n; i++)
    {
        printf("\t %d", *(arr+i));
    }
}

int main()
{
  int n;
   
   
    printf("\n nhap so phan tu mang ");
    int *arr = (int *) malloc(n*sizeof(int));

    scanf("%d", &n);
    nhap(arr, n);
    xuat(arr, n);

}