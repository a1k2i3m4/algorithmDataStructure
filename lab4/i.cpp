#include <iostream>
using namespace std;
struct Node
{
    int data,cnt;
    Node *right,*left;
    Node(){
        data=0;
        cnt=1;
        right=left=nullptr;
    }
    
    Node(int data){
        this->data=data;
        cnt=1;
        right=left=nullptr;
    }
    
    Node(int data,Node *_left,Node *_right){
        this->data=data;
        cnt=1;
        right=_right;
        left=_left;
    }
};
struct Bst
{
  private:
  Node *root;
  Node *insert(Node *root,int data){
    if(!root){
        return new Node(data);
    }
    if(data>root->data) root->right=insert(root->right,data);
    else if(data<root->data) root->left=insert(root->left,data);
    return root;
  }
  public:
  Bst(){
    root=nullptr;
  }
  void add(int data){
    Node *newNode=insert(root,data);
    if(!root) root= newNode;
  }
  Node *search(Node *root,int  data){
   if(!root || root->data==data) return root;
   if(root->data<data) return search(root->right,data);
   return search(root->left,data);
  }
  Node *getRoot()
  {
    return root;
  }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Bst bst;
    Node *node;
    int q,x;
    cin>>q;
    string s;
    for (int i=0;i<q;i++)
    {
        cin>>s>>x;
        if(s=="insert"){
           if(!bst.getRoot()) bst.add(x); 
           else
        {
            node=bst.search(bst.getRoot(),x);
            if (!node) bst.add(x);
            else node->cnt+=1;
            
        }
        }
        else if(s=="cnt"){
           node=bst.search(bst.getRoot(),x);
           if(node) cout << node->cnt;
           else cout << 0;
           cout << "\n";
        } else {
      node =bst.search(bst.getRoot(), x);
      node->cnt = node->cnt - 1;
    }
        
        
        
    }
    

}