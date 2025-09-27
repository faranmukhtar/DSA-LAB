#include <iostream>
using namespace std;

int main(){
    int arr[6] = {2022,2023,2024,2022,2023,2024};
    for (int i=0;i<6;i++){
        int minindex = i;
        for(int j=i;j<6;j++){
            if(arr[minindex] > arr[j]){
                minindex = j;
            }
        }
        int temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
    }
    for(int j=0;j<6;j++){
        cout<<arr[j]<<" , ";
    }
}