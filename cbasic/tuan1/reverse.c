#include <stdio.h>

int main(void){
	int i, A[10];
	printf("Nhap vao 10 phan tu cua mang\n");
	for ( i = 0; i < 10; ++i)
	{
		/* code */
		scanf("%d",&A[i]);
	}
	printf("Cac phan tu cua mang theo thu tu nguoc lai la\n");
	for ( i = 9; i >=0; i--)
	{
		/* code */
		printf("%d\n",A[i] );
	}
	return 0;
}