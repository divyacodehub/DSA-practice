// LeetCode 73 - Set Matrix Zeroes
// Topic: Matrix
// Approach: In-place Marker Method
// Time Complexity: O(m × n)
// Space Complexity: O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m,0);
        vector<int> col(n,0);

        //first traversal:marks rows and columns
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        //second traversal:set zeroes
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(row[i] == 1 || col[j] == 1){
                   matrix[i][j] = 0;
                }
            }
        }
    }
};



// Approach 2: Optimal (Using First Row & First Column as Markers)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
         int m = matrix.size();
        int n = matrix[0].size();

        int col0 = 1;

         //Step 1: Mark rows and columns
        for(int i = 0; i < m; i++){

             // Check if first column has a zero
            if(matrix[i][0] == 0)
                col0 = 0;

            //Start from column 1
            for(int j = 1; j < n; j++) {

                if(matrix[i][j] == 0) {

                    matrix[i][0] = 0;   // Mark the row
                    matrix[0][j] = 0;   // Mark the column
                }
            }
        }

        //Step 2: Set zeroes using the markers
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){

                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        //Step 3: Handle the first row
        if(matrix[0][0] == 0){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }

        //Step 4: Handle the first column
        if(col0 == 0){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
