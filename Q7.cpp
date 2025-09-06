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
                Tail->next = Head;
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
            Tail->next = Head;
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
            // while condition so ininite loop print can be avoided
            while(curr != Tail){
                cout<<curr->val<<" -> ";
                curr = curr->next;
            }
            cout<<curr->next->val<<endl;
        }
};

int main(){
    int arr[5] = {3,1,2,5,8};
    Linkedlist l1;
    for(int i=0;i<5;i++){
        l1.add_to_tail(new Node(arr[i]));
    }
    cout<<"Initial ater adding only to tail : "<<endl;
    l1.display();
    
    l1.add_to_head(new Node(23));
    cout<<"After adding to head : "<<endl;
    l1.display();

    l1.add_at_pos(new Node(11),4);
    cout<<"added 11 to position 4 : "<<endl;
    l1.display();
    l1.deleteval(2);
    cout<<"Deleted value 2 : "<<endl;
    l1.display();
    cout<<"Final List : "<<endl;
    l1.display();
}