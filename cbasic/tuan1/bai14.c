#include<stdio.h>
 
int main() {
   FILE *fp1, *fp2;
   char a;
 
   fp1 = fopen("lab1.c", "r");
   if (fp1 == NULL) {
      puts("Khong the mo file nay");
      
   }
 
  
  else
  {
   fp2 = fopen("lab2.c", "w"); 
    if (fp2 == NULL) {

      puts("Khong the mo file nay");
      fclose(fp1);
      
   }
   else{
   while((a =fgetc(fp1)) != EOF){
    fputc(a, fp2);
    putchar(a);
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