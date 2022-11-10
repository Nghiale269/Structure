// nhap thong tin sinh vien
#include<stdio.h>
#include<string.h>
#include<iomanip>
////////////////////////////////////////////
void xoa_ktr_dau_cuoi(char *);
void chuan_chuan_hoa_chuoi (char *source)
{
    xoa_ktr_dau_cuoi(source);
    int n = strlen(source);
    if (source[0] >= 79 && source[0] < 122 )
    {
        source[0] -= 32;
    }
    for (int i = 1; i< n; i++)
    {
        if (source[i] == ' ')
        {
            if (source[i+1] >= 79 && source[i+1] < 122 )
             {
                source[i+1] -= 32;
             }
        }
    }
}
// xóa khoan trang đầu và cuối
void xoa_ktr_dau_cuoi(char * source)
{
    int n = strlen(source);
    while(source[0] == ' ' || source[n-1] == ' ')
    {
        int vt = 0;
        if (source[0] == ' ')
        {
            vt = 0;
        }
        else if (source[n-1] == ' ')
        {
            vt = n-1;
        }


        for (int i = vt; i < n - 1; i++)
            {
                source[i] = source[i+1];
            }
            source[n-1] = '\0';
    }
         
    
}
/////////////////////////////////////
typedef struct sinh_vien
{
    char Ho_ten[20];
    char Mssv[20];
    float diem_laptrinh;
    float diem_toan;
    float diem_CTDL;
    float diem_tb;

}sv_t;
//
void nhap_1 (sv_t &sinhvien)
{
     do
        {
            fflush(stdin);
            printf("\nNhap ho ten sv: ");
            gets(sinhvien.Ho_ten);
            chuan_chuan_hoa_chuoi(sinhvien.Ho_ten);
            if (strlen(sinhvien.Ho_ten)> 20)
            {
                printf("\n nhap lai!!");
            }  
        } while (strlen(sinhvien.Ho_ten)> 20);
          fflush(stdin);
        printf("nhap MSSV: ");
        gets(sinhvien.Mssv);
        printf("nhap diem lap trinh: ");
        scanf("%f", &sinhvien.diem_laptrinh);
        printf("\nNhap diem toan: ");
        scanf("%f", &sinhvien.diem_toan);
        printf("\nNhap diem CTDL: ");
        scanf("%f", &sinhvien.diem_CTDL);
}

void nhap_in4 (sv_t sinhvien[], int &n)
{
     printf("\n nhap so luong sinh vien ");
    scanf("%5d", &n);
    int i;
    for (i = 0; i< n; i++)
    {
         printf("\n********************************Nhap sinh vien thu %d**************************", i+1);
            nhap_1(sinhvien[i]);

    }
}
void xuat_1(sv_t sinhvien)
{
    
    printf("%-20s %-15s %-10.1f %-15.1f %-15.1f\n", sinhvien.Ho_ten, sinhvien.Mssv, sinhvien.diem_laptrinh, sinhvien.diem_toan, sinhvien.diem_CTDL);
    

}
///
void in_in4 (sv_t sinhvien[], int n)
{
   
    int i;
     printf("\n******************************************************************************");
      printf("\n\n\t\tThong tin sinh vien");
       printf("\n");
       printf("\n%s %15s %15s %15s %15s %15s", "STT" , "Ho ten", "MSSV", "Diem LT",  "Diem toan", "Diem CSDL");
       printf("\n\n");
    for (i = 0; i< n; i++)
    {
       printf("%-10d", i+1);
       xuat_1(sinhvien[i]);

    }
     printf("\n");
    printf("\n\n******************************************************************************");
}
// xêp loai sinh viên

