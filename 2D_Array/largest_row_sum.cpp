#include <iostream>
using namespace std;

int main() {

    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};

    int maxi=-1;
    int rowIndex=-1;

    for(int row=0;row<3;row++) {

        int sum=0;

        for(int col=0;col<3;col++) {
            sum+=arr[row][col];
        }

        if(sum>maxi) {
            maxi=sum;
            rowIndex=row;
        }
    }

    cout<<"Largest Row = "<<rowIndex<<endl;
    cout<<"Sum = "<<maxi;

    return 0;
}