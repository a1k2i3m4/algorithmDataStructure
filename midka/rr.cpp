#include <iostream>
#include <set>
using namespace std;
struct node
{
    int data;
    node *next;
    node(){

    }
    node(int data){
        this->data=data;
        next=nullptr;
    }
};
   int index=1;
node* insert(node *root,int data){
        node *newNode=new node(data);
    
     if(root->next!=nullptr){
     insert(root->next,data);
     }
     else
     {
     
     root->next=newNode;
     return root;
     }
}

node*  del(node** root,int i){
   if(*root==nullptr){
    index=1;
    return *root;
   }
   node* temp =*root; 
   if (i==1)    
   {
    *root=temp->next;
   }
   while(index!=i-1){
    temp=temp->next;
    index++;
    }
   if (temp == nullptr || temp->next == nullptr){ 
    index=1;
    return *root;}
    node* t=temp->next->next;
   temp->next=t;
   index=1;
}
int getRoot(node *root,int i){
    if(index==i){
        index=1;
        return root->data;
    }
    index++;
    getRoot(root->next,i);
}
void print(node*root){
    cout<<root->data<<" ";
    if(root->next==nullptr) return;
    print(root->next);
}
int main(){
    int t,n;
    cin>>t;
    while (t--)
    {
        node *root =new node(1);
        cin>>n;
        for (int i = 2; i <=n; i++)
        {
         insert(root,i);
        }
        int t=getRoot(root,n/2);
        del(&root,n/2);
        node *root1=new node(t);
        int lasti=1;
        int o=n=n-1;
        while (o--)
        {
            int r;
           int  best_number=0;
           for (int i=1;i<=n;i++)
           { 
              if(best_number<abs(getRoot(root1,lasti)-getRoot(root,i))){
                 best_number=getRoot(root,i);
                 r=i;
              }
           }
           del(&root,r);
           print(root);
           lasti++;
           n--;
           insert(root1,best_number);
        }
        print(root1);
    }

    
}