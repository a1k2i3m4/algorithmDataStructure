#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *left,*right;
  Node(int data){
    this->data=data;
    left=right=nullptr;
  }
};
struct Bst
{
   private:
   Node *root;
   Node *insert(Node *root ,int val){
    if(!root) {
      return new Node(val);
    }
    if(val>root->data){
      root->right=insert(root->right,val);
    }
    else if (val<root->data)
    {
      root->left=insert(root->left,val);
    }
    return root;
   }
   public:
   Bst(){
    root=nullptr;
   }
   Node *getRoot(){
    return root;
   }
   void add(int val){
   Node *newNode=insert(root,val);
   if(!root) root=newNode;
   }
   int count(Node *root,int& cnt){
       if(!root) return 0;
       int l=count(root->left,cnt);
       int r=count(root->right,cnt);
       cnt=max(l+r+1,cnt);
       return max(l,r)+1;
   }
};
int main()
{
  Bst bst;
  int n;
  cin>>n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin>>x;
    bst.add(x);
  }
  int cnt=0;
  bst.count(bst.getRoot(),cnt);
  cout<<cnt;
  return 0;
}

