#include<stdio.h>


int main()
{ int km;
  float cost;  
    printf("\nBan muon di bao nhieu km: ");

    scanf("%d", &km);
    if (km <= 1 && km >0)
        cost = km * 15000;
    else if (km <= 5 && km >1)
        cost = 15000 + (km - 1) * 13500;
    
    else if (km > 5){
         if (km >= 120)
         {
         cost = (15000 + 4 * 13500 +(km - 5) * 11000) * 0.9 ;
          printf("\n >120");
         }
         else{
        cost = 15000 + 4 * 13500 +(km - 5) * 11000;
        printf("\n >5"); }
    }
    else
        cost = -1 ;

    printf("\n gia tien = %.0f", cost);
        
}