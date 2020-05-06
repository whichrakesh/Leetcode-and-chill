class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int l=0; l<n/2; l++){
            for(int j=0; j<n-2*l-1; j++){
                int temp = matrix[l][l + j];
                matrix[l][l+j] = matrix[n-1-l-j][l];
                matrix[n-1-l-j][l] = matrix[n-1-l][n-1-l-j];
                matrix[n-1-l][n-1-l-j] = matrix[l+j][n-1-l];
                matrix[l+j][n-1-l] = temp;
            }
        }
    }
};