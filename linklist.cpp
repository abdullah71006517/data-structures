// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct node {
    int data ;
    node *next;
};
node* linklist(int item, node * next){

    node *new_node= new node ;
    if(new_node==nullptr){

    cout<<" oppps ! not space "<< endl;
}
new_node->data=item;
new_node->next=next;
return new_node;

}

int main() {
  node *n;
  n=linklist(20,nullptr);
  cout<<n-> data ;
  return 0;


}
