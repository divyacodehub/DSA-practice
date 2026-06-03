#include <iostream>
using namespace std;

bool searchMatrix(int arr[][4], int row, int col, int target) {

    int rowIndex = 0;
    int colIndex = col - 1;

    while(rowIndex < row && colIndex >= 0) {

        int element = arr[rowIndex][colIndex];

        if(element == target)
            return true;

        if(element < target)
            rowIndex++;
        else
            colIndex--;
    }

    return false;
}

int main() {

    int arr[5][4] = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10,13,14,17},
        {18,21,23,26}
    };

    int target = 19;

    if(searchMatrix(arr, 5, 4, target))
        cout << "Found";
    else
        cout << "Not Found";

    return 0;
}