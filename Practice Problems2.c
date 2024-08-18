#include<stdio.h>
int main (){
int size;
printf(" enter your array size : ");
scanf("%d",&size);
int array[size];
for(int i=0;i<size;i++){
    scanf("%d",&array[i]);

}
printf(" \n total array elements :");
for(int i=0;i<size;i++){
    printf("%d  ",array[i]);

}


return 0;
}
