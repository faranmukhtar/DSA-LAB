#include<iostream>
using namespace std;

bool Duplicates(int arr[]){
    for(int i=0;i<5;i++){
        int key = arr[i];
        for(int j=i+1;j<5;j++){
            if(arr[i] == arr[j]){
                cout<<"The array has duplicate values"<<endl;
                return true;
            }
        }
    }
    cout<<"The array has no duplicate values"<<endl;
    return false;
}
int main(){
    int arr[5];
    for(int i=0;i<5;i++){
        cout<<"Enter element number "<<i+1<<": ";
        cin>>arr[i];
   }
    Duplicates(arr);
}