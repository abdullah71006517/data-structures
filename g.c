#include<stdio.h>
int main(){

    char name [5]={'a','b','c','d','e'};
        int a[5]={5,1,4,3,2};

        for(int i=0;i<5-1;i++){

for(int j=0;j<5-1-i;j++){

	if(a[j]>a[j+1]){
		int tamp=a[j];
		char c=name[j];
		name[j]=name[j+1];
		name[j+1]=c;
		a[j]=a[j+1];
		a[j+1]=tamp;
	}
}

}

for(int i=0;i<5;i++){
printf("id:%d\t name:%c\n",a[i],name[i]);
}
return 0;
}
