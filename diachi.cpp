#include<stdio.h>
 struct student {
    int mssv;
    char name[20];
    float marks;
 };
 vo
 int main()
 {
    struct student S = {123, "tom", 12.3};
     struct student *ptr = &S;

    printf("\n dịa chia cua ptr = %d", &ptr);
    printf("\n dịa chia cua S = %d", S);
    printf("\n dịa chia cua phan tu struc dau tien = %d", &S.mssv);
     printf("\n dịa chia cua phan tu struc thu hai  = %d", &S.name);
      printf("\n Gia tri cua ptr = %d", *ptr);






 }