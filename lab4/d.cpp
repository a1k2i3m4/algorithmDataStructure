#include <bits/stdc++.h>
using namespace std;
int n,p,m;
int sum[5001];
struct TreeNode
{
    int val;
    int level;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
      val=0;
      left=nullptr;
      right=nullptr;
      level=1;
    }
    TreeNode(int x,int l){
        val=x;
        level=l;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int x,TreeNode *_left,TreeNode *_right,int _level){
        val=x;
        left=_left;
        right=_right;
        level=_level;
    }
    
};
TreeNode *insert(TreeNode *tree,int x,int l=1){
    m=max(m,l);
    if(!tree) {
        tree=new TreeNode(x,l);
        sum[l] += x;
        return tree;
    }
    if (x<=tree->val)
    {
        tree->left=insert(tree->left,x,l+1);
    }
    else
    {
        tree->right=insert(tree->right,x,l+1);
    }
    return tree;
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
cout << m << "\n";
  for(int i = 1; i <= m; i++) cout << sum[i] << " ";

return 0;
}