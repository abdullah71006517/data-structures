#include<stdio.h>
void merge(int a[],int low ,int mid ,int high){
int i=low, j=mid+1, k=0;
int b[20];
while (i<=mid && j<=high){
    if(a[i]<a[j]){
       b[k]=a[i];
       k++;
       i++;
       }
        else {

            b[k]=a[j];
            k++;
            j++;
        }
}
while(i<=mid){

    b[k]=a[i];
    k++;
    i++;

}

while(j<=high){
    b[k]=a[j];
    k++;
    j++;

}
for(int i=low,k=0;i<=high;i++,k++){
    a[i]=b[k];
}
}


void merageshort(int a[],int low,int high){
    if(low<high){
int mid=(low+high)/2;
merageshort(a,low,mid);
merageshort(a,mid+1,high);
merge(a,low,mid,high);
    }
}
int main (){
int array[5]={5,4,6,2,1};
 merageshort(array,0,4);
printf(" \n before marage short: ");
for(int i=0;i<5;i++){
    printf("%d ",array[i]);
}
return 0;


}
