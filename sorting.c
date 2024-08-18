#include <stdio.h>
void bubble (int a[],int size){
for(int i=0;i<size-1;i++){

for(int j=0;j<size-1-i;j++){

	if(a[j]>a[j+1]){
		int tamp=a[j];
		a[j]=a[j+1];
		a[j+1]=tamp;
	}
}

}


}

void selecation(int a[j],int size ){
for(int i=0;i<size-1;i++){
 int min=i;
for(int j=i+1;j<size;j++){
	if(a[j]<a[min])
		min=j;

}
int tamp =a[min];
a[min]=a[i];
a[i]=tamp;


}




}

int main()
{
	int size;
	printf("enter your arrry size \n");
	scanf("%d",&size);
	int array[size];
for(int i=0;i<size;i++){
	scanf("%d",&array[i]);
}
bubble(array,size);
printf("\n");
for(int i=0;i<size;i++){
	printf("%d ",array[i]);
}


	return 0;
}