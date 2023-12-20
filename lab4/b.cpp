#include <bits/stdc++.h>
using namespace std;
int n,p,x;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
      val=0;
      left=nullptr;
      right=nullptr;
    }
    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int x,TreeNode *_left,TreeNode *_right){
        val=x;
        left=_left;
        right=_right;
    }
    
};
TreeNode *insert(TreeNode *tree,int x){
    if(!tree) {
        tree=new TreeNode(x);
        return tree;
    }
    if (x<=tree->val)
    {
        tree->left=insert(tree->left,x);
    }
    else
    {
        tree->right=insert(tree->right,x);
    }
    return tree;
}
TreeNode *search(TreeNode *tree,int x){
    if(!tree || tree->val==x) return tree;
    if(tree->val>=x) return search(tree->left,x);
    else return search(tree->right,x);
}
int count(TreeNode *tree){
    if(!tree) return 0;
    return 1 + count(tree->left)+count(tree->right);
}
TreeNode *root;
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>n>>p;
root=insert(root,p);
for (int i = 1; i < n; i++)
{
    cin>>p;
    insert(root,p);
}
cin>>x;
root=search(root,x);
cout<<count(root);
return 0;
}