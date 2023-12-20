#include <bits/stdc++.h>
using namespace std;
int n,x,y,z,m[1001],max_w;
bool was[1001];
struct TreeNode
{
    int val,level;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
      val=0;
      level=0;
      left=nullptr;
      right=nullptr;
    }
    TreeNode(int x,int l){
        val=x;
        level=l;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int x,TreeNode *_left,TreeNode *_right,int _level){
        val=x;
        level=_level;
        left=_left;
        right=_right;
    }
};
TreeNode *t;
TreeNode *root;
void search(TreeNode *tree, int x, int level = 1) {
  if(!tree) return;
  if(tree->val == x) {
    t = tree;
    m[level + 1] += 1; 
    return;
  }
  search(tree->left, x, level + 1);
  search(tree->right, x, level + 1);
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>n;
root = new TreeNode(1,1);
for (int i = 1; i < n; i++)
{
    cin>>x>>y>>z;
    search(root,x);
    if(z==0) t->left=new TreeNode(y,t->level+1);
    else if(z==1) t->right=new TreeNode(y,t->level+1);
}
for(int i = 1; i <= 1000; i++) max_w = max(max_w,m[i]);
  cout << max_w;

return 0;
}