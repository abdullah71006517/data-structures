#include<stdio.h>
void marge(int a[],int low , int mid ,int high){
int i=low,j=mid+1,k=0;
int b[20];
while(i <=mid && j<=high){
     if(a[i]<=a[j]){
        b[k]=a[j];
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
while (j<=high){

    b[k]=a[j];
    k++;
    j++;
}

for(int i=0,k=0;i<high;i++,k++){
    a[i]=b[k];
}

}

void mergesort(int a[],int low, int high){
if(low<high){
    int mid=(low+high)/2;
     mergesort(a,low,mid);
     mergesort(a,mid+1,high) ;
     merge(a,low, mid,high);
}

}
int main (){
int a[5]={5,4,3,2,1};
mergesort(a,0,4);
for(int i=0;i<5;i++){
    printf("%d ",a[i]);
}
return 0;

}





