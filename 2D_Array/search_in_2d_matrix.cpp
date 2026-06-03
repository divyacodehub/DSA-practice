#include <iostream>
using namespace std;

bool searchMatrix(int arr[][4],int row,int col,int target) {

    int start=0;
    int end=row*col-1;

    while(start<=end) {

        int mid=start+(end-start)/2;

        int element=arr[mid/col][mid%col];

        if(element==target)
            return true;

        if(element<target)
            start=mid+1;
        else
            end=mid-1;
    }

    return false;
}

int main() {

    int arr[3][4]={
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    int target=16;

    if(searchMatrix(arr,3,4,target))
        cout<<"Found";
    else
        cout<<"Not Found";

    return 0;
}