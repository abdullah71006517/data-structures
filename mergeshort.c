#include<stdio.h>
void merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=0;
    int b[20];//tamp array;
    while(i<=mid&& j<=high)
    {
        if(a[i]<a[j])
        {
           b[k]=a[i];
           k++;
           i++;
        }
        else

        {
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


     for (i = low, k = 0; i <= high; i++, k++) {
        a[i] = b[k];
    }

}
void mergesort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);


    }
}

int main(){
int array[20]={1,20,2,19,3,18,4,17,5,16,6,15,7,14,8,13,9,12,10,11};
 mergesort(array,0,19);
printf(" \n before marage short: ");
for(int i=0;i<20;i++){
    printf("%d ",array[i]);
}


return 0;
}
