#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

main()
{
    int a = 2;
    int *p1,*p2;
    int A[] = {8,5,4,3,5,2,1};
    printf("Mang ban dau la\n");
    printf("%d %d %d %d %d %d %d    \n",A[0], A[1],A[2],A[3],A[4],A[5],A[6] );
    p1 = (int*)malloc(sizeof(int));
    p2 = (int*)malloc(sizeof(int));
    p1 = p2 = A;
    int i = 0;
    while(A[i] != 0)
    {
        if(*p1 == a)
        {
            int j = i;
            while(A[j] != 0)
            {
                *(p2) = *(p2+1);
                p2 = &A[j];
                j++;
            }
            A[j-1] = 0;
        }
        else
        {
            i++;
            p1 = &A[i];
            p2 = p1;
        }
    }
    printf("Mang sau khi su dung la\n");
    i = 0;
    while(A[i]!=0)
    {
        printf("%d ",A[i] );
        i++;
    }
    printf("\n");
}