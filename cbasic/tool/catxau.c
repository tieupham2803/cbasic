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

main(){
    char s[] = "dkmquang";
    char *Nuon,temp[30],temp1[30];
    Nuon = catxau(s,temp,' ');
    printf("%s\n",Nuon );
    printf("%s\n",temp );
    // Nuon = catxau(Nuon,temp1,' ');
    // printf("%s\n",Nuon );
    // printf("%s\n",temp1 );
}