/*
Ho va Ten : Nguyen Van Quang
MSSV      : 20133099
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Time
{
	int h;
	int minute;
}TimeTask;

typedef struct CV
{
	char Namejob[40];
	struct Time starts;
	struct Time theend;
	char content[100];
	int leveljob;
	char work[40];
	struct CV *next;
}Work;

typedef struct BST
{
	int day;
	struct CV *date;
	struct BST *left;
	struct BST *right;
}TreeNode;

void DeleteNode(TreeNode *root);
void DisplayNode(TreeNode **p,int a);
TreeNode *Node_min(TreeNode *root);
int InDayAtoB(TreeNode *p,int a,int b);
int InDay(TreeNode *a,int b);
void MenuSearching(TreeNode *root);
void SearDay(TreeNode *root);
Work *AddWork();
int Isemtpy(TreeNode *s);
int TrueLevel();
void TrueTime(TimeTask *a);
int TrueDate(TimeTask *a,TimeTask *b);
int TrueDay();
Work * InsertWork(Work **top);
void AddNodeInsert(TreeNode **root);
TreeNode *AddNodeDate();
TreeNode *InsertTree(TreeNode *a,TreeNode *node);
void Prin(Work *p,int a);
void Prin2(TreeNode *p);
void Prin1();
void SearAtoB(TreeNode *root);

main()
{
	TreeNode *root;
	root =NULL;
	int imenu;
	while(1)
	{
		printf("\n==============MENU==============\n");
		printf("  1:Nhap them Cong Viec \n");
		printf("  2:Xem lich cong tac \n");
		printf("  3:Xoa lich Cong tac\n");
		printf("  4:Dieu chinh lich chinh\n");
		printf("  5:Thoat\n");
		printf("Moi ban chon chuc nang\n");
		scanf("%d",&imenu);
		while(getchar() != '\n');
		switch(imenu)
		{
			case 1 :
			{
				AddNodeInsert(&root);
				printf("%s\n","20");
				Prin1();
				printf("%s\n","21");
				Prin2(root);
				printf("%s\n","22");
				continue;
			}
			case 2 :
			{
				MenuSearching(root);
				continue;
			}
			case 3 :
			{
				DeleteNode(root);
				Prin1();
				printf("%s\n","21");
				Prin2(root);
				continue;
			}
			default :
			{
				printf("Input wroong!...\n");
                printf("Please input again!\n");
			}
			case 5 :
			{
				break;
			}
		}
		break;
	}
}

void TrueTime(TimeTask *a)
{
    while(1)
    {
    	scanf("%d:%d",&a->h,&a->minute);
    	while(getchar() !='\n');
    	while(getchar() !='\n');
    	if(a->h < 0|| a->h > 24 || a->minute <0 || a->minute > 60)
    	{
    		printf("\n Wrong Date \n Input again");
    	}
    	else
    		break;
    }
}

int TrueDate(TimeTask *a,TimeTask *b)
{
		if(a->h > b->h) return 0;
		else if((a->h == b->h) && a->minute > b->minute) return 0;
		else return 1;
}

int TrueDay()
{
	int a;
	while(getchar() !='\n');
	while(1)
	{
	printf("Enter day have work\n");
	scanf("%d",&a);
		if(a < 0 || a>30){
			printf("\n Wrong \n Input again");
		}
		else break;
	}
	return a;
}

int TrueLevel()
{
	int a;
	while(1)
	{
		printf("Work Level\n");
		scanf("%d",&a);
		while(getchar() !='\n');
		if(a < 0 || a > 4)
		{
			printf("\nWrong \n Input again");
		}
		else break;
	}
	return a;
}

int Isemtpy(TreeNode *s)
{
	return (s == NULL);
}
//=================================Tao node ==================================
Work *AddWork()
{
	Work *Node;
	Node = (Work*)malloc(sizeof(Work));
	if(Node == NULL)
	{
		printf("Memory Full\n");
	}
	printf("Name work :");
	fgets(Node -> Namejob,40,stdin);
	Node ->Namejob[strlen(Node ->Namejob) - 1] = '\0';
	
	printf("\nTime of Job working Starts DD:YY ");
		TrueTime(&Node->starts);

	printf("\nTime of Job working Theend DD:YY ");
		TrueTime(&Node->theend);

	printf("\nviec da lam chua :");
	fgets(Node->work,40,stdin);
	Node -> work[strlen(Node ->work) - 1] = '\0';

	printf("\nContent of Job :");
	fgets(Node ->content,100,stdin);
	Node -> content[strlen(Node ->content) - 1] = '\0';

	printf("\nlevel job\n%s : VeryImportant \n%s : Important\n%s : Normal\n%s : NotImportant\n","1","2","3","4");
	Node ->leveljob = TrueLevel();
	Node -> next = NULL;

	return Node;
}
//=============================chen node==============================================

TreeNode *InsertTree(TreeNode *a,TreeNode *node)
{  
		if(a == NULL)
		{
		 a = node;
		}
		else if( node -> day < a -> day)
		{
			a ->left = InsertTree(a->left,node);
		}
		else if(node -> day > a -> day)
		{
			a ->right = InsertTree(a ->right,node);
		}
	return a;
}
//============================chen cong viec ================================
Work *InsertWork(Work **top)
{
	Work *a;
	a = AddWork();
	Work *temp,*temp1;
	temp = (*top);
	temp1 = (*top);
	while(temp)
	{
		if(temp ->next == NULL)
		{
			temp ->next = a;
			printf("%s\n","2");
			break;
		}
		else if(TrueDate(&temp->theend,&a->starts) == 1)
		{
			temp1 -> next = a;
			printf("%s\n","3");
			a -> next = temp;
			printf("%s\n","4");
			break;
		}
		else
		{
			printf("%s\n","5");
			temp1 = temp;
			printf("%s\n","6");
			temp = temp ->next;
			printf("%s\n","7");	
		}
	}
}
// ====================================chen Node================================
TreeNode *AddNodeDate()
{
	int i,n;
	TreeNode *Node;
	Node = (TreeNode *)malloc( sizeof(TreeNode));
	Node -> day = TrueDay();
	//printf("%s\n","8");
	printf("So cong viec cua ngay la %d :",Node->day);
	scanf("%d",&n);
	while(getchar() !='\n');
	//printf("%s\n","9");
	Node ->date = NULL;
	//printf("%s\n","**");
	for(i = 0; i < n;i++)
	{
		if(Node->date == NULL)
		{
			Node->date = AddWork();
			continue;
		}
		//printf("%d===",i);
		InsertWork(&Node->date);
		//printf("%s\n","10");
	}
	Node -> left = NULL;
	Node -> right = NULL;
	return Node;
}
//================================Them Node ==================================
void AddNodeInsert(TreeNode **root)
{
	TreeNode *p;
	TreeNode *a;
	int i,m;
	printf("How many day have  work \n");
	scanf("%d",&m);
	//printf("%s\n","12");
	while(getchar() !='\n');

	for(i = 0;i < m;i++)
	{
		if((*root) == NULL)
	{
		(*root) = AddNodeDate();
	//printf("%s\n","11");
	continue;
	}
		a = (*root);
		p = AddNodeDate();
		//printf("%s\n","13");
		a = InsertTree(a,p);
		//printf("%s\n","14");
	}
	//printf("%s\n","+++");
	//Prin((*root)->date,(*root)->day);
	//printf("%s\n","++");
}
//=========================================Tao node=============================
/* a -> left -> left = NULL 
   a -> left -> left = node
   a -> left =*/

