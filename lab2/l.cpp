#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(){
        data=0;
    }
    node(int _data,node *_next){
        data=_data;
        next=_next;
    }
};

struct linked_list
{   
    node *head,*tail;
    int size;
    linked_list(){
      head=new node(0,NULL);
      tail=new node(0,NULL);
      size=0;
    }
    void add_back(int data){
        if(size==0){
            head->data=data;
            tail=head;
            size++;
            return;
        }
        else
        {
            node *newNode=new node();
            if(tail->data>0){
                data=data+tail->data;
                newNode->data=data;
                tail->next=newNode;
                tail=newNode;
                
            }
            else
            { 
                newNode->data=data;
                 tail->next=newNode;
                tail=newNode;
            }
            size++;
            return;
        }
        
    }
void max(){
int m=head->data;
node *cur=head;
while (cur!=NULL)
{
    int s=cur->data;
    if(m<s){
        m=s;
    }
    cur=cur->next;
}
cout<<m;
}
};
int main(){
    linked_list l;
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        l.add_back(x);
    }
    l.max();
    
    
}