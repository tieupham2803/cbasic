#include <stdio.h>
#define ALPHABET_LEN 26
int main(void)
{
	/* code */
	int AA[ALPHABET_LEN] = {0};
	int i,a = 0;
	char c = '\0';
	printf("nhap vao chuoi ky tu, ket thuc bang chuoi xuong dong\n");
	c  = getchar();
	while(c != '\n'){
		if (c <='z' && c >='a')
		{
			/* code */
			++AA[c - 'a'];
			c = getchar();
			
		}

	}

	printf("askdjask\n");
	for(i = 0; i< 26 ;++i){
	if (AA[i]>0)
	printf("ky tu %c xuat hien %d lan \n" ,'a'+i , AA[i]);
}
	return 0;
}