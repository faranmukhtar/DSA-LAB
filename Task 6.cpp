#include <iostream>
using namespace std;

int recursiveArraySum(int *arr[], int size[], int dim){
    if(dim < 0){
        return 0;
    }
    int sum = 0;
    for(int i=0;i<size[dim];i++){
        sum = sum + arr[dim][i];
    }
    return sum + recursiveArraySum(arr, size, dim-1);

}

int main(){
    int rows;
    cout<<"Enter number of rows: ";
    cin>>rows;
    int *col = new int[rows];
    for(int i=0;i<rows; i++){
        cout<<"Enter number of columns for row "<<i<<" : ";
        cin>>col[i];
    }
    int ** arr= new int *[rows];
    for(int i=0;i<rows;i++){
        arr[i] = new int [col[i]];
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<col[i];j++){
            cout<<"ROW "<<i<<" COL "<<j<<" : ";
            cin>>arr[i][j];
        }
    }
    cout<<"Array is : "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<col[i];j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Sum of all elements in array is: "<<recursiveArraySum(arr,col,rows);


}