#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fori(n) for(i = 0;i < n;i++)
#define fori1(n) for(i = 1;i <= n;i++)
#define forj(n) for(j = 0;j < n;j++)
#define forj1(n) for(j = 1;j <= n;j++)
#define mp make_pair
#define pb push_back
#define MAX 2501
ll i,j;
struct node{
    int data;
    node *nxt = NULL;
    node() {
        data = 0;
    }
    node(int _data,node * _nxt){
        data = _data;
        nxt = _nxt;
    }
};
struct linked_list{
    node *head,*tail;
    linked_list(){
        head = new node(0,NULL);
        tail = new node(0,NULL);
    }
    void output(){
        node *cur = head;
        while(cur != NULL){
            cout << cur->data << " ";
            cur = cur->nxt; 
        }
    }
    void insert_begin(int data){
        node *nd = new node(data,head);
        head = nd;
    }
    void insert_end(int data){
        if(head->data == 0){
            head->data = data;
            tail = head;
        }else{
            node *new_node = new node(data,NULL);
            tail->nxt = new_node;
            tail = new_node; 
        }
    }
    node* get(int ind){
        node *cur = head;
        fori(ind)
            cur = cur->nxt;
        return cur;
    }
    void insert(int data,int ind){ 
        if(ind == 0){
            insert_begin(data);
            return;
        }
        node *nd = get(ind-1);
        node *new_node = new node(data,nd->nxt);
        nd->nxt = new_node;
    }

};
int main(){
    linked_list l;
    int n;cin >> n;
    fori(n){
        cin >> j;
        l.insert_end(j);
    }
    cin >> i >> j;
    l.insert(i,j);
    l.output();
    return 0;
}