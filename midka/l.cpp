#include <iostream>
using namespace std;
int cnt=0;
struct node
{
    int data;
    node *left,*right;
    node(int data){
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};
node *insert(node* root,int data){
    node* newNode=new node(data);
    if(!root){
        root=newNode;
    }
    if(data>root->data) root->right=insert(root->right,data);
    if(data<root->data) root->left=insert(root->left,data);
    return root;
}
node *check(node* root){
  if(!root->left and !root->right) cnt++;
  if(root->left) check(root->left );
  if(root->right) check(root->right);
  return root;
}
int main(){
    int n,p;
    cin>>n>>p;
    node *root=new node(p);
    for (int i = 1; i < n; i++)
    {
        cin>>p;
        insert(root,p);
    }
    check(root);
    cout<<cnt;
}
