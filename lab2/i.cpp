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
    string data;
    node *nxt = NULL;
    node *prev = NULL;
    node() {
        data = "";
    }
    node(string _data,node * _nxt,node *_prev){
        data = _data;
        nxt = _nxt;
        prev = _prev;
    }
};
struct linked_list{
    node *head,*tail;
    int size;
    linked_list(){
        head = new node("",NULL,NULL);
        tail = new node("",NULL,NULL);
        size = 0;
    }
    void output(){
        node *cur = head;
        while(cur != NULL){
            cout << cur->data << " ";
            cur = cur->nxt; 
        }
        cout << "\n";
    }
    void clear(){
        head = new node("",NULL,NULL);
        tail = new node("",NULL,NULL);  
        size = 0;
    }
    void insert_begin(string data){
        if(size == 0){
            head->data = data;
            tail = head;
        }else{
        node *nd = new node(data,head,NULL);
        head = nd;
        }
        cout << "ok\n";
        size++;
    }
    void insert_end(string data){
        if(size == 0){
            head->data = data;
            tail = head;
        }else{
            node *new_node = new node(data,NULL,tail);
            tail->nxt = new_node;
            tail = new_node; 
        }
        size++;
        cout << "ok\n";
    }
    void erase_front(){
        if(size != 0){
            cout << head->data << "\n";
            if(size!=1)
                head = head->nxt;
            else{
                clear();
                return;
            }
            size--;
        }else 
            cout << "error\n";
    }
    void erase_back(){
        if(size != 0){
            cout << tail->data << "\n";
            if(size != 1){
                tail = tail->prev;
                tail->nxt = NULL;
            }else{
                clear();
                return;
            }
            size--;
        }else
            cout << "error\n";
    }
};
linked_list l;
int main(){
    string s;
    while(true){
        string com;cin >> com;
        if(com == "add_front"){
            cin >> s;
            l.insert_begin(s);
        }else if(com == "add_back"){
            cin >> s;
            l.insert_end(s);
        }else if(com == "erase_front"){
            l.erase_front();
        }else if(com == "erase_back"){
            l.erase_back();
        }else if(com == "front"){
            if(l.size != 0)
                cout << l.head->data << "\n";
            else   
                cout << "error\n";
        }
        else if(com == "back")
            if(l.size != 0)
                cout << l.tail->data << "\n";
            else 
                cout << "error\n";
        else if(com == "clear"){
            l.clear();
            cout << "ok\n";
        }
        else if(com == "exit"){
            cout << "goodbye\n";
            break;
        }
        if(com == "3")
            l.output();
    }
}