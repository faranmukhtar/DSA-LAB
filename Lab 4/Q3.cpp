#include<iostream>
using namespace std;

int main(){
    string arr[5] = {"banana" , "apple" , "cherry" , "date" ,"grape"};
    for(int i=0;i<4;i++){
        bool swap = true;
        int j=i+1;
        while(swap == true && j<5){
            swap == false;
            if(arr[i]>arr[j]){
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swap = true;
            }
            j++;
        }
    }
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" , ";
    }
}