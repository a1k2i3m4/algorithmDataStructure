#include <iostream>
using namespace std;
struct node
{
    string data;
    node *next=NULL;
    node(){
     data="";
    }
    node(string _data,node * _next){
    data=_data;
    next=_next;
    }
};
struct linked_list
{
    node *head,*tail;
    linked_list(){
        head = new node("",NULL);
        tail = new node("",NULL);
    }
    void out(){
        node *t=head;
        while (t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->next; 
        }
       cout<<"\n"; 
    }
    void insertEnd(string data){
       if(head->data==""){
        head->data=data;
        tail=head;
       }
       else
       {
        node *newNode=new node(data,NULL);
        tail->next=newNode;
        tail=newNode;
       }
       
    }
    node* getTail(){
        node *cur=head;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        return cur;
    }
    void popFront(){
        head=head->next;
    }
    void shift(int k){
     string front;
     while (k--)
     {
        front=head->data;
        popFront();
        insertEnd(front);
               
     }
     
    }
};
int main(){
linked_list l;
   int n;cin >> n;
    int k;cin >> k;
    string s;
    for (int i = 0; i < n; i++)
    {
         cin >> s;
        l.insertEnd(s);
    }
    l.shift(k);
    l.out();
    
}


