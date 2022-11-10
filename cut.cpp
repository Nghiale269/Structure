
   fscanf(fptr,"\n******************************************************************************");
     fscanf(fptr,"\n\n\t\tThong tin sinh vien");
      fscanf(fptr,"\n");
      fscanf(fptr,"\nSTT \t Ho ten \t MSSV \t\t Diem LT \t Diem toan \t Diem CSDL  ");
      fscanf(fptr,"\n\n");
    for (int i = 0; i< n; i++)
    {
      fscanf(fptr,"%d", i+1);
     fscanf(fptr,"\t %s \t %s \t \t %.1f \t \t %.1f \t \t  %.1f \n", sinhvien[i].Ho_ten, sinhvien[i].Mssv, sinhvien[i].diem_laptrinh, sinhvien[i].diem_toan, sinhvien[i].diem_CTDL);

    }
    fscanf(fptr,"\n");
   fscanf(fptr,"\n\n******************************************************************************");
 printf("\nDoc xong !");  
  fclose(fptr); 