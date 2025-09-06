#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node * next;
    Node(int v, Node * n): val(v),next(n){};
};

// 1-2-3-4-5
// 1

void ispalindrome(Node * Head){
    Node * newhead = nullptr;
    Node * curr;
    Node * Temp;
    int size =0;
    if(Head){
        curr = Head;
        while(curr){
            size++;
            curr = curr->next;
        }
        curr = Head;
        int x=0;
        while(x < (int(size/2) +1)){
            curr = curr->next;
            x++;
        }
        while(curr){
            Temp = curr->next;
            curr->next = newhead;
            newhead = curr;
            curr = Temp;
        }
        curr = newhead;
        Temp = Head;
        while(curr){
            if(curr->val != Temp->val){
                cout<<"This is not a palindrome"<<endl;
                return;
            }
            curr = curr->next;
            Temp = Temp->next;
        }
        cout<<"This is a palindrome"<<endl;
    }

}

int main(){
    Node N10(6,nullptr);
    Node N9(7,&N10);
    Node N8(1,&N9);
    Node N7(1,nullptr);
    Node N6(0,&N7);
    Node N5(0,&N6);
    Node N4(2,&N5);
    Node N3(0,&N4);
    Node N2(0,&N3);
    Node N1(1,&N2);
    ispalindrome(&N1);
}