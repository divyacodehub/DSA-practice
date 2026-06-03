#include <iostream>
using namespace std;

int main() {

    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};

    int row=3,col=3;

    int count=0;
    int total=row*col;

    int startRow=0;
    int startCol=0;
    int endRow=row-1;
    int endCol=col-1;

    while(count<total) {

        for(int i=startCol;count<total && i<=endCol;i++) {
            cout<<arr[startRow][i]<<" ";
            count++;
        }
        startRow++;

        for(int i=startRow;count<total && i<=endRow;i++) {
            cout<<arr[i][endCol]<<" ";
            count++;
        }
        endCol--;

        for(int i=endCol;count<total && i>=startCol;i--) {
            cout<<arr[endRow][i]<<" ";
            count++;
        }
        endRow--;

        for(int i=endRow;count<total && i>=startRow;i--) {
            cout<<arr[i][startCol]<<" ";
            count++;
        }
        startCol++;
    }

    return 0;
}