void Xep_loai (sv_t sinh_vien[], int n)
{
     float dtb;
    for (int i = 0; i< n; i++)
    {
         dtb = (sinh_vien[i].diem_laptrinh + sinh_vien[i].diem_toan +sinh_vien[i].diem_CTDL) /3.0;
        if (dtb > 9.8)
        {
            printf("\n sinh vien thu %d loai Xuat sac", i+1);
        }
        else if (dtb >= 8)
        {
              printf("\n sinh vien thu %d loai gioi", i+1);
        }
        else if (dtb < 8 && dtb >= 6.5)   // < 8
        {
              printf("\n sinh vien thu %d loai kha", i+1);

        }
        else if (dtb < 4)
              printf("\n sinh vien thu %d loai yeu", i+1);
        else 
              printf("\n sinh vien thu %d loai trung binh", i+1);


    }
   
}
// sắp xếp theo điểm trung bình
void tinhdiemtrungbinh (sv_t sinh_vien[], int n)
{
     for (int i = 0; i< n; i++)
    {
        sinh_vien[i].diem_tb = (sinh_vien[i].diem_laptrinh + sinh_vien[i].diem_toan +sinh_vien[i].diem_CTDL) /3.0;

    }
}
void sap_xep_dtb (sv_t sinh_vien[], int n)
{
    tinhdiemtrungbinh(sinh_vien, n);
    for (int i = 0; i< n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (sinh_vien[i].diem_tb < sinh_vien[j].diem_tb)
            {
                sv_t temp = sinh_vien[i];
                sinh_vien[i] = sinh_vien[j];
                sinh_vien[j] = temp;

            }
        }

    }
}
// sắp xếp theo tên sinh viênedfaedf
// tạo hàm lấy tên sv rồi so sánh
char* lay_ten (char* sinhvien)
{
    int dau = 0;
    char sub[10];
     for (int l = strlen(sinhvien) -1 ; l >=0 ; l--)
        {
            if (sinhvien[l] == ' ')
            {
                while (sinhvien[l] != '\0')
                {
                    sub[dau++] = sinhvien[l+1];
                    l++;
                }
 
                break;
                
            } 
        }
        char *ten = sub;
     
        return ten;

}
void sap_xep_ten (sv_t sinhvien[], int n)
{
    
    for (int i = 0; i< n -1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
           
            char ten1[10];
            char ten2[20];

            strcpy(ten1, lay_ten(sinhvien[i].Ho_ten));
             strcpy(ten2, lay_ten(sinhvien[j].Ho_ten));

             printf("\n strcmp = %s",ten1) ;
            printf("\n strcmp = %s",ten2 );
        

           //if (strcmp(lay_ten(sinhvien[i].Ho_ten) , lay_ten(sinhvien[j].Ho_ten)) > 0)
            
          
           if (strcmp(ten1, ten2 )> 0)
           {
                sv_t temp = sinhvien[i];
                sinhvien[i] = sinhvien[j];
                sinhvien[j] = temp;
           }
        }

        
    }
}
// tim kiem xinh vien theo msv
int check_Mssv (char * src1, char *src2)
{
    if (strlen(src1) != strlen(src2))
    {
        return 0;
    }
    for (int i = 0; i < strlen(src1); i++ )
    {
        if (src1[i] != src2[i])
        {
            
            return 0;
        }
    }
    return 1;
}
void tim_kiem_mssv (sv_t sinhvien[], int n)
{
    int check = 0;
    char mssv[20];
    fflush(stdin);
    printf("\nNhap MSSV can tim ");
    gets(mssv);
    for (int i = 0; i< n; i++)
    {
        if (check_Mssv(sinhvien[i].Mssv, mssv) == 1)
        {
            xuat_1(sinhvien[i]);
            break;
        }
    }
    if(check == 0)
    {
        printf("\n Khong tim thay!!!");
    }
}
// them 1 sinh vien
void them_sv(sv_t sinhvien[], int &n)
{
    printf("\n************************** Them sinh vien ************************");
     int vt;
     printf("\nNhap vi tri muon them ");
     scanf("%d", &vt);
     vt --;
    if (vt < 0) vt = 0;
    if (vt > n) vt = n;
    for (int i = n; i > vt ; i--)
    {
        sinhvien[i] = sinhvien[i-1];
    }
    nhap_1(sinhvien[vt]);
    n++;
}
// xóa sinh vien
void xoa_sv (sv_t sinhvien[], int &n)
{
     printf("\n************************* Xoa sinh vien *************************");
     int vt;
     printf("\nNhap vi tri muon xoa ");
     scanf("%d", &vt);
     vt --;
    if (vt < 0) vt = 0;
    if (vt > n) vt = n;
    for (int i = vt; i < n-1 ; i++)
    {
        sinhvien[i] = sinhvien[i+1];
    }
   
    n--;
}
//
void Ghi_file (sv_t sinhvien[], int n)
{
   
    FILE *fptr;
    fptr = fopen("G:\\C_C++\\17.File\\program.txt","w"); 
     if(fptr == NULL)
   {
      printf("Error! ghi");   
                
   }
    if (fptr)
    {
        for (int i = 0; i< n; i++)
        {
        fprintf(fptr, "%-15s %s %.1f %.1f %.1f\n", sinhvien[i].Ho_ten, sinhvien[i].Mssv, sinhvien[i].diem_laptrinh, sinhvien[i].diem_toan, sinhvien[i].diem_CTDL);
       
       // fprintf(fptr, "%-20s %-15s %-8.1f %-15.1f %-15.1f\n", sinhvien[i].Ho_ten, sinhvien[i].Mssv, sinhvien[i].diem_laptrinh, sinhvien[i].diem_toan, sinhvien[i].diem_CTDL);

        }
    }
    
 printf("\nGhi xong !");  
  fclose(fptr); 
}
//
void Doc_file (sv_t sinhvien[], int &n)   //%20s %15s %8.1f %15.1f %15.1f\n
{
   
    FILE *fptr;
    fptr = fopen("G:\\C_C++\\17.File\\program.txt","r"); 
     if(fptr == NULL)
   {
      printf("Error! doc"); 
      exit(1);  
                
   }
    int i = 0;

   
        for (;;)
    {
        
        fscanf(fptr, "%15[^\n] %s %f %f %f\n", sinhvien[i].Ho_ten, sinhvien[i].Mssv, &sinhvien[i].diem_laptrinh, &sinhvien[i].diem_toan, &sinhvien[i].diem_CTDL);
        //fscanf(fptr, "%20[^\n] %15s %8f %15f %15f\n", sinhvien[i].Ho_ten, sinhvien[i].Mssv, &sinhvien[i].diem_laptrinh, &sinhvien[i].diem_toan, &sinhvien[i].diem_CTDL);
            
            i++;

            if (feof(fptr))
            {
                break;
            }
   }

    fclose(fptr); 
    n = i;
    printf("\n n = %d",i);
 printf("\nDoc xong !");  
  

}
// menu
void menu()
{
    printf("\n*===================================Quan li sinh vien*==========================================");
    printf("\n* 1. Nhap danh sach sinh vien.                                                                  ");
    printf("\n* 2. xuat danh sach sinh vien.                                                                  ");
    printf("\n* 3. Sap xep theo diem trung binh.                                                              ");
    printf("\n* 4. Tim MSSV.                                                                                  ");
    printf("\n* 5. Them sinh vien.                                                                            ");
    printf("\n* 6. Xoa sinh vien.                                                                             ");
    printf("\n* 7. Ghi file.                                                                                  ");
    printf("\n* 8. Doc file.                                                                                  ");
    printf("\n* 9. Thoat.                                                                                     ");
    printf("\n*===============================================================================================");
}



