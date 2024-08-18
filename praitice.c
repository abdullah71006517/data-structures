#include<stdio.h>
int main ()
{
    int size;
    printf(" enter your array size : ");
    scanf("%d",&size);
    int array[size];

    for(int i=0; i<size; i++)
    {
        scanf("%d",&array[i]);

    }
    for(int i=0; i<size; i++)
    {
        if(array[i]%2==0)
        {
            printf("%d  ",array[i]);
        }
    }


    return 0;
}
