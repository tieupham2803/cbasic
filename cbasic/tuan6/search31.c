#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct products
{
    int id;
    char name[30];
    char description[100];
    int price;
    int quantity;
} product;

typedef struct list
{
    product data;
    struct list *next;
} node;

node *root = NULL;
int linked_list_no_elements = 0;

int is_Numeric(char *string)
{
    while(*string != '\0')
    {
        if(*string < '0' || *string > '9')
            return 0;
        string ++;
    }
    return 1;
}

void append()
{
    node *new;
    char id[5];
    int flag = 0; // raises flag if id entered is not a nummber //
    while(1)
    {
        new = (node*) malloc(sizeof(node));
        new->next = NULL;
        do
        {
            printf("Enter product's id: ");
            scanf("%[^\n]%*c", id);
            if(!is_Numeric(id)) // input is not a number //
            {
                printf("Exit!\n");
                free(new);
                flag = 1;
                break;
            }
            else // input is a number //
            {
                new->data.id = atoi(id);
                if(new->data.id < 101 || new->data.id > 500)
                    printf("Invalid! Please re-enter!\n");
            }
        }
        while(new->data.id < 101 || new->data.id > 500);
        if(flag == 1)
            break;
        printf("Enter product's name: ");
        fgets(new->data.name, 30, stdin);
        printf("Enter product's description: ");
        fgets(new->data.description, 100, stdin);
        printf("Enter product's price: ");
        scanf("%10d",&new->data.price);
        printf("Enter product's quantity: ");
        scanf("%4d%*c",&new->data.quantity);
        if(root == NULL)
            root = new;
        else
        {
            node *temp;
            temp = root;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = new;
        }
        linked_list_no_elements ++ ;
    }
    return;
}

void display(node *new)
{
    printf("Product's id: %d\n", new->data.id);
    printf("Product's name: %s", new->data.name);
    printf("Product's description: %s", new->data.description);
    printf("Product's price: %d\n",new->data.price);
    printf("Product's quantity: %d\n",new->data.quantity);
}

void display_all()
{
    node *current;
    current = root;
    while(current != NULL)
    {
        display(current);
        current = current->next;
    }
}

void freeList()
{
    node* tmp;
    while (root != NULL)
    {
        tmp = root;
        root = root->next;
        free(tmp);
    }
}

void createFile()
{
    node *current;
    current = root;
    FILE *fptr;
    if((fptr = fopen("SANPHAM.txt", "wb")) == NULL)
    {
        printf("Can not create a new file!\n");
        return;
    }
    else
    {
        fwrite(&linked_list_no_elements, sizeof(int), 1, fptr);
        while(current != NULL)
        {
            fwrite(&(current->data), sizeof(current->data), 1, fptr);
            current = current->next;
        }
        printf("Successfully created SANPHAM.txt!\n");
    }
    fclose(fptr);
}

void readFile(product **my_array, int *array_size)
{
    FILE *fptr;
    if((fptr = fopen("SANPHAM.txt", "rb")) == NULL)
    {
        printf("Can not open SANPHAM.txt!\n");
        return;
    }
    else
    {
        int size;
        fread(&size, sizeof(int), 1, fptr);
        *array_size = size; // passing size of the array read from file to array_size //
        product *array;
        array = (product*) calloc(size, sizeof(product));
        fread(array, sizeof(product), size, fptr);
        *my_array = array;
        printf("Successfully read SANPHAM.txt!\n");
    }
    fclose(fptr);
}

void swap(product *array, int pos1, int pos2)
{
    product temp;
    temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

void quicksort(product *array, int left, int right)
{
    if(right - left <= 0)
        return;
    else
    {
        int pivot = (left+right)/2;
        product pivotValue = array[pivot];
        int leftPosition = left;
        int i;
        swap(array, pivot, right);
        for(i = left; i < right; i ++)
        {
            if(array[i].id < pivotValue.id)
            {
                swap(array, i, leftPosition);
                leftPosition ++;
            }
        }
        swap(array, leftPosition, right);
        quicksort(array, left, leftPosition - 1);
        quicksort(array, leftPosition + 1, right);
    }
}

int binarySearch(product array[], int left, int right, int x)
{
    if (right - left >= 0)
    {
        int mid = (right + left)/2;
        if (array[mid].id == x)
            return mid;
        if (array[mid].id > x)
            return binarySearch(array, left, mid - 1, x);
        else
            return binarySearch(array, mid + 1, right, x);
    }
    return -1;
}

int main()
{
    int choice;
    product *array;
    do
    {
        do
        {
            printf("Please enter your choice(1-4):\n 1:Create file \n 2:readfile \n 3:search \n 4:Exit");
            scanf("%2d%*c", &choice);
            if(choice != 1 && choice != 2 && choice != 3 && choice != 4)
                printf("Invalid! Please re-enter!\n");
        }
        while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
        switch(choice)
        {
        case 1:
            printf("======= INPUT =======\n");
            append();
            display_all();
            createFile();
            break;
        case 2:
            printf("======= READ FILE =======\n");
            int array_size;
            readFile(&array, &array_size);
            break;
        case 3:
            printf("======= SEARCH =======\n");
            quicksort(array, 0, array_size - 1);

            int result;
            int search_id;
            printf("Enter product's id: ");
            scanf("%3d",&search_id);
            result = binarySearch(array, 0, array_size - 1, search_id);
            if(result == -1)
                printf("Your search did not match !\n");
            else
            {
                printf("Product's id: %d\n", array[result].id);
                printf("Product's name: %s", array[result].name);
                printf("Product's description: %s", array[result].description);
                printf("Product's price: %d\n",array[result].price);
                printf("Product's quantity: %d\n",array[result].quantity);
            }
            break;
        case 4:
            printf("Exit!\n");
            break;
        }
    }
    while(choice != 4);
    freeList();
    return 0;
}
