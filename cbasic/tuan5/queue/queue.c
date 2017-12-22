
typedef struct model_t
{
  char name[30];
  char mssv[10];
  float diem;
} ElementType;
typedef struct n
typedef struct Node{
ElementType Element;
Node* Next; //pointer to next element
};
typedef Node* Position;
typedef struct{
Position Front, Rear;
} Queue;
