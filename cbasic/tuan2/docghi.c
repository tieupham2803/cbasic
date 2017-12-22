#include<stdio.h>
 enum{SUCCESS, FAIL, MAX_LEN = 81};
int main() {
   FILE *fp1, *fp2;
   char a[MAX_LEN];
 
   fp1 = fopen("lab1.txt", "r");
   if (fp1 == NULL) {
      puts("Khong the mo file nay");
      
   }
 
  
  else
  {
   fp2 = fopen("lab2.txt", "w"); 
    if (fp2 == NULL) {

      puts("Khong the mo file nay");
      fclose(fp1);
      
   }
   else{
   while(fgets(a,MAX_LEN,fp1) != NULL){
    fputs(a, fp2);
      printf("%s\n",a );
     }
   // do {
   //    a = fgetc(fp1);
   //    fputc(a, fp2);
   // } while (a != EOF);
    fclose(fp1);
    fclose(fp2);
  }
 }
 
   return(0);
}