#include<stdio.h>
void recurse (count ){
if(count >5){
    return ;


}
recurse(count+1);
printf("count %d\n",count);

}
int main(){
recurse(0);


 return 0;
}
