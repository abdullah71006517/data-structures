#include <stdio.h>
int current_size = 0;
void inputarry(int a[], int n)
{
    for (int i = current_size; i < n; i++)
    {
        scanf("%d", &a[  i]);  // Pass the address of the element
    }
    current_size+=n;
    return;
}

void insert_at_end(int array[], int size, int newelement)
{

    if (current_size == size)
    {
        printf("Sorry, insertion not possible. Array is full.\n");
    }
    else
    {
        array[current_size] = newelement;
        current_size ++;
    }
}



void pint(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a [ i]);
    }
    printf("\n");
    return;
}
void insert_atspafice_position(int a[],int pos,int element,int size )
{
   if(current_size==size){
   printf(" \n insert not possible ");
   return ;}
   else  {

    for(int i=current_size-1;i>=pos-1;i--){

        a[i+1]=a[i];
    }
    a[pos-1]=element;
    current_size++;
   }
return ;
}

void insert_begin(int a[],int size,int element)
{


    if (current_size == size)
    {
        printf("Sorry, insertion not possible. Array is full.\n");
        return ;
    }
    else
    {
        for(int i=current_size-1;i>=0;i--){
            a[i+1]=a[i];
        }
        a[0]=element;
        current_size ++;
    }
return ;
}







int main()
{
    int size, n;
    printf("Enter your array size: ");
    scanf("%d", &size);
    int array[size];
    printf("\nEnter the number of elements you take form usser : ");
    scanf("%d", &n);
    inputarry(array, n);

    int newelement;
    printf("\nEnter the new element to be inserted at the last index: ");
    scanf("%d", &newelement);



    insert_at_end(array, size, newelement);

    pint(array, current_size);
insert_atspafice_position(array,3,100,size);
pint(array,current_size);
insert_begin(array,size,1000);
pint(array,current_size);
    return 0;
}

