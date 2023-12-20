#include <iostream>
using namespace std;
int n,p;
int triangles[1000];
struct node
{
    int data;
    node *left,*right;
   
    node(int data)
    {
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};
node* add(node* root,int data){
     if(!root)
     {
        return new node(data);
     }
     else if(root->data>data){
        if (root->left==nullptr)
        {
            root->left=new node(data);
        }
        else
        {
            root->left=add(root->left,data);
        }
    }else if(root->data<data){
        if (root->right==nullptr)
        {
            root->right=new node(data);
        }
        else
        {
            root->right=add(root->right,data);
        }
    }
    return root;
}
node* check(node *root)
{
    if(!root){
        return nullptr;
    }
    int i=1;
    node* r=root->right;
    node* l=root->left;
    while (r and l)
    {
        ++triangles[i++];
        r=r->right;
        l=l->left;
    }
    check(root->left);
    check(root->right);
}
int main()
{
 ios::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);
 cin>>n>>p;
 node *root=new node(p);
 for (int i = 1; i < n; i++)
 {
    cin>>p;
    add(root,p);
 }
  check(root);
 for (int i = 1; i < n; i++) 
 {
    cout<<triangles[i]<<" ";
 }
 
}