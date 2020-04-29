struct Node
{
    Node(){
        leftOnes = 0;
        upOnes = 0;
        maxSquare = 0;
    }
    int leftOnes;
    int upOnes;
    int maxSquare;
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        vector<vector<Node>> map = 
            vector<vector<Node>>(matrix.size(), vector<Node>(matrix[0].size(), Node()));
        int maxSq = 0;
        for(int j=0; j<matrix[0].size(); j++){
            for(int i=0; i<matrix.size(); i++){
                if(matrix[i][j] == '1'){
                    map[i][j].upOnes = i > 0 ? map[i-1][j].upOnes + 1 : 1;
                }
            }
        }
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    map[i][j].leftOnes = j > 0 ? map[i][j-1].leftOnes + 1 : 1;
                    map[i][j].maxSquare = i > 0 && j > 0 ?
                                    min(map[i-1][j-1].maxSquare + 1, min(map[i][j].leftOnes, map[i][j].upOnes))
                                    : 1;
                    maxSq = max(maxSq, map[i][j].maxSquare);
                }
            }
        }
        return maxSq * maxSq;
    }
};