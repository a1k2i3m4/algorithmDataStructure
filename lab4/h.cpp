#include <bits/stdc++.h>
using namespace std;
int s,pre;
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
    Node *insert(Node *root,int val){
        if(!root){
            return new Node(val);
        }
        if(val>root->data) root->right=insert(root->right,val);
        else if (val<root->data) root->left=insert(root->left,val);
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
        if(!root) root =newNode;
    }
    Node  *BstToGst(Node *root){
    if(root->right) BstToGst(root->right);
    pre=pre+root->data;
    root->data=pre; 
    if(root->left) BstToGst(root->left);
    return root;
    }
    void print(Node *root){
        if(root->right) print(root->right);
        cout<<root->data<<" ";
        if(root->left) print(root->left);
    }

};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Bst bst;
    cin>>s;
    for (int i = 0; i < s; i++)
    {
        int x;
        cin>>x;
        bst.add(x);
    }
    bst.BstToGst(bst.getRoot());
    bst.print(bst.getRoot());
}
