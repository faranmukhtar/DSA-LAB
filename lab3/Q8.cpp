#include<iostream>
using namespace std;

struct Node{
    int val;
    Node * next;
    Node * prev;
    Node(int v) : val(v), next(nullptr), prev(nullptr){};
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
                ptr->prev = Tail;
                Tail->next = ptr;
                Tail = ptr;
            }
            else{
                Head = ptr;
                Tail = ptr;
            }
        }
        void add_to_head(Node * ptr){
            size++;
            Head->prev = ptr;
            ptr->next = Head;
            Head = ptr;
            if(Tail == nullptr){
                Tail = Head;
            }
        }
       
        void display(){
            curr = Head;
            while(curr){
                cout<<curr->val<<" <--> ";
                curr = curr->next;
            }
            cout<<"NULL "<<endl;
        }

    void concatenate(Node * l1 , Node *l2){
        Node * curr;
        if(l1 && l2){
            curr = l1;
            while(curr->next){
                curr = curr->next;
            }
            curr->next = l2;
            l2->prev = curr;
            Head = l1;
        }
        else{
            cout<< "Insuficient number of linked lists"<<endl;
            
        }
    }
};



int main(){
    Node H1 (12);
    Node H2 (12);
    int arr[5] = {3,1,2,5,8};
    Linkedlist l1;
    for(int i=0;i<5;i++){
        l1.add_to_tail(new Node(arr[i]));
    }

    int arrs[8] = {23,34,54,32,12,32,43,67};
    Linkedlist l2;
    for(int i=0;i<8;i++){
        l2.add_to_tail(new Node(arrs[i]));
    }
    cout<<"Linked list l1: "<<endl;
    l1.display();
    cout<<"Linked list l2: "<<endl;
    l2.display();
    cout<<"l1 + l2 combined (12 added to heads of both lists): "<<endl;
    l1.add_to_head(&H1);
    l2.add_to_head(&H2);

    Linkedlist C1;
    C1.concatenate(&H1,&H2);
    C1.display();
    
    
}