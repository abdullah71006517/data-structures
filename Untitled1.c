#include<stdio.h>
current_size=0;
void insert_at_end(int array[], int size, int newelement){
 array[current_size] = newelement;
        size++;


}

int main (){
int n;
printf("enter your arriy size :");
   scanf("%d",&n);
   int arriay[n];
   for(int i=0;i<n;i++){
    scanf("%d",&arriay[i]);
   }
   insert_at_end(arriay, n, 10);
for(int i=0;i<n;i++){
    printf("%d",arriay[i]);
}

return 0;
}
