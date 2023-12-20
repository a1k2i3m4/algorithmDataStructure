#include <bits/stdc++.h>
using namespace std;
struct node
{
    pair<char,bool> data;
    node *next;
    node *prev;
    node(){
        data.first='0';
        data.second=false;
    }
    node(pair<char,bool> _data,node* _next,node* _prev){
        data=_data;
        next=_next;
        prev=_prev;
    }
};
struct linked_list
{
    node *head,*tail;
    linked_list(){
        head = new node(make_pair('0',false),NULL,NULL);
        tail = new node(make_pair('0',false),NULL,NULL);
        }
    void add_back(char data){
        if(head->data.first=='0'){ 
            head->data.first = data;
            tail = head;
        }else
        {
            node *newNode=new node(make_pair(data,false),NULL,tail);
            tail->next=newNode;
            tail=newNode;
        }
        
    }
    void clear(){
        head = new node(make_pair('0',false),NULL,NULL);
        tail = new node(make_pair('0',false),NULL,NULL);     
    }
    void check(){
      node *cur=tail->prev;
      while (cur!=NULL)
      {
        if(cur->data.first==tail->data.first){
            cur->data.second=true;
            tail->data.second=true;
        }
        cur = cur->prev;
      }
      cur=head;
      while (cur!=NULL)
      {
        if(cur->data.second==false){
            cout<<cur->data.first<<" ";
            return;
        }
        cur=cur->next;
      }
      cout<<"-1 ";
      
    }
        
};
linked_list l;
int main(){
    int a,n;
    
    cin>>a;
    while(a--){
        cin>>n;
        char s;
        for (int i = 0; i < n; i++)
        {
            cin>>s;
            l.add_back(s);
            l.check();
            
        }
        l.clear();
        cout<<"\n";
        

    }
}
