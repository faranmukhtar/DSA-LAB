#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand (time(0));
    const int size = 70;
    int arr[size];
    for(int i=0;i<size;i++){
        arr[i] = int(rand() % size);
    }
    int max = -999;
    cout<<"Random Input Array: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" , ";   
    }
    cout<<endl;
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    int * count = new int[max + 1]();
    for(int i=0 ; i < size ; i++){
        count[arr[i]]++;
    }
    int num =count[0];
    for(int i=1;i <= max;i++){
        num = num + count[i];
        count[i] = num;
    }
    int output[size];
    for(int i=size-1;i >= 0;i--){
        int pos = count[arr[i]];
        pos--;
        output[pos] = arr[i];
        count[arr[i]]--;
    }
    cout<<"Output Array: "<<endl;
    for(int i=0;i<size;i++){
        cout<<output[i]<<" , ";   
    }
}