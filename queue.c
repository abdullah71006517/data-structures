#include<stdio.h>
#define capacity 5
int queue[capacity];
int fornt=0,rear=-1,totalitem=0;
int full(){
if( totalitem==capacity ){
    return 1;
}
return 0;

}
int empty(){
if(totalitem==0){
    return 1;
}
 return 0;
}
void enqueue(int item ){
if(full()){
    printf(" queue is full , cann't possible enque \n ");
    return -1;
}
else {
rear=(rear+1)%capacity;
queue[rear]=item;
totalitem++;
printf(" an item added done \n");

}
}
int  dequeue (){
if(empty()) {
    printf(" queue is empty \n");
    return -1;
}
else {
    int item=queue[fornt];
    fornt=(fornt+1) % capacity;
    totalitem--;
    return item ;}
}
int main(){
 enqueue(100);
enqueue(20);
enqueue(30);
enqueue(40);
enqueue(50);
int d= dequeue();
int c= dequeue();
for(int i=fornt;i<=rear;i++){
printf("%d ", queue[i]);
}
}
