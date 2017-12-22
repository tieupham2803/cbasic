# include <stdio.h>
# include <stdlib.h>

struct node {
	int data;
	struct node *link;
};
struct node *push(struct node *p, int value)
{
	struct node *temp;
	temp= (struct node *)malloc(sizeof(struct node));
	if(temp==NULL) {
		printf("không còn bộ nhớ, Error!\n");
		exit(0);
	}
	temp->data = value;
	temp->link = p;
	p = temp;
	return(p);
}
struct node *pop(struct node *p, int
*value)
{
	struct node *temp;
	if(p==NULL)
	{
		printf(" Stack rỗng,không thể pop");
		exit(0);
	}
	*value = p->data;
	temp = p;
	p = p->link;
	free(temp);//lưu ý: giá trị của phần tử top phải được ghi lại trước khi thực hiện phép toán pop
	return(p);
}

void main()
{
	struct node *top = NULL;
	int n,value;
	do
	{
	do
	{
		printf("nhập phần tử để push vào\n");
		scanf("%d",&value);
		top = push(top,value);
		printf("nhập 1 để tiếp tục\n");
		scanf("%d",&n);
	} while(n == 1);

	printf("nhập 1 để pop 1 phần tử\n");
		scanf("%d",&n);
		while( n == 1)
		{
	top = pop(top,&value);
	printf("giá trị được pop ra là:%d\n",value);
	printf(" nhập 1 để pop 1 phần tử\n");
	scanf("%d",&n);
}
printf(" nhập 1 để tiếp tục\n ");
scanf("%d",&n);
} while(n == 1); 
}