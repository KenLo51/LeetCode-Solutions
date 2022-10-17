class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // create result matrix
        vector<vector<int>> resMat(matrix.size());
        for(int i=0; i<matrix.size(); i++)
            resMat[i].resize(matrix[0].size());
        
        // transform
        for(int dstY=0; dstY<matrix.size(); dstY++){
            for(int dstX=0; dstX<matrix[0].size(); dstX++){
                // transform function
                int srcX, srcY;
                srcX = dstY;
                srcY = matrix[0].size() - dstX-1;
                
                // sample data
                resMat[dstY][dstX] = matrix[srcY][srcX];
            }
        }
        
        // copy data
        for(int dstY=0; dstY<matrix.size(); dstY++){
            for(int dstX=0; dstX<matrix[0].size(); dstX++){
                matrix[dstY][dstX] = resMat[dstY][dstX];
            }
        }
    }
};