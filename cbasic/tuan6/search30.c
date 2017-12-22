#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct students
{
    char id[10];
    char name[30];
    float score;
} student;

typedef struct list
{
    student data;
    struct list *next;
} node;

node *root = NULL;
int linked_list_no_elements = 0;

void addst()
{
    node *new;
    while(1)
    {
        new = (node*)malloc(sizeof(node));
        new->next = NULL;
        printf("Enter student's name: ");
        fgets(new->data.name, 30, stdin);
        //scanf("%[^\n]%*c", new->data.name);
        if(strcmp(new->data.name, "###\n") == 0)
        {
            printf("Exit!\n");
            free(new);
            break;
        }
        printf("Enter student's id: ");
        fgets(new->data.id, 10, stdin);
        do
        {
            printf("Enter student's score: ");
            scanf("%4f%*c", &new->data.score);
            if(new->data.score < 0 || new->data.score >10)
                printf("Invalid! Please re-enter!\n");
        }
        while(new->data.score < 0 || new->data.score >10);
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
    printf("Student's id: %s", new->data.id);
    printf("Student's name: %s", new->data.name);
    printf("Student's score: %.2f\n", new->data.score);
}

void print()
{
    node *current;
    current = root;
    while(current != NULL)
    {
        display(current);
        current = current->next;
    }
}

void makeFile()
{
    node *current;
    current = root;
    FILE *fptr;
    if((fptr = fopen("sinhvien.dat", "wb")) == NULL)
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
        printf("Successfully created sinhvien.dat!\n");
    }
    fclose(fptr);
}

void readFile(student **my_array, int *array_size)
{
    FILE *fptr;
    if((fptr = fopen("sinhvien.dat", "rb")) == NULL)
    {
        printf("Can not open sinhvien.dat!\n");
        return;
    }
    else
    {
        int size;
        int i;
        fread(&size, sizeof(int), 1, fptr);
        *array_size = size; // passing size of the array read from file to array_size //
        student *array;
        array = (student*) calloc(size, sizeof(student));
        fread(array, sizeof(student), size, fptr);
        *my_array = array;
        printf("Successfully read sinhvien.dat!\n");
    }
    fclose(fptr);
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

void swap(student *array, int pos1, int pos2)
{
    student temp;
    temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

void quicksort(student *array, int left, int right)
{
    if(right - left <= 0)
        return;
    else
    {
        int pivot = (left+right)/2;
        student pivotValue = array[pivot];
        int leftPosition = left;
        int i;
        swap(array, pivot, right);
        for(i = left; i < right; i ++)
        {
            if(strcmp(array[i].id, pivotValue.id) < 0)
            {
                swap(array, i, leftPosition);
                leftPosition ++;
            }
        }
        swap(array, leftPosition, right);
        quicksort(array, left, leftPosition-1);
        quicksort(array, leftPosition + 1, right);
    }
}

int binarySearch(student array[], int left, int right, char *x)
{
   if (right - left >= 0)
   {
        int mid = (right + left)/2;
        if (strcmp(array[mid].id, x) == 0)
            return mid;
        if (strcmp(array[mid].id, x) > 0)
            return binarySearch(array, left, mid - 1, x);
        else
            return binarySearch(array, mid + 1, right, x);
   }
   return -1;
}

int main()
{
    int x;
    int i;
    student *array;
    do
    {
        do
        {
            printf("Enter your choice(1-5):\n1: make file\n2:readfile\n3:SORT\n4:SEARCH\n");
            scanf("%2d%*c", &x);
            if(x != 1 && x != 2 && x != 3 && x != 4 && x != 5)
                printf("Invalid! Please re-enter!\n");
        }
        while(x != 1 && x != 2 && x != 3 && x != 4 && x != 5);
        switch(x)
        {
        case 1:
            printf("======= INPUT =======\n");
            addst();
            print();
            makeFile();
            break;
        case 2:
            printf("======= READ FILE =======\n");
            int array_size;
            readFile(&array, &array_size);
            break;
        case 3:
            printf("======= SORT =======\n");
            quicksort(array, 0, array_size - 1);
            for(i = 0; i < array_size; i++)
            {
                printf("Please enter the student's id: %s", array[i].id);
                printf("Please enter the student's name: %s", array[i].name);
                printf("Please enter the student's score: %.2f\n", array[i].score);
            }
            break;
        case 4:
            printf("======= SEARCH =======\n");
            int result;
            char search_id[10];
            printf("Please enter student's id: ");
            fgets(search_id, 10, stdin);
            result = binarySearch(array, 0, array_size - 1, search_id);
            if(result == -1)
                printf("Your search did not match \n");
            else
            {
                printf("Element is present in the array at index %d\n",result);
                printf("Student's id: %s", array[result].id);
                printf("Student's name: %s", array[result].name);
                printf("Student's score: %.2f\n", array[result].score);
            }
            break;
        case 5:
            printf("Exit!\n");
            break;
        }
    }
    while(x != 5);
    freeList();
    return 0;
}
