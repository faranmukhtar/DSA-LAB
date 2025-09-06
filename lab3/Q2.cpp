#include<iostream>
using namespace std;


struct Node{
    int val;
    Node * next;
    Node (int v, Node*n):val(v),next(n) {};
};

void movse(Node* Head, int num){
    Node * ptr = Head;
    if(Head != nullptr){
        while(ptr->next != nullptr){
            ptr = ptr->next;
        }
        Node * Tail = ptr;
        ptr = Head;
        int x=0;
        while(x<num && ptr){
            Node *Temp = ptr;
            ptr = ptr->next;
            Head = ptr;
            Tail->next = Temp;
            Tail = Temp;
            Tail->next = nullptr;
            x++;
        }
        
        while (ptr){
            cout<<ptr->val<<" -> ";
            ptr = ptr->next;
        }
        cout<<"Null ptr"<<endl;
        
    }
}


int main(){
    Node N7(2,nullptr);
    Node N6(4,&N7);
    Node N5(6,&N6);
    Node N4(8,&N5);
    Node N3(1,&N4);
    Node N2(3,&N3);
    Node N1(5,&N2);

    movse(&N1,4);
}