#include <bits/stdc++.h>
using namespace std ;
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
        head=new node(0,NULL);
        tail=new node(0,NULL);
    }
    void output(){
        node *cur=head;
        while (cur!=NULL)
        {
            cout<<cur->data<<" ";
            cur=cur->next;
        }
    }
    void insertBegin(int data){
        node *newNode= new node(data,head);
        head=newNode;
    }
    void insertEnd(int data){
        if(head->data==0){
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
    node *getE(int i){
        node *cur=head;
        for(int j=0;j<i;j++){
            cur=cur->next;
        }
        return cur;
    }
    void insert(int data,int in){
        if(in==0){
            insertBegin(data);
            return;
        }
        else
        {
            node *cur= getE(in-1);
            node *newNode=new node(data,cur->next);
            cur->next=newNode;
        }
        
    }
};
int main(){
    linkedList l;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        l.insertEnd(x);
    }
    int i,j;
    cin >> i >> j;
    l.insert(i,j);
    l.output();
    return 0;
}

