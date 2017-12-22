#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *catxau(char *a,char *b,char c)    
{
    int i,j= 0,k = 0;
    for(i = 0;i < strlen(a) + 1;i++)
    {
        if(a[i]== c)
        {
            b[i] = '\0';
            j = i + 1; break;
        }
        b[i] = a[i];
        if(i == strlen(a))
        {
            b[i] = '\0';    
        }
    }
    for(i = 0;i < strlen(a) ;i++)
    {
        a[i] = a[i+j];
    }
    return a;
}
 main() {
   FILE *fp1, *fp2,*fp;
   int n,i=0,k,diem1,diem2,mangdiem[20];
   char a,c,diem;
   char sbd[10],ten[30],s[100], xxx[10],*Nuon,temp[30],temp1[30];



   fp1 = fopen("sinhvien.dat", "r");
   if (fp1 == NULL) 
      puts("Khong the mo file nay");
      
   
 
  
  else
  {



   fp2 = fopen("sinhvien2.dat", "w"); 
    if (fp2 == NULL) {

      puts("Khong the mo file nay");
      fclose(fp1);
      
   }
   else{
 
    fgets(xxx,50,fp1);
    printf("%3s\n",xxx);
    n=atoi(xxx);
    // fscanf()
    // printf("%d",i+1 );
    //   fgets(s,41,fp1);
    //   printf("%41s",s );
    //       fgets(s,6,fp1);
    //   printf("%4s\n",s );
    //      printf("%d",i+1 );
    //   fgets(s,41,fp1);
    //   printf("%41s",s );
    //       fgets(s,5,fp1);
    //   printf("%4s",s );
    // for (i = 0; i < n; ++i)
    // {
    //   /* code */
    //   printf("%d",i+1 );
    //   fgets(s,30,fp1);
    //   printf("%s",s );
    // }
 // printf("%d",i+1 );
 //      fgets(s,41,fp1);
 //      printf("%41s\n",s );
 //          fgets(s,5,fp1);
 //          Nuon =catxau(s,temp,'.');
 //          printf("%2s\n",Nuon);
 //          printf("%2s\n",temp);
      // printf("%2s.%2s\n",temp,Nuon);
 for (i = 0; i < n-1; ++i)
    {
      /* code */
      printf("%d",i+1 );
      fgets(s,41,fp1);
      printf("%41s",s );
      fgets(s,6,fp1);
      Nuon =catxau(s,temp,'.');
      mangdiem[i]= atoi(temp);
          // printf("%d\n",mangdiem[i] );
      printf("%2s.%3s\n",temp,Nuon);
    }
      printf("%d",n );
      fgets(s,41,fp1);
      printf("%41s",s );
      fgets(s,6,fp1);
      Nuon =catxau(s,temp,'.');
      mangdiem[n-1]= atoi(temp);
      printf("%2s.%2s\n",temp,Nuon);
    
   fp = fopen("sinhvien.dat", "r");
   if (fp == NULL) 
      puts("Khong the mo file nay");
    else{
     fgets(xxx,50,fp);
      for (i = 0; i <= n-1; i++)
      {
        /* code */
         fgets(s,60,fp);
        // printf("%d\n",mangdiem[i] );
      
        if(mangdiem[i]>=5){
           
     
         printf("%s",s );
            fputs(s,fp2);
        }

        else continue;
        // printf("%d\n",mangdiem[i] );
      }
      }
   }
  
    fclose(fp1);
    fclose(fp2);
  }
 
 
   // return(0);
}