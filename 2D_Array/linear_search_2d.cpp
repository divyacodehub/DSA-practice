#include <iostream>
using namespace std;

bool search(int arr[][3],int row,int col,int key) {

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(arr[i][j]==key)
                return true;
        }
    }

    return false;
}

int main() {

    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int key=5;

    if(search(arr,3,3,key))
        cout<<"Found";
    else
        cout<<"Not Found";

    return 0;
}