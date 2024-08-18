#include<stdio.h>
int main(){

int a=5;
int * ptr;
ptr=&a;
*ptr=12;
int **ptr1;
ptr1=&*ptr;
 *ptr1=255;
printf("the adderss ptr %x",&ptr1);
printf("\n the adderss a %x",&a);
printf("\n the vule %d",*ptr1);
printf("\n the vule %d",a);



return 0;
}
