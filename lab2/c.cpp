#include <iostream>
using namespace std ;
struct node{
    int data ;
    node *next;
};
struct linked_list{
node *head,*tail;
linked_list()
{
    head=NULL;
    tail=NULL;
}
node* getTail(){
    node* cur=head;
    while (cur->next!=NULL)
    {
        cur=cur->next;
    }
    
}
void add_node(int n){
    node *t=new node;
    t->data=n;
    t->next=NULL;
    if (head==NULL)
    {
        head=t;
        tail=t;
    }
    else
    {
        tail->next=t;
        tail=tail->next;
    }
    
}
void out(){
    node *t ;
    t=head;
    while (t!=NULL)
    {
        cout << t->data << ' ';
            t = t->next;
    }
    
}
};
int main(){
     int n;cin>>n;
    linked_list l;
    for(int i=0;i<n;i++){
        int j;cin>>j;
        if(i%2==0){
            l.add_node(j);
        }
    }
    l.out() ;
}