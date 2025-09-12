#include <iostream>
using namespace std;

int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        cout<<"Enter element no"<<i+1<<": ";
        cin>>arr[i];
    }
    for(int i=0;i<4;i++){
        int minindex =i;    
        for(int j=i;j<10;j++){
            if(arr[j] < arr[minindex]){ 
                minindex = j;
            }

        }
        int temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
        cout<<i+1<<")"<<arr[i]<<endl;
    }
}

