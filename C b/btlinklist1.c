#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Birthday
    {
        int date, month, year;
    }a;

	typedef struct Node
	{
	char k[5];
	char lop[10];
	char hovaten[40];
	struct Birthday brithday;
	char quequan[40];
    struct Node *next;
	}Danhsach;

Danhsach *top = NULL;
    int tso,tscu;

// **********************Nguyen mau ham ************************************
    Danhsach *StratNodemoi(Danhsach *first);
Danhsach *StratNode(Danhsach *first);
Danhsach *AddedNode(Danhsach *first);
void Printf(Danhsach *first);
Danhsach * LocaInsert();
int TrueDate(int day,int month,int year);
void Full();
int IsEmpty(Danhsach *first);
void Search(Danhsach* p);
int MenuInputlist();
void IntheoClass(Danhsach *p);
void Intheokhoa(Danhsach *p);
int ReadNode();
int InsertNode(Danhsach *top);
void Printf(Danhsach *first);
void Printf1(Danhsach *temp);
void DeleteList(Danhsach *p);
Danhsach *InsertHead(Danhsach *p);
Danhsach * Themnode(Danhsach *p);

//*********** Ham Main ********************************************
main()
{
    FILE *ptr;
    char filename1[] = "ds.dat";
    int imenu,inum = 0;
    tso = tscu = 0;
    Danhsach *node;
    ReadNode();

    while(1)
    {
    printf("\t MENU \t\n");
    printf("1  :Doc du lieu o file va nhap them\n");
    printf("2  :In danh sach\n");
    printf("3  :Tim sinh vien\n");
    printf("5  :Thoat\n");
    printf("Moi ban chuc nang \n");
    scanf("%d",&imenu);
    while(getchar() !='\n');
    switch(imenu)
    {
            case 1 :
            {
                InsertNode(top);
                Printf(top);
                continue;
            }
            case 2 :
            {
                MenuInputlist();
                continue;
            }
            case 3 :
            {
                Search(top);
                continue;
            } 
            default :{
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
    if (tso != tscu)
    {
        if((ptr = fopen(filename1,"wb"))==NULL)
        {
            printf("Can not file\n");

        }
        else

        for(node = top;node != NULL;node = node ->next)
        {
            fwrite(node,sizeof(Danhsach),1,ptr);
            inum++;
        }
         printf("So ho so ghi la %d \n",inum);
    }
    //DeleteList(top);
}
/* Tao node */
Danhsach *StratNode(Danhsach *first)
{   
    Danhsach *temp;
    temp = (Danhsach*)malloc(sizeof(Danhsach));
    if(temp == NULL) 
    {
        Full();
        return NULL;
    }

    printf("Khoa :");
    fgets(temp ->k ,5,stdin);
    temp->k[strlen(temp->k) - 1] = '\0';
    printf("\nLop :");
    fgets(temp ->lop ,10,stdin);
    temp->lop[strlen(temp->lop) - 1] = '\0';
    printf("\nHovaTen :");
    fgets(temp ->hovaten ,40,stdin);
    temp->hovaten[strlen(temp->hovaten) - 1] = '\0';
    while(1)
    {
        printf("Nhap nhay thang nam sinh aa/bb/cccc \n");
        scanf("%d",&temp ->brithday.date);
        while(getchar()!='\n');
        scanf("%d",&temp ->brithday.month);
        while(getchar()!='\n');
        scanf("%d",&temp ->brithday.year);
        while(getchar()!='\n');
        if(TrueDate(temp ->brithday.date,temp -> brithday.month,temp -> brithday.year) == 0)
            printf("wroong Date \n");
        else
            break;
    }
    printf("\nQue Quan :");
    fgets(temp ->quequan ,40,stdin);
    temp->quequan[strlen(temp->quequan) - 1] = '\0';
    temp ->next = first;
    first = temp;
    return temp;
}
//****************************************************************************************
Danhsach * AddedNode(Danhsach *first) // ham them node 
{
    Danhsach *temp;
    temp =(Danhsach*)malloc(sizeof(Danhsach));
    if(temp == NULL) 
    {
        Full();
        return NULL;
    }
    printf("Khoa :");
    fgets(temp ->k ,5,stdin);
    temp->k[strlen(temp->k) - 1] = '\0';
    printf("\nLop :");
    fgets(temp ->lop ,10,stdin);
    temp->lop[strlen(temp->lop) - 1] = '\0';
    printf("\nHovaTen :");
    fgets(temp ->hovaten ,40,stdin);
    temp->hovaten[strlen(temp->hovaten) - 1] = '\0';
    while(1)
    {
        printf("Nhap nhay thang nam sinh aa/bb/cccc \n");
        scanf("%d",&temp ->brithday.date);
        while(getchar()!='\n');
        scanf("%d",&temp ->brithday.month);
        while(getchar()!='\n');
        scanf("%d",&temp ->brithday.year);
        while(getchar()!='\n');
        if(TrueDate(temp ->brithday.date,temp -> brithday.month,temp -> brithday.year) == 0)
            printf("wroong Date \n");
        else
            break;
    }
    printf("\nQue Quan :");
    fgets(temp ->quequan ,40,stdin);
    temp->quequan[strlen(temp->quequan) - 1] = '\0';
    temp ->next = first ->next;
    first ->next= temp;
    return temp;
} 
// ****************************************************************************************
void Printf(Danhsach *first)  // ham in danh sach
{
    Danhsach *temp;
    temp = first;
    printf("\n%-10s%-10s%-20s%-20s%20s \n","Khoa","Lop","HovaTen","Ngay Sinh","Que Quan");
    while(temp)
    {
        Printf1(temp);
        temp = temp ->next;
    }
}
//********************************************************************************************

void Printf1(Danhsach *temp)
{
    printf("%-10s%-10s%-20s%2d/%2d/%-7d%20s \n",temp->k,temp->lop,temp->hovaten,temp->brithday.date,
        temp->brithday.month,temp->brithday.year,temp->quequan);
}
//*******************************************************************************************
Danhsach *LocaInsert()  // ham chon vi tri can chen 
{
    char a[40];
    Danhsach *p,*begin;
    p = top;
    printf("Moi ban nhap ten \n");
    fgets(a,40,stdin);
    a[strlen(a) - 1] = '\0';
    while(p)
    {
        begin = p;
        if((p -> next) == NULL)
        {
            return p;
        }
        if(strcmp((p ->hovaten),a) < 0)
        {
            return begin;          
        }
        if(strcmp((p -> hovaten),a) > 0 || strcmp((p -> hovaten),a) == 0)
        {
            return p;
        }
        p =p ->next;
    }
}
//*************************************************************************
int TrueDate(int day,int month,int year)// 0977335098 ham hop ngay thang nam
{
    if((day <= 0) || (month <= 0) || (month > 12) || (year < 0) || (year > 2014)) return 0;
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: if(day > 31) return 0;

        case 2:
        {
            if((year % 400 == 0) || (year %4 == 0 && year % 100 != 0)) 
                if(day > 28) return 0;
            else
                if(day > 29) return 0;
        }
        case 4:
        case 6:
        case 9:
        case 11: if(day >30) return 0;
    }
return 1;
}
// Loi ham malloc 
void Full()
{
    printf("Memory full \n");
}
//*********** Kiem tra rong *****************
int IsEmpty(Danhsach *first)
{
    return (first == NULL);
}

// ***************Tim kiem ***************************************************
void Search(Danhsach* p)
{
    Danhsach *temp;
    temp = p;

    char a[40];
    printf("Moi ban nhap ten \n");
    fgets(a,40,stdin);
    a[strlen(a) - 1] = '\0';
    printf("\n%-10s%-10s%-20s%-20s%20s \n","Khoa","Lop","HovaTen","Ngay Sinh","Que Quan");


    while(temp)
    {
    if(strcmp(temp ->hovaten ,a) == 0)
        {
            Printf1(temp);
        }
        temp = temp->next;
    }
}
//***********************In ********************
int MenuInputlist()
{
    while(1)
    {
    int imenu;
    printf("***********MENU***********\n");
    printf("1 - In theo khoa \n");
    printf("2 - In theo Class \n");
    printf("3 - Thoat\n");
    printf("Moi ban chon chuc nang \n");
    scanf("%d",&imenu);
    while(getchar()!='\n');
        switch(imenu)
        {
            case 1:
            {
                Intheokhoa(top);
            continue;
            }
            case 2:
            {
                IntheoClass(top);
                continue;
            }
            default :
            {
                printf("Input wroong!...\n");
                printf("Please input again!\n");
            }
            case 3 :
            break;
        }
        break;
    }

}
//***************************In danh sach theo khoa*****************************************
void Intheokhoa(Danhsach *p)
{
    Danhsach *temp;
    temp = p;
    char a[10];
    printf("Moi ban nhap khoa \n");
    fgets(a,10,stdin);
    a[strlen(a) - 1] = '\0';
    printf("\n%-10s%-10s%-20s%-20s%20s \n","Khoa","Lop","HovaTen","Ngay Sinh","Que Quan");

    while(temp)
    {
        if(strcmp(temp ->k,a)==0)
        {
        Printf1(temp);
        }

        temp = temp ->next;
    }
}
//*********************In danh sach theo lop***********************************
void IntheoClass(Danhsach *p)
{
    Danhsach *temp;
    temp = p;
    char a[10];
    printf("Moi ban nhap Class \n");
    fgets(a,10,stdin);
    a[strlen(a) - 1] = '\0';
    printf("\n%-10s%-10s%-20s%-20s%20s \n","Khoa","Lop","HovaTen","Ngay Sinh","Que Quan");

    while(temp)
    {
        if(strcmp(temp -> lop,a) == 0)
        {
        Printf1(temp);
        }
        temp = temp -> next;
    }
}
//******************Ham doc file *******************************************8
int ReadNode()
{
    Danhsach *p;
    p = (Danhsach *)malloc(sizeof(Danhsach));
    int  num,i;
    FILE *ptr;
    char filename1[] = "ds.dat";
    if((ptr = fopen(filename1,"rb")) == NULL)
    {
        printf("Can not file \n");
       top = StratNode(top);
    }
    else
    {
        fseek(ptr, 0, SEEK_END);
        tso = ftell(ptr) / sizeof(Danhsach);
        rewind(ptr);
        tscu = tso;
        printf("%d***\n",tso);

        for(i = 0;i < tso;i++)
        {
            printf("%d**** \n",i);
          fread(p, sizeof(Danhsach),1, ptr);
          if(IsEmpty(p)) 
          {
            top = StratNode(top);
          }
          else 
            if(i == 0)
            {
             top = p = StratNodemoi(p);
            }
            p = Themnode(p);
        }
            Printf(top);
        fclose(ptr);
    }
    return 1;
}
//**************************************Chonvi tri va them node *********************
int InsertNode(Danhsach *top)
{
    Danhsach *S1;
    int i,them;
    printf("So Sinh vien muon them la \n");
    scanf("%d",&them);
    while(getchar() != '\n');

    for(i = tso;i < tso+them;i++)
    {
        S1 = LocaInsert();
        S1 = AddedNode(S1);
    }
    tso = tso +them;
    return 1;
}

void DeleteList(Danhsach *p)
{
    Danhsach *a;
    if(IsEmpty(p))
    {
        a = p;
        p -> next =p; 
    }
    free(a);
}

Danhsach *InsertHead(Danhsach *p)
{
    Danhsach *temp;
    temp = (Danhsach *)malloc( sizeof(Danhsach));
    temp -> next = p ->next;
    p -> next = temp;
    return temp;
}

Danhsach * Themnode(Danhsach *p)
{
    Danhsach *Node;
    Node = (Danhsach *)malloc(sizeof(Danhsach));
    Node ->next = p -> next;
    p -> next = Node;
    return Node;
}

Danhsach *StratNodemoi(Danhsach *first)
{
    first ->next= NULL;
    return first;
}