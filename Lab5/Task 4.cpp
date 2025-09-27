#include<iostream>
using namespace std;

struct Node{
    int val;
    Node * next;
    Node(int v) : val(v), next(nullptr){};
};

class Linkedlist{
    private:
        Node * Head;
        Node * curr;
        Node * Tail;
        int size;

    public:
        Linkedlist(){
            Head = nullptr;
            curr = nullptr;
            Tail = nullptr;
            size = 0;
        }
        void add_to_tail(Node * ptr){
            size++;
            if(Tail != nullptr){
                Tail->next = ptr;
                Tail = ptr;
            }
            else{
                Head = ptr;
                Tail = ptr;
            }
        }
        
        void display(Node * head){
            if(!head){
                return;
            }
            display(head->next);
            cout<< head->val<<" , "; 
        }

        void search(Node * head, int val){
            if(!head){
                 cout<<"Value not found"<<endl;
                return;
            }
            if(head->val == val){
                cout<<"Value found"<<endl;
                return;
            }
            search(head->next, val);
        }
};

int main(){
    int arr[5] = {3,1,2,5,8};
    Linkedlist l1;
    Node n1(0);
    l1.add_to_tail(&n1);
    for(int i=0;i<5;i++){
        l1.add_to_tail(new Node(arr[i]));
    }
    l1.display(&n1);
    cout<<endl;
    l1.search(&n1,5);
}