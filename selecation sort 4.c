#include<stdio.h>
int main(){
int size;
printf(" enter your array size : ");
scanf("%d",&size);
float a[size];
for(int i=0;i<size;i++){
    scanf("%f",&a[i]);
}
for(int i=0;i<size-1;i++){
        int min_index=i;
    for(int j=i+1;j<size;j++){

         if(a[j]>a[min_index]){
           min_index=j;
        }
    }
float temp = a[min_index];

a[min_index] = a[i];

a[i] = temp;
}
printf(" sort the array in descending oder :  ");
for(int i=0;i<size;i++){
    printf("%.2f ",a[i]);
}
return 0;
}
