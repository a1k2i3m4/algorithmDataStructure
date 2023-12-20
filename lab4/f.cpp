#include <iostream>
using namespace std;
int n,p,sum;
struct node
{
    int data;
    node *left;
    node *right;
    node(){
     data=0;
     left=nullptr;
     right=nullptr;
    }
    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
    node(node *_left,node *_right,int val){
        data=val;
        right=_right;
        left=_left;
    }
};
node *insert(node *tree,int x){
    if(!tree){ tree=new node(x);return tree;}
    if(x<=tree->data) tree->left=insert(tree->left,x);
    else tree->right=insert(tree->right,x);
    return tree;
}
void check(node *tree) {
  if(!tree) return;
  if(tree->right && tree->left) ++sum;
  check(tree->left);
  check(tree->right);
}
node *root;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> p;
  root = insert(root, p);
  for(int _ = 1; _ < n; _++) {
    cin >> p;
    insert(root, p);
  }
  check(root);
  cout << sum;
  return 0;
}