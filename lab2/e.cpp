#include <bits/stdc++.h>
using namespace std;
#define fori(n) for(i = 0;i < n;i++)
struct node
{
    string data;
    node *next=NULL;
    node(){
        data="";
    }
    node( string _data,node* _next ){
        data=_data;
        next=_next;
    }
};
struct linkedlist
{
    node *head,*tail;
    int size;
    linkedlist(){
        head= new node("",NULL);
        tail=new node("",NULL);
        size=0;
    }
    int length(){
        node *cur=head;
        while (cur!=NULL)
        {
            size++;
            cur=cur->next;
        }
        return size;
    }
    void output(){
        node *cur=head;
        while (cur!=NULL)
        {
            cout<<cur->data<<"\n";
            cur=cur->next;
        }
        
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
    void popFront(){
        head=head->next;
    }
    void clear(){
        head = new node("",NULL);
        tail = new node("",NULL);
    }
    void reverse(node *cur){
       if(cur!=NULL){
        reverse(cur->next);
       }
       else if (cur==NULL)
       {
        clear();
        return;
       }
       insertEnd(cur->data);
        
    }
    void solution(){
        node *nd =head;
        while (nd->next!=NULL and  nd!=NULL)
        {
          while (nd->next!=NULL and nd->data==nd->next->data)
          {
            node *x=nd->next;
             nd->next=x->next;
          }
          if(nd->next!=NULL) nd = nd ->next;
        }
        
    }
};
int main(){
    int n;cin >> n;
    string s;
    linkedlist l;
    for(int i=0;i<n;i++){
        cin >> s;
        l.insertEnd(s);
    }
    node *nd = l.head;
    l.solution();
    l.reverse(nd);
    cout << "All in all: " << l.length() << "\nStudents:\n";
    l.output();
}
