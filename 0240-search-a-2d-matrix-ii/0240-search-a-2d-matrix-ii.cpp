class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int t_r = matrix.size();
        int t_c = matrix[0].size();


        int row = 0;
        int col = t_c-1;


        // Finalize only 2 of the directions -> start from the 0,m-1 . If the target is smaller go towards left side (col--) or else go to down side (row++);
        while(row < t_r && col >=0){
            if(matrix[row][col] == target ){
                return true;
            }
            else if(matrix[row][col ] > target){
                col--;
            }
            else{
                row++;
            }
        } 

        return false;
    }
};