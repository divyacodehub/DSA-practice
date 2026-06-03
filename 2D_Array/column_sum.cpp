#include <iostream>
using namespace std;

int main() {
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};

    for(int col=0;col<3;col++) {
        int sum=0;

        for(int row=0;row<3;row++) {
            sum+=arr[row][col];
        }

        cout<<"Column "<<col<<" Sum = "<<sum<<endl;
    }

    return 0;
}