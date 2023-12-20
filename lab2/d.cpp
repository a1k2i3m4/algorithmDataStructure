#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    int cnt;
    node * next;
    node * prev;
    node(int val){
        this->val=val;
        next = nullptr;
        prev = nullptr;
        cnt = 1;
    }
};
class LinkedList{
public:
    node * head;
    node * tail;
    LinkedList(){
         head = nullptr;
        tail = nullptr;
    }
    void add(int val){
        node * newNode= new node(val);
        if(head==nullptr){
            head=tail=newNode;
        }
        else
        {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        
    }
    void print(){
          node * cur = head;
        while(cur != nullptr){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }
    vector<int> mode(){
        vector<int> ans;
        node * first= head;
         node * second = nullptr;
         int mx=0;
         while (first->next!=nullptr)
         {
            second=first->next;
            while (second!=nullptr)
            {
                if(first->val==second->val) first-> cnt++;
                second=second->next;
            }
            if(first -> cnt > mx){
                mx = first -> cnt;
            }
            first=first->next;
            
         }
         node * cur=head;
         while (cur!=nullptr)
         {
            if (cur->cnt==mx)
            {
                ans.push_back(cur->val);
            }
            cur=cur->next;
         }
          sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        return ans;
         
    }

};
int main(){
    LinkedList list;
    int n;cin>>n;
    for (int i = 0; i <n; i++)
    {
        int x;cin>>x;
        list.add(x);
    }
    for(auto i : list.mode()){
        cout<<i<<" ";
    }
}