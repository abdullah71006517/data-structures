#include<iostream>
#include <stdlib.h>
using namespace std;
struct node {
    int data;
    struct node* next;
};

int main() {
    struct node* a = (struct node*)malloc(sizeof(struct node));
    struct node* b = (struct node*)malloc(sizeof(struct node));
    struct node* c = (struct node*)malloc(sizeof(struct node));

  a->data=10;
  b->data=20;
  c->data=30;
   a->next=b;
b->next=c;
c->next=NULL;
while(a!=0){
    cout<< a->data<<endl;
    a=a->next;
}
    return 0;
}

