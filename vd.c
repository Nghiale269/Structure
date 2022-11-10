#include<stdio.h>

void Swap(int *a, int *b)
{
  //int temp = *a;
// 5 = 0101
//10 = 1010

     //   a =  1111
     //        0101
                //  1010 

    //        // 1010
                    
     //   b = 0101 = 5
     //   a = 1010  = 10

  *a = *a^*b;
  *b = *a^*b;
  *a = *a^*b;

}
int check_chan_le (int n)
{
  int num = n%10;
  if (n == 0)
  return  -1;

  if (num & 0x01 == 1)
  {
    return 0;
  }
  return 1;
}

int main()
{
  // int a = 5, b =10;
  // Swap(&a, &b);

  // printf("\n a = %d, b = %d", a, b);

int n = 1234;

if (check_chan_le(n) == 0)
{
  printf("\n %d la so le ", n);
}
else if (check_chan_le(n) == 1)
{
   printf("\n %d la so chan ", n);
}
else 
printf("\n n = 0");


}