
#include <stdio.h>

void main()
{
 int a;
char Mang1[10] = {0,0,1,2,3,4,5,6,2,8};
char Mang2[10] = {0,0,1,2,3,4,5,6,7,2};
 a = compare_arrays(Mang1,Mang2,11);
 printf("%d\n",a );
}

int compare_arrays(int arr1[],int arr2[], int size){
	int i =0;
	for (i = 0;i < size; i++ ){
	if(arr1[i] != arr2[i]){
		return 0;
}
return 1;
}
}