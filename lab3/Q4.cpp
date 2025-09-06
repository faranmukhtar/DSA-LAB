#include<iostream>
using namespace std;

struct Node{
    int val;
    Node * next;
    Node(int v, Node * n) : val(v), next(n){};
};

void display(Node *Head){
    Node * curr = Head;
    while(curr){
        cout<<curr->val<<" -> ";
        curr = curr->next;
    }
    cout<<"NULL "<<endl;
}


Node * modifylist(Node * Head){
    Node * curr = Head;
    Node * even = nullptr;
    Node * ecurr = nullptr;
    Node * odd = nullptr;
    Node * ocurr = nullptr;
    if(curr){
        while(curr){
            if(curr->val %2 == 0){
                if(even == nullptr){
                    even = curr;
                    ecurr = even;
                }
                else{
                    ecurr->next = curr;
                    ecurr = ecurr->next;
                }
            }
            else if(curr->val %2 != 0){
                if(odd == nullptr){
                    odd = curr;
                    ocurr = odd;
                }
                else{
                    ocurr->next = curr;
                    ocurr = ocurr->next;
                }
            }
            curr = curr->next;
        }
        ocurr->next = nullptr;
        cout<<"Even: "<<endl;
        display(even);
        cout<<"Odd: "<<endl;
        display(odd);
        ecurr->next = odd;
        Head = even;
        return Head;
    }
    else {
        return(nullptr);
    }
}


int main(){
    Node N10(6,nullptr);
    Node N9(7,&N10);
    Node N8(1,&N9);
    Node N7(4,&N8);
    Node N6(5,&N7);
    Node N5(10,&N6);
    Node N4(12,&N5);
    Node N3(8,&N4);
    Node N2(15,&N3);
    Node N1(17,&N2);

    cout<<"Unsorted"<<endl;
    display(&N1);

    cout<<"Sorted"<<endl;
    display(modifylist(&N1));
}
