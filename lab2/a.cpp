#include <iostream>
#include <cmath>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
class linked_list
{
private:
    node *head,*tail;
public:
    linked_list(){
        head=NULL;
        tail=NULL;
    }
    void append(int N){
     node *newNode=new node;
     newNode->data=N;
     newNode->next=NULL;
     if(head==NULL){
        head=newNode;
        tail=newNode;
     }
     else
     {
        tail->next=newNode;
        tail=newNode;
     }
     
    }
    int findTheNearestNumber(int n){
        node *tmp;
        tmp = head;
        int dif=abs(n-tmp->data);
        int i=0;
        int ans=i;
        while(tmp!=NULL){
            if(dif>abs(n-tmp->data)){
                dif=abs(n-tmp->data);
                ans=i;
            }
            tmp=tmp->next;
            i++;
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    linked_list a;
    int x,b;
    while(n!=0){
        cin>>x;
        a.append(x);
        n--;
    }
    cin>>b;
    cout<<a.findTheNearestNumber(b);
    return 0;
}



