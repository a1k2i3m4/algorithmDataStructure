#include <iostream>
using namespace std;
long long s=0;
struct node
{
    int data;
    int level;
    node *left,*right;
   
    node(int data,int level)
    {
        this->data=data;
        this->level=level;
        left=nullptr;
        right=nullptr;
    }
};
node* add(node* root,int data,int level=0){
     if(!root)
     {
        return new node(data,0);
     }
     else if(root->data>data){
        if (root->left==nullptr)
        {
            root->left=new node(data,level+1);
        }
        else
        {
            root->left=add(root->left,data,level+1);
        }
    }else if(root->data<data){
        if (root->right==nullptr)
        {
            root->right=new node(data,level+1);
        }
        else
        {
            root->right=add(root->right,data,level+1);
        }
    }
    return root;
}
node*  print(node* root)
{

   s+=root->data-root->level;
   if(root->left!=nullptr){
   print(root->left);}
   if(root->right!=nullptr){
   print(root->right);}

   return root;
}
int main()
{
    long long n;
    int t;
    cin>>n>>t;
    node *root =new node(t,0) ;
    for (int i = 1; i < n; i++)
    {
        cin>>t;
        add(root,t);
    }
    print(root);
    cout<<s;
}