int main()
{
    system("cls");
    int n;
    sv_t sinhvien[100];
  
    int choice = 8;
    while (choice != 9)
    {
        menu();
    
        printf("\nNhap lua chon ");
        scanf("%d", &choice);
      

        switch (choice)
        {
            case 1:
            {
                system("cls");
                nhap_in4(sinhvien, n);
                system("cls");
             
                break;

            }

            case 2:
            {
                system("cls");
                system("cls");
                in_in4(sinhvien, n);
             
                 break;
            }
            case 3:
            {
                system("cls");
                sap_xep_dtb(sinhvien, n);
             
                break;
            }
            case 4:
            {
                system("cls");
                tim_kiem_mssv(sinhvien, n);
             
                break;
            }
            case 5:
            {
                system("cls");
                them_sv(sinhvien, n);
                system("cls");
             
                break;
            }
            case 6:
            {
                system("cls");
                xoa_sv(sinhvien, n);
             
                break;
            }
            case 7:
            {
                system("cls");
                Ghi_file(sinhvien, n);
                break;
            }
            case 8:
            {
                system("cls");
                Doc_file(sinhvien, n);
                break;
            }
            case 9:
            {
                system("cls");
                printf("\n\n\t\t\t\t********* Thoat************");
            }
        }
    }
}