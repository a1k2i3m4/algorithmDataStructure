#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next=NULL;
    node(){
        data=0;
    }
    node(int _data,node* _next){
        data=_data;
        next=_next;
    }
};
struct linkedList
{
    node *head,*tail;
    linkedList(){
        head=nullptr;
        tail=nullptr;
        }
    void insert(int data,int p){
        if(p==0){
          node *t=new node(data,head);
          head=t;
        
        }
        else
        {
            node* cur=head;
            int i=0;
            node* t=new node(data,nullptr);
            
            while (cur!=nullptr)
            {
                if(i==p-1){
                    t->next=cur->next;
                    cur->next=t;
                    break;
                }
                i++;
                cur=cur->next;
            }
            
        }
        
    }
    void remove(int p){
      if(p==0){
        head=head->next;
      }
      else
      {
        node* cur=head;
        node* prev=nullptr;
        int i=0;
        while (cur!=nullptr)
        {
            if(i==p){
                prev->next=cur->next;
                break;
            }
            i++;
            prev=cur;
            cur=cur->next;
        }
        
      }
      
    }
    void replace(int p1,int p2){
        node* cur=head;
        node* prev=nullptr;
        int i=0;
        while (cur!=nullptr)
        {
            if(p1==0){
                head=head->next;
                break;
            }
            else if(i==p1)
            {
                prev->next=cur->next;
                break;
            }
            i++;
            prev=cur;
            cur=cur->next;
        }
     node* t=cur;
    cur = head;
    prev = nullptr;
    i = 0;
    while (cur!=nullptr)
    {
        if(p2==0){
            t->next=head;
            head=t;
            break;
        }
        else if (i==p2)
        {
            prev->next=t;
            t->next=cur;
            break;
        }
        else if(cur -> next == nullptr){
            cur -> next = t;
            t -> next = nullptr;
            break;
        }
       
        i++;
        prev = cur;
        cur = cur -> next;
    }
    
    }
    void reverse(){
     node* cur = head;
    node *prev = nullptr;
    node *next = nullptr;
    
    while(cur != nullptr){
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    
    }
    void print(){
        node *cur =head;
        while(cur!= nullptr){
        cout << cur -> data << " ";
        cur = cur -> next;
    }
    }
    void cyclic_left(int x){
        node * cur = head;
    int i = 0;
    while(cur -> next != nullptr){
        cur = cur -> next;
        i++;
    }
    cur -> next = head;
    cur = head;
    while(x-1){
        cur = cur -> next;
        x--;
    }
    head = cur -> next;
    cur -> next = nullptr;
    }
    void cyclic_right(int x){
    node * cur = head;
    int i = 0;
    while(cur -> next != nullptr){
        cur = cur -> next;
        i++;
    }
    cur -> next = head;
    int k = i - x;
    cur = head;
    while (k)
    {
        cur=cur->next;
        k--;
    }
    head=cur->next;
    cur->next=nullptr;
    }
};
int main(){
    linkedList l;
    while (true)
    {
        int c;cin>>c;
        if(c==0){
            break;
        }
        else if (c==1)
        {
            int x,p;cin>>x>>p;
            l.insert(x,p);
        }else if (c==2)
        {
            int p;cin>>p;
            l.remove(p);
        }else if (c==3)
        {
            l.print();
        }else if (c==4)
        {
            int p1,p2;cin>>p1>>p2;
            l.replace(p1,p2);
        }else if (c==5)
        {
            l.reverse();
        }else if (c==6)
        {
            int x;cin>>x;
            l.cyclic_left(x);
        }else if (c==7)
        {
            int x;cin>>x;
            l.cyclic_right(x);
        }
        
        
        
        
        
        
        
    }
    
}