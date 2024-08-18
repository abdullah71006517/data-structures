#include<stdio.h>
int main (){
int size,even=0,odd=0;
printf("enter size ");
scanf("%d",&size);
int array[size];
for(int i=0;i<size;i++){
    scanf("%d",&array[i]);
    if(array[i]%2==0)
        even++;
    else odd++;
}
if(2<=even){
        int count=0;
    for(int i=size;i>=0;i--){
        if(array[i]%2==0){
            for(int j=i;j<size-1;j++){
              array[j]=  array[j+1];
            }
            size--  ;
            count++;
        }
        if(count==2)
            break;
    }



}

for(int i=0;i<size;i++){
    printf ("%d ",array[i]);
}


return 0;
}
