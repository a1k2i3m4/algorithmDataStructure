#include <bits/stdc++.h>
using namespace std;
int n,m,p;
string s;
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
    }
    TreeNode(int x,TreeNode* _left,TreeNode* _right){
        val=x;
        left=_left;
        right=_right;
    }
};
TreeNode *insert(TreeNode *tree,int val){
        if(!tree){
            tree=new TreeNode(val);
            return tree; 
        }
        if (val<=tree->val) tree->left=insert(tree->left,val);
        else tree->right=insert(tree->right,val);
        return tree;
        
    }
string check(TreeNode *tree,string s){
     TreeNode *node=tree;
     for (int i = 0; i < s.size(); i++)
     {
        if (s[i]=='L')
        {
            node=node->left;
            if(!node) return "NO";
        }
        else
        {
            node=node->right;
            if(!node) return "NO";
        }
    }
     return "YES";
    }

TreeNode *root;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>p;
    root = insert(root, p);

    for (int i = 1; i < n; i++)
    {
        cin>>p;
        insert(root,p);
    }
    
    for(int i=0;i<m;i++)
    {
        cin>>s;
        cout<<check(root,s)<<endl;
    }
    return 0; 
}