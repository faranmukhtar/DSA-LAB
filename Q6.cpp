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
        void add_to_head(Node * ptr){
            size++;
            ptr->next = Head;
            Head = ptr;
            if(Tail == nullptr){
                Tail = Head;
            }
        }
        void add_at_pos(Node * ptr , int pos){
            if(Head != nullptr && pos < size){
                int x=0;
                curr = Head;
                while(x<pos -1){
                    curr = curr->next;
                    x++;
                }
                Node * Temp = curr->next;
                curr->next = ptr;
                ptr->next = Temp;
            }
        }
        void deleteval(int findval){
            if(Head->val != findval){
                Node *prev;
                curr = Head;
                while(curr->next){
                    prev = curr;
                    curr = curr->next;
                    if(curr->val == findval){
                        Node *Temp = curr;
                        prev->next = curr->next;
                        delete Temp;
                        size--;
                        return;
                    }
                }
            }
            else{
                Node * Temp = Head;
                Head = Head->next;
                delete Temp;
                size --;
                return;
            }
            cout<<"Value "<<findval<< " is not in array"<<endl;
        }
        void display(){
            curr = Head;
            while(curr){
                cout<<curr->val<<" -> ";
                curr = curr->next;
            }
            cout<<"NULL "<<endl;
        }
};

int main(){
    int arr[5] = {3,1,2,5,8};
    Linkedlist l1;
    for(int i=0;i<5;i++){
        l1.add_to_tail(new Node(arr[i]));
    }
    l1.display();
    l1.deleteval(1);
    l1.deleteval(2);
    l1.deleteval(52);
    l1.display();
}