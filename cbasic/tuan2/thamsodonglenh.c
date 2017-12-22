int main(int argc, char* argv[]){
	
	int a,b,c ;
	if (argc!= 3)
	{
		/* code */
		printf("so luong tham so truyen vao khong dung\n");
	}
	else{
	a = *argv[1];
	b = *argv[2];
	printf("%d---------------%d\n",a,b );
	c = ((a + b) / 2 + abs(a-b) / 2);
	printf("so lon nhat la %c\n",c,c );
	}
}