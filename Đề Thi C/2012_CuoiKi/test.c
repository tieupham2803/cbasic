#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct phoneaddress {
	char name[20];
	char tel[11];
	char email[25];

}phoneaddress;
typedef struct NodeType{
	phoneaddress Key;
	struct NodeType* left, *right;
} NodeType;

typedef NodeType* TreeType;

TreeType Search(char* email,TreeType Root)
{
	if (Root == NULL) 
		return NULL; // not found
	else if (strcmp((Root->Key).email, email) == 0)
		return Root;
	else if (strcmp((Root->Key).email, email) < 0)
		return Search(email,Root->right); /*Tiếp tục tìmtrong cây con phải*/
	else
	return Search(email,Root->left); /*Tiếp tục tìm trong cây con trái*/
}

void InsertNode(phoneaddress x,TreeType **Root )
{
	if (*Root == NULL){
		*Root=(NodeType*)malloc(sizeof(NodeType));
		(*Root)->Key = x;
		(*Root)->left = NULL;
		(*Root)->right = NULL;
	}
	else if (strcmp(((*Root)->Key).email, x.email) > 0)
		InsertNode(x, (*Root)->left);
	else if (strcmp(((*Root)->Key).email, x.email) < 0)
		InsertNode(x,(*Root)->right);
}

void printPreorder(TreeType Root) // duyet cay theo thu tu truoc: con trai -> goc -> cn phai
{
	
	if (Root != NULL) {
		printf("%s ", Root->Key.email);		//2
		printPreorder(Root->left);			//1
		printPreorder(Root->right);			//3
	}
}

int main( )
{
	FILE *fp;
	phoneaddress phonearr[MAX];
	TreeType root;
	phoneaddress x;
	// int i, irc; // return code
	// int n=5;
	// //Đọc lại file này vào mảng
	// if ((fp = fopen("dulieu.txt","rb")) == NULL){
	// 	printf("Can not open %s.\n", "dulieu.txt");
	// return -1;
	// }
	// irc = fread(phonearr, sizeof(phoneaddress), n, fp);
	// fclose(fp);
	// for (i=0; i<n; i++)
	// 	root = InsertNode(phonearr[i],&root);

	// printPreorder(root);
	

	return 0;
}