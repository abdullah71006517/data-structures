#include <stdio.h>
int current_size = 0;
void inputarry(int a[], int n)
{
    for (int i = current_size; i < n; i++)
    {
        scanf("%d", &a[ i]);
    }
    current_size+=n;
    return;
}
void pint(int a[],int n){

for(int i =0;i<n;i++){
    printf("%d  ",a[i]);


}
printf("\n");
return ;}
void dlt_atlast (int a[]) {
if( current_size<0){
    printf(" \n array has no element ");
}
else {
    current_size--;
}

}
void dlt_beging (int a[]){
    if( current_size<0){
    printf(" \n array has no element ");
} else {
for(int i=0;i<current_size;i++){
    a[i]=a[i+1];
}
    current_size--;
}
}
void dlt_at_spefice_position(int a[],int pos){
if(current_size<0 || current_size<pos){
        printf(" \ not possible dlt ");

}

else {
    for(int i=pos-1;i<current_size;i++){

        a[i]=a[i+1];
    }
    current_size--;
}
}
int main (){
int size,n;
printf("enter your array size :   ");
scanf("%d",&size);
int array[size];
printf("\n enter element size which you want form user :");
scanf("%d",&n);
inputarry(array , n);
dlt_atlast(array);
pint(array,current_size);
dlt_beging(array);
pint(array,current_size);
dlt_at_spefice_position(array,3);
pint(array,current_size);
return 0;
};

