#include<iostream>
using namespace std;


struct Node{
    int val;
    Node * next;
    Node (int v, Node*n):val(v),next(n) {};
};

void Extractappend(Node * head){
    Node * curr = head;
    Node * Extracted = curr->next;
    Node * nextptr = Extracted->next;
    Extracted->next = nullptr;
    Node * normal = curr;
    curr = nextptr;
    int x = 3;
    while(curr){
        if(x%2 == 0){
            Node * Temp = curr->next;
            curr->next = Extracted;
            Extracted = curr;
            curr = Temp;
        }
        else{
            normal->next = curr;
            normal = normal->next;
            curr = curr->next;
        }
        x++;
    }
    normal->next = Extracted;

    curr = head;
    while(curr){
        cout<<curr->val<<" -> ";
        curr = curr->next;
    }
    cout<<"NULL "<<endl;
}


int main(){
    Node N7(2,nullptr);
    Node N6(4,&N7);
    Node N5(6,&N6);
    Node N4(8,&N5);
    Node N3(1,&N4);
    Node N2(3,&N3);
    Node N1(5,&N2);
    Extractappend(&N1);
}