void Prin1()
{
	printf("%-5s%-10s%-10s%-10s%-10s%-10s%5s\n","Day","Name","Starts","theend","content","Viec","Important");
}

void Prin(Work *p,int a)
{
	while(p != NULL)
	{
		printf("%-5d",a);
		printf("%-10s%5d:%-5d%5d:%-5d%-10s%-10s%5d\n",p->Namejob,p->starts.h,p->starts.minute,p->theend.h
		,p->theend.minute,p->content,p->work,p->leveljob);
		p = p->next;
		//printf("%s\n","15");
	}
}
void Prin2(TreeNode *p)
{
	if(p != NULL)
	{
		//printf("%s\n","16"); 
		Prin(p ->date,p->day);
		Prin2(p->left);
		//printf("%s\n","17");
		Prin2(p->right);
		//printf("%s\n","18");
	}	
}
//======================MENU Searching ===========================================
void MenuSearching(TreeNode *root)
{
	int imenu;
	while(1)
	{
		printf("1  : Xem cong viec ngay \n");
		printf("2  : Xem cong viec chua lam\n");
		printf("3  : Xem cong viec da lam\n");
		printf("4  : Xem cong viec chuoi cac ngay\n");
		printf("5  : Exit\n");
		printf("Moi ban chon chuc nang\n");
		scanf("%d",&imenu);
		while(getchar() !='\n');
		switch(imenu)
		{
			case 1:
			{
				SearDay(root);
				continue;
			}
			case 4 :
			{
				SearAtoB(root);
				continue;
			}
			default :
			{
				printf("Input wroong!...\n");
                printf("Please input again!\n");
			}
			case 5 :
			break;
		}
		break;
	}
}

