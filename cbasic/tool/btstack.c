 
typedef int item; //kieu du lieu
struct Node
{
    item Data; //du lieu
    Node *Next; //link
};
typedef struct Stack
{
    Node *Top;
};
 
void Init (Stack &S); //khoi tao Stack rong
int Isempty(Stack S); //kiem tra Stack rong
int Len (Stack S); //Do dai Stack
void Push(Stack &S, item x); //them phan tu vao Stack
int Peak(Stack S); //Lay phan tu o dau Stack nhung khong xoa
int Pop(Stack &S); //Loai bo phan tu khoi Stack
void Input (Stack &S); //Nhap Stack
void Output(Stack S); //Xuat Stack
Node *MakeNode(item x); //Tao 1 Node
 
void Init (Stack &S) //khoi tao Stack rong
{
    S.Top = NULL;
}
 
int Isempty(Stack S) //kiem tra Stack rong
{
    return (S.Top == NULL);
}
 
int Len (Stack S)
{
    Node *P = S.Top;
    int i=0;
    while (P != NULL) //trong khi chua het Stack thi van duyet
    {
        i++;
        P = P->Next;
    }
    return i;
}
 
Node *MakeNode(item x) //tao 1 Node
{
    Node *P = (Node*) malloc(sizeof(Node));
    P->Next = NULL;
    P->Data = x;
    return P;
}
 
void Push(Stack &S, item x) //them phan tu vao Stack
{
    Node *P = MakeNode(x);
    P->Next = S.Top;
    S.Top = P;
}
 
int Peak(Stack S) //Lay phan tu o dau Stack nhung khong xoa
{
    return S.Top->Data;
}
 
int Pop(Stack &S) //Loai bo phan tu khoi Stack
{
    if (!Isempty(S))
    {
        item x = S.Top->Data; //luu lai gia tri
        S.Top = S.Top->Next; //Xoa phan tu Top
        return x;
    }
}
 
void Input (Stack &S) //nhap danh sach
{
    int i=0; 
    item x;
    do
    {
        i++;
        printf ("Nhap phan tu thu %d : ",i);
        scanf("%d",&x);
        if (x != 0) Push(S,x);
    } while(x != 0); //nhap 0 de ket thuc
}
 
void Output(Stack S)
{
    Node *P = S.Top;
    while (P != NULL)
    {
        printf("%d   ",P->Data);
        P = P->Next;
    }
    printf("\n");
}
 
int main()
{
    Stack S;
    Init(S);
    Input(S);
    Output(S);
 
    int lua_chon;
    printf("Moi ban chon phep toan voi DS LKD:");
    printf("\n1: Kiem tra Stack rong");
    printf("\n2: Do dai Stack");
    printf("\n3: Them phan tu vao Stack");
    printf("\n4: Xoa phan tu trong Stack");
    printf("\n5: Xuat Stack");
    printf("\n6: Thoat");
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&lua_chon);
        switch (lua_chon)
        {
            case 1:
            {
                if (Isempty(S)) printf("Stack rong !");
                else printf ("Stack khong rong !");
                break;
            }
            case 2:
            {
                printf("Do dai Stack: %d",Len(S));
                break;
            }
            case 3:
            {
                item x;
                printf ("Nhap phan tu can chen vao DS: ");
                scanf("%d",&x);
                Push(S,x);
                break;
            }
            case 4:
            {
                Pop(S);
                break;
            }
            case 5: 
            {
                Output(S);
                break;
            }
            case 6: break;
        }
    }while (lua_chon !=6);
    return 0;
}
