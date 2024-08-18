#include<stdio.h>
void binary (int a[],int n,int x) {

int low=0,high=n-1,mid=0;

while(low<=high){
    mid=(low+high)/2;
    if(a[mid]==x){
    printf(" found %d  at position %d",x, mid+1);
    return ;
    }
    else if (a[mid]>x){
        high=mid-1;

    }
    else low=mid+1;

}
printf(" sry data not founded ");

}




int main (){

int a[5]={10,20,30,40,50};
 binary(a,5,1);




return 0;
}
