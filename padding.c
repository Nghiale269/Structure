#include<stdio.h>

int main()
{
    typedef struct xe{   
        
        char rr;
        int yy;
        int xxdx;
        double fdfd;
        char rrd;
        
    } xe_hoi ;
xe_hoi dap = {12, 'r', 45, 56, 7.2, '8'};

    printf("\n %d", sizeof (xe_hoi));

  
     printf("\n %d", &dap.rr);
      printf("\n %d", &dap.yy);
       printf("\n %d", &dap.xxdx);
        printf("\n %d", &dap.fdfd);
         printf("\n %d", &dap.rrd);

}