void SearDay(TreeNode *root)
{
	TreeNode *b;
	b = root;
	int a;
	printf("Moi ban nhap ngay can xem\n");
	scanf("%d",&a);
	while(getchar() !='\n');
	printf("%s\n","33");
	if(InDay(b,a)==0)
	{
		printf("Ngay %d KHONG co cong viec\n",a);
	}
}

int InDay(TreeNode *a,int b)
{
	if(a == NULL)
	{
		return 0;
	}
	else if((a ->day) == b )
	{
		printf("%s\n","30");
		Prin(a ->date,b);
		return 1;
	}
	else if(a->day > b)
	{
		printf("%s\n","31");
		InDay(a ->left,b);
	}
	else if(a ->day < b)
	{
		printf("%s\n","32");		
		InDay(a ->right,b);
	}
}

void SearAtoB(TreeNode *root)
{
	TreeNode *p;
	p = root;
	int a,b;
	printf("Ban muon xem cong viec tu ngay : ");
	scanf("%d",&a);
	while(getchar() !='\n');
	printf("\n toi ngay :");
	scanf("%d",&b);
	while(getchar() !='\n');
	if(InDayAtoB(p,a,b) == 0)
	{
		printf("KHONG co cong viec");
	}
}

int InDayAtoB(TreeNode *p,int a,int b)
{
	if(p == NULL)
	{
		return 0;
	}
	else if(a <= (p ->day) && (p ->day) <= b )
	{
		printf("%s\n","30");
		Prin(p ->date,p->day);
	}
		InDayAtoB(p ->left,a,b);	
		InDayAtoB(p ->right,a,b);
}

void DeleteNode(TreeNode *root)
{
	TreeNode *p;
	p = root;
	int a;
	printf("Moi ban nhap ngay muon xoa \n :");
	scanf("%d",&a);
	while(getchar() !='\n');
	DisplayNode(&p,a);
}

void DisplayNode(TreeNode **p,int a)
{
	if((*p) -> day < a)
	{
		DisplayNode(&(*p) -> right ,a);
		printf("%s\n","+++" );
	}
	else if((*p)->day > a)
	{
		DisplayNode(&(*p) -> left ,a);
		printf("%s\n","===" );
	}
	else if((*p) -> day == a)
	{
		if( ((*p) -> left) != NULL && ((*p) -> right) != NULL )
		{
			TreeNode *tmp;
			printf("%s\n","!!!" );
			tmp = Node_min((*p));
			printf("%s\n","@@@" );
			(*p) ->day = tmp ->day;
			printf("%s\n","###" );
			(*p) ->date = tmp ->date;
			printf("%s\n","^^^" );
			DisplayNode(&(*p)->right,(*p)->day);
			printf("%s\n","&&&" );
		}
		else
		{
			TreeNode *tmp;
			tmp = (*p);
			if(((*p)->left) == NULL) (*p) = (*p) -> right;
			else
			{
				if(( (*p)-> right) == NULL) (*p) = (*p)->left;
			}
			free(tmp);
		}
	}
}

TreeNode *Node_min(TreeNode *root)
{
	if(root->left == NULL)
	{
	printf("%s\n","$$$" );	
		return root;
	}
	else
		root = Node_min(root->left);
	printf("%s\n","~~~" );
	return root;
}

void SawpWork(Work **a,Work **b)
{
	strcpy((*a)->Namejob,(*b)->Namejob);
	(*a)->starts.h = (*b)->starts.h;
	(*a)->starts.minute = (*b)->starts.minute;
	(*a)->theend.h = (*b)->theend.h;
	(*a)->theend.minute = (*b)->theend.minute;
	strcpy((*a)->content,(*b)->content);
	(*a)->leveljob = (*b)->leveljob;
	strcpy((*a)->work,(*b)->work);		
}