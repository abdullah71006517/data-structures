#include<stdio.h>
int sumiya =0;
void insert_at_last (int array[],int data ,int size){
       if(sumiya==size){
        printf(" add kora possible na ");
        return ;
       }
array[sumiya]=data;
sumiya++;
return ;
}



int main (){
int size ,n;
printf("enter your size ");
scanf("%d",&size);
int array[size];

printf(" tomi koi ta man nite caw ");
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%d",&array[i]);
}
sumiya=sumiya+n;
insert_at_last(array,55,size);
for(int i=0;i<sumiya;i++){
    printf("%d ",array[i]);
}


return 0;
}
