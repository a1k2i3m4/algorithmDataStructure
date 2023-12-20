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
if(x<=tree->val) return search(tree->left,x);
else return search(tree->right,x);

}
void print(TreeNode *tree){
    if(!tree) return;
    cout<<tree->val<<" ";
    print(tree->left);
    print(tree->right);
    
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
print(root);
return 